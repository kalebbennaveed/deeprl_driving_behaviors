#!/usr/bin/env python
"""
@file    route2poly.py
@author  Jakob Erdmann
@author  Michael Behrisch
@date    2012-11-15
@version $Id: route2poly.py 25253 2017-07-19 06:30:42Z behrisch $

From a sumo network and a route file, this script generates a polygon (polyline) for every route
which can be loaded with sumo-gui for visualization

SUMO, Simulation of Urban MObility; see http://sumo.dlr.de/
Copyright (C) 2012-2017 DLR (http://www.dlr.de/) and contributors

This file is part of SUMO.
SUMO is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3 of the License, or
(at your option) any later version.
"""
from __future__ import absolute_import
import sys
import os
import itertools
import random
from optparse import OptionParser
sys.path.append(os.path.join(os.path.dirname(__file__), '..'))
from sumolib.output import parse
from sumolib.net import readNet
from sumolib.miscutils import Colorgen


def parse_args(args):
    USAGE = "Usage: " + sys.argv[0] + " <netfile> <routefile> [options]"
    optParser = OptionParser()
    optParser.add_option("-o", "--outfile", help="name of output file")
    optParser.add_option("-u", "--hue", default="random",
                         help="hue for polygons (float from [0,1] or 'random')")
    optParser.add_option("-s", "--saturation", default=1,
                         help="saturation for polygons (float from [0,1] or 'random')")
    optParser.add_option("-b", "--brightness", default=1,
                         help="brightness for polygons (float from [0,1] or 'random')")
    optParser.add_option(
        "-l", "--layer", default=100, help="layer for generated polygons")
    optParser.add_option("--geo", action="store_true",
                         default=False, help="write polgyons with geo-coordinates")
    optParser.add_option("--blur", type="float",
                         default=0, help="maximum random disturbance to route geometry")
    optParser.add_option("--standalone", action="store_true",
                         default=False, help="Parse stand-alone routes that are not define as child-element of a vehicle")
    options, args = optParser.parse_args(args=args)
    if len(args) < 2:
        sys.exit(USAGE)
    try:
        options.net = args[0]
        options.routefiles = args[1:]
        options.colorgen = Colorgen(
            (options.hue, options.saturation, options.brightness))
    except:
        sys.exit(USAGE)
    if options.outfile is None:
        options.outfile = options.routefiles[0] + ".poly.xml"
    return options


def randomize_pos(pos, blur):
    return tuple([val + random.uniform(-blur, blur) for val in pos])


def generate_poly(net, id, color, layer, geo, edges, blur, outf, type="route"):
    shape = list(itertools.chain(*list(net.getEdge(e).getLane(0).getShape()
                                       for e in edges)))
    if blur > 0:
        shape = [randomize_pos(pos, blur) for pos in shape]

    geoFlag = ""
    if geo:
        shape = [net.convertXY2LonLat(*pos) for pos in shape]
        geoFlag = ' geo="true"'
    shapeString = ' '.join('%s,%s' % (x, y) for x, y in shape)
    outf.write('<poly id="%s" color="%s" layer="%s" type="%s" shape="%s"%s/>\n' % (
        id, color, layer, type, shapeString, geoFlag))


def main(args):
    options = parse_args(args)
    net = readNet(options.net)
    known_ids = set()

    def unique_id(cand, index=0):
        cand2 = cand
        if index > 0:
            cand2 = "%s#%s" % (cand, index)
        if cand2 in known_ids:
            return unique_id(cand, index + 1)
        else:
            known_ids.add(cand2)
            return cand2

    with open(options.outfile, 'w') as outf:
        outf.write('<polygons>\n')
        for routefile in options.routefiles:
            print("parsing %s" % routefile)
            if options.standalone:
                for route in parse(routefile, 'route'):
                    # print("found veh", vehicle.id)
                    generate_poly(net, unique_id(route.id), options.colorgen(),
                                  options.layer, options.geo,
                                  route.edges.split(), options.blur, outf)
            else:
                for vehicle in parse(routefile, 'vehicle'):
                    # print("found veh", vehicle.id)
                    generate_poly(net, unique_id(vehicle.id), options.colorgen(),
                                  options.layer, options.geo,
                                  vehicle.route[0].edges.split(), options.blur, outf)
        outf.write('</polygons>\n')

if __name__ == "__main__":
    main(sys.argv[1:])

#!/usr/bin/env python
"""
@file    netmatch.py
@author  Marek Heinrich
@author  Michael Behrisch
@date    2013-10-22
@version $Id: netmatch.py 25254 2017-07-19 06:34:24Z behrisch $

This script tries to match the edges of two sumo networks.

SUMO, Simulation of Urban MObility; see http://sumo.dlr.de/
Copyright (C) 2009-2017 DLR (http://www.dlr.de/) and contributors

This file is part of SUMO.
SUMO is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3 of the License, or
(at your option) any later version.
"""

from __future__ import print_function
from __future__ import absolute_import
import os
import sys
from optparse import OptionParser
sys.path.append(os.path.join(os.path.dirname(__file__), '..'))

import sumolib  # noqa
from sumolib.geomhelper import distance

optParser = OptionParser()
optParser.add_option("-v", "--verbose", action="store_true", dest="verbose",
                     default=False, help="tell me what you are doing")
optParser.add_option("-1", "--net1", dest="net1",
                     help="SUMO network to use (mandatory)", metavar="FILE")
optParser.add_option("-2", "--net2", dest="net2",
                     help="SUMO network to use (mandatory)", metavar="FILE")
# optParser.add_option("-t", "--trips", dest="trips",
#                    help="Trips to remap (mandatory)", metavar="FILE")
# optParser.add_option("-a", "--nodes1", dest="nodes1",
#                     help="The first matching nodes", metavar="NODELIST")
# optParser.add_option("-b", "--nodes2", dest="nodes2",
#                     help="The second matching nodes", metavar="NODELIST")
# optParser.add_option("-d", "--dump", dest="dump",
#                     help="dump file to use", metavar="FILE")
optParser.add_option("-d", "--delta", default="1",
                     type="float", help="maximum distance between end points")
optParser.add_option("-o", "--output", dest="output",
                     help="(base) name for the output", metavar="FILE")
optParser.add_option("--edges1", help="matched edges in net 1", metavar="FILE")
optParser.add_option("--edges2", help="matched edges in net 2", metavar="FILE")
(options, args) = optParser.parse_args()


if not options.output or not options.net1 or not options.net2:
    optParser.exit("missing input or output")

# read networks
if options.verbose:
    print("Reading net#1...")
net1 = sumolib.net.readNet(options.net1)
net1.move(-net1.getLocationOffset()[0], -net1.getLocationOffset()[1])

if options.verbose:
    print("Reading net#2...")
net2 = sumolib.net.readNet(options.net2)
net2.move(-net2.getLocationOffset()[0], -net2.getLocationOffset()[1])


f = open(options.output, "w")

matchedEdges1 = set()
matchedEdges2 = set()

for e1 in net1.getEdges():
    from1 = e1.getFromNode().getCoord()
    to1 = e1.getToNode().getCoord()
    for e2, d in net2.getNeighboringEdges(from1[0], from1[1], options.delta):
        if distance(from1, e2.getFromNode().getCoord()) < options.delta \
                and distance(to1, e2.getToNode().getCoord()) < options.delta \
                and e2 not in matchedEdges2:
            print(e1.getID(), e2.getID(), file=f)
            matchedEdges1.add(e1)
            matchedEdges2.add(e2)
            break

f.close()

print("matched", len(matchedEdges1), "out of",
      len(net1.getEdges()), "in", options.net1)
print("matched", len(matchedEdges2), "out of",
      len(net2.getEdges()), "in", options.net2)

if options.edges1:
    print("\n".join(["edge:%s" % e.getID()
                     for e in matchedEdges1]), file=open(options.edges1, "w"))
if options.edges2:
    print("\n".join(["edge:%s" % e.getID()
                     for e in matchedEdges2]), file=open(options.edges2, "w"))

# adaptor = netshiftadaptor.NetShiftAdaptor(net1, net2, options.nodes1.split(","), options.nodes2.split(","))
# adaptor.reproject(options.verbose)

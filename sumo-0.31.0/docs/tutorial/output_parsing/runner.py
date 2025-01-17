#!/usr/bin/env python
"""
@file    runner.py
@author  Michael Behrisch
@date    2012-12-09
@version $Id: runner.py 24864 2017-06-23 07:47:53Z behrisch $

This script is a test runner for the output_parsing tutorial.

SUMO, Simulation of Urban MObility; see http://sumo.dlr.de/
Copyright (C) 2008-2017 DLR (http://www.dlr.de/) and contributors

This file is part of SUMO.
SUMO is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3 of the License, or
(at your option) any later version.
"""
from __future__ import absolute_import
from __future__ import print_function


import os
import subprocess
import sys
import time
import shutil
sys.path.append(
    os.path.join(os.path.dirname(__file__), '..', '..', '..', '..', "tools"))
sys.path.append(os.path.join(os.environ.get("SUMO_HOME", os.path.join(
    os.path.dirname(__file__), "..", "..", "..")), "tools"))
from sumolib import checkBinary  # noqa


netconvertBinary = checkBinary('netconvert')
sumoBinary = checkBinary('sumo')
# build/check network
retcode = subprocess.call(
    [netconvertBinary, "-c", "data/circular.netccfg"], stdout=sys.stdout, stderr=sys.stderr)
try:
    shutil.copy("data/circular.net.xml", "net.net.xml")
except:
    print("Missing 'circular.net.xml'")
print(">> Netbuilding closed with status %s" % retcode)
sys.stdout.flush()
# run simulation
retcode = subprocess.call(
    [sumoBinary, "-c", "data/output_file.sumocfg", "--no-step-log"], stdout=sys.stdout, stderr=sys.stderr)
print(">> Simulation closed with status %s" % retcode)
sys.stdout.flush()

/****************************************************************************/
/// @file    MSLogicJunction.cpp
/// @author  Christian Roessel
/// @author  Daniel Krajzewicz
/// @author  Michael Behrisch
/// @author  Jakob Erdmann
/// @date    Wed, 12 Dez 2001
/// @version $Id: MSLogicJunction.cpp 25918 2017-09-07 19:38:16Z behrisch $
///
// with one ore more logics.
/****************************************************************************/
// SUMO, Simulation of Urban MObility; see http://sumo.dlr.de/
// Copyright (C) 2001-2017 DLR (http://www.dlr.de/) and contributors
/****************************************************************************/
//
//   This file is part of SUMO.
//   SUMO is free software: you can redistribute it and/or modify
//   it under the terms of the GNU General Public License as published by
//   the Free Software Foundation, either version 3 of the License, or
//   (at your option) any later version.
//
/****************************************************************************/

// ===========================================================================
// included modules
// ===========================================================================
#ifdef _MSC_VER
#include <windows_config.h>
#else
#include <config.h>
#endif

#include "MSLinkCont.h"
#include "MSLogicJunction.h"
#include "MSLane.h"


// ===========================================================================
// member method definitions
// ===========================================================================
/* -------------------------------------------------------------------------
 * methods from MSLogicJunction
 * ----------------------------------------------------------------------- */
MSLogicJunction::MSLogicJunction(const std::string& id,
                                 SumoXMLNodeType type,
                                 const Position& position,
                                 const PositionVector& shape,
                                 std::vector<MSLane*> incoming
                                 , std::vector<MSLane*> internal
                                ):
    MSJunction(id, type, position, shape),
    myIncomingLanes(incoming),
    myInternalLanes(internal) {
}


MSLogicJunction::~MSLogicJunction() {}


void
MSLogicJunction::postloadInit() {
    /*
    if(getID()=="1565") {
        int bla = 0;
    }
    // inform links where they have to report approaching vehicles to
    int requestPos = 0;
    std::vector<MSLane*>::iterator i;
    // going through the incoming lanes...
    for(i=myIncomingLanes.begin(); i!=myIncomingLanes.end(); ++i) {
        const MSLinkCont &links = (*i)->getLinkCont();
        // ... set information for every link
        for(MSLinkCont::const_iterator j=links.begin(); j!=links.end(); j++) {
            (*j)->setRequestInformation(&myRequest, requestPos,
                &myRespond, requestPos/, clearInfo/);
            requestPos++;
        }
    }
    // set information for the internal lanes
    requestPos = 0;
    for(i=myInternalLanes.begin(); i!=myInternalLanes.end(); ++i) {
        // ... set information about participation
        static_cast<MSInternalLane*>(*i)->setParentJunctionInformation(
            &myInnerState, requestPos++);
    }
    */
}

const std::vector<MSLane*>
MSLogicJunction::getInternalLanes() const {
    // Besides the lanes im myInternal lanes, which are only the last parts of the connections,
    // this collects all lanes on the junction
    std::vector<MSLane*> allInternalLanes;
    for (std::vector<MSLane*>::const_iterator i = myInternalLanes.begin(); i != myInternalLanes.end(); ++i) {
        MSLane* l = *i;
        while (l != 0) {
            allInternalLanes.push_back(l);
            const std::vector<MSLane::IncomingLaneInfo> incoming = l->getIncomingLanes();
            if (incoming.size() == 0) {
                break;
            }
            assert(l->getIncomingLanes().size() == 1);
            l = l->getIncomingLanes()[0].lane;
            if (!l->isInternal()) {
                break;
            }
        }
    }
    return allInternalLanes;
}



/****************************************************************************/


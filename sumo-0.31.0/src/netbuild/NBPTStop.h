/****************************************************************************/
/// @file    NBPTStop.h
/// @author  Gregor Laemmel
/// @date    Tue, 20 Mar 2017
/// @version $Id: NBPTStop.h 25918 2017-09-07 19:38:16Z behrisch $
///
// The representation of a single pt stop
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
#ifndef SUMO_NBPTSTOP_H
#define SUMO_NBPTSTOP_H

// ===========================================================================
// included modules
// ===========================================================================
#ifdef _MSC_VER
#include <windows_config.h>
#else
#include <config.h>
#endif

#include <string>
#include <utils/geom/Position.h>
#include "utils/common/SUMOVehicleClass.h"
#include "NBPTPlatform.h"


// ===========================================================================
// class declarations
// ===========================================================================
class OutputDevice;


// ===========================================================================
// class definitions
// ===========================================================================
/**
* @class NBPTStop
* @brief The representation of a single pt stop
*/
class NBPTStop {

public:
    /**@brief Constructor
    * @param[in] id The id of the pt stop
    * @param[in] position The position of the pt stop
    * @param[in] edgeId The edge id of the pt stop
    * @param[in] length The length of the pt stop
    */
    NBPTStop(std::string ptStopId, Position position, std::string edgeId, std::string origEdgeId, double length, std::string name, SVCPermissions svcPermissions);
    std::string getID() const;

    const std::string getEdgeId();
    const std::string getOrigEdgeId();
    const std::string getName();
    const Position& getPosition();
    SVCPermissions getPermissions();
    void computExtent(double center, double d);
    void setLaneID(const std::string& laneId);
    void write(OutputDevice& device);
    void reshiftPostion(const double offsetX, const double offsetY);

    std::vector<NBPTPlatform>& getPlatformCands();
    bool getIsMultipleStopPositions();
    void setIsMultipleStopPositions(bool multipleStopPositions);
    double getLength();
    void setEdgeId(std::string edgeId);
    void registerAdditionalEdge(std::string wayId, std::string edgeId);
    void addPlatformCand(NBPTPlatform platform);
private:
    const std::string myPTStopId;
    Position myPosition;
    std::string myEdgeId;
    std::map<std::string, std::string> myAdditionalEdgeCandidates;
public:
    const std::map<std::string, std::string>& getMyAdditionalEdgeCandidates() const;
private:
    std::string myOrigEdgeId;
public:
    void setMyOrigEdgeId(const std::string& myOrigEdgeId);
private:
    double myPTStopLength;
public:
    void setMyPTStopLength(double myPTStopLength);
private:
    const std::string myName;
    std::string myLaneId;
    const SVCPermissions myPermissions;

    double myStartPos;
    double myEndPos;


private:
    /// @brief Invalidated assignment operator.
    NBPTStop& operator=(const NBPTStop&);


    std::vector<NBPTPlatform> myPlatformCands;
    bool myIsMultipleStopPositions;
};

#endif //SUMO_NBPTSTOP_H

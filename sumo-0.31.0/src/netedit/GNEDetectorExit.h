/****************************************************************************/
/// @file    GNEDetectorExit.h
/// @author  Pablo Alvarez Lopez
/// @date    Nov 2015
/// @version $Id: GNEDetectorExit.h 25918 2017-09-07 19:38:16Z behrisch $
///
//
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
#ifndef GNEDetectorExit_h
#define GNEDetectorExit_h


// ===========================================================================
// included modules
// ===========================================================================
#ifdef _MSC_VER
#include <windows_config.h>
#else
#include <config.h>
#endif

#include "GNEDetector.h"

// ===========================================================================
// class declarations
// ===========================================================================
class GNEDetectorE3;

// ===========================================================================
// class definitions
// ===========================================================================
/**
 * @class GNEDetectorExit
 * class for detector of type exit
 */
class GNEDetectorExit  : public GNEDetector {
public:
    /**@brief Constructor
     * @param[in] viewNet pointer to GNEViewNet of this additional element belongs
     * @param[in] parent pointer to GNEDetectorE3 of this Exit belongs
     * @param[in] lane Lane of this StoppingPlace belongs
     * @param[in] pos position of the detector on the lane
     * @param[in] friendlyPos enable or disable friendly positions
     */
    GNEDetectorExit(GNEViewNet* viewNet, GNEDetectorE3* parent, GNELane* lane, double pos, bool friendlyPos);

    /// @brief destructor
    ~GNEDetectorExit();

    /**@brief writte additional element into a xml file
     * @param[in] device device in which write parameters of additional element
     * @param[in] volatileOptionsEnabled flag to indicate that additionals are being saved with volatile options enabled
     */
    void writeAdditional(OutputDevice& device, bool volatileOptionsEnabled) const;

    /// @brief check if Position of detector is fixed
    bool isDetectorPositionFixed() const;

    /// @brief get E3 Detector parent
    GNEDetectorE3* getE3Parent() const;

    /// @brief update pre-computed geometry information called by E3 parent
    void updateGeometryByParent();

    /// @name Functions related with geometry of element
    /// @{
    /// @brief update pre-computed geometry information
    void updateGeometry();
    /// @}

    /// @name inherited from GUIGlObject
    /// @{
    /**@brief Draws the object
     * @param[in] s The settings for the current view (may influence drawing)
     * @see GUIGlObject::drawGL
     */
    void drawGL(const GUIVisualizationSettings& s) const;
    /// @}

    /// @name inherited from GNEAttributeCarrier
    /// @{
    /* @brief method for getting the Attribute of an XML key
     * @param[in] key The attribute key
     * @return string with the value associated to key
     */
    std::string getAttribute(SumoXMLAttr key) const;

    /* @brief method for setting the attribute and letting the object perform additional changes
     * @param[in] key The attribute key
     * @param[in] value The new value
     * @param[in] undoList The undoList on which to register changes
     */
    void setAttribute(SumoXMLAttr key, const std::string& value, GNEUndoList* undoList);

    /* @brief method for checking if the key and their correspond attribute are valids
     * @param[in] key The attribute key
     * @param[in] value The value asociated to key key
     * @return true if the value is valid, false in other case
     */
    bool isValid(SumoXMLAttr key, const std::string& value);
    /// @}

private:
    /// @brief pointer to E3 parent
    GNEDetectorE3* myE3Parent;

    /// @brief set attribute after validation
    void setAttribute(SumoXMLAttr key, const std::string& value);

    /// @brief Invalidated copy constructor.
    GNEDetectorExit(const GNEDetectorExit&);

    /// @brief Invalidated assignment operator.
    GNEDetectorExit& operator=(const GNEDetectorExit&) = delete;

    /// @brief Invalidated get filename
    const std::string& getFilename() const = delete;

    /// @brief Invalidated set frequency
    int getFrequency() const = delete;

    /// @brief Invalidated set filename
    void setFrequency(double freq) = delete;

    /// @brief Invalidated
    void setFilename(const std::string& filename) = delete;
};


#endif
/****************************************************************************/

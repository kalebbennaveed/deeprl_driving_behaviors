/****************************************************************************/
/// @file    MSSOTLPolicy5DFamilyStimulus.h
/// @author  Riccardo Belletti
/// @author  Simone Bacchilega
/// @date    2014-09-30
/// @version $Id: MSSOTLPolicy5DFamilyStimulus.h 25277 2017-07-20 11:15:41Z behrisch $
///
// The class the low-level policy stimulus
/****************************************************************************/
// SUMO, Simulation of Urban MObility; see http://sumo.dlr.de/
// Copyright (C) 2013-2017 DLR (http://www.dlr.de/) and contributors
/****************************************************************************/
//
//   This file is part of SUMO.
//   SUMO is free software: you can redistribute it and/or modify
//   it under the terms of the GNU General Public License as published by
//   the Free Software Foundation, either version 3 of the License, or
//   (at your option) any later version.
//
/****************************************************************************/

#ifndef MSSOTLPOLICY5DFAMILYSTIMULUS_H_
#define MSSOTLPOLICY5DFAMILYSTIMULUS_H_

// ===========================================================================
// included modules
// ===========================================================================
#ifdef _MSC_VER
#include <windows_config.h>
#else
#include <config.h>
#endif

//#define SWARM_DEBUG
#include <utils/common/SwarmDebug.h>
#include <utils/common/MsgHandler.h>
#include <sstream>
#include <cmath>
#include <stdlib.h>
#include <string.h>
#include "MSSOTLPolicy5DStimulus.h"

/**
 * \class MSSOTLPolicy5DListStimulus
 * \brief This class determines the stimulus of a MSSOTLPolicy when
 * used in combination with a high level policy.\n
 * The stimulus function is calculated as follows:\n
 * stimulus = cox * exp(-pow(pheroIn - offsetIn, 2)/divisor -pow(pheroOut - offsetOut, 2)/divisor)
 */
class MSSOTLPolicy5DFamilyStimulus: public MSSOTLPolicyDesirability {

private:

    /*double stimCoxDVal,
    stimOffsetInDVal, stimOffsetOutDVal, stimOffsetDispersionInDVal, stimOffsetDispersionOutDVal,
    stimDivInDVal, stimDivOutDVal, stimDivDispersionInDVal, stimDivDispersionOutDVal,
    stimCoxExpInDVal, stimCoxExpOutDVal, stimCoxExpDispersionInDVal, stimCoxExpDispersionOutDVal;*/

    std::map<std::string, std::string> default_values;
    std::vector<std::string> params_names;
    std::vector<MSSOTLPolicy5DStimulus*> family;

    //std::vector<std::string> inline StringSplit(const std::string &source, const char *delimiter = " ", bool keepEmpty = false);

public:

    MSSOTLPolicy5DFamilyStimulus(std::string keyPrefix, const std::map<std::string, std::string>& parameters);

    std::string getMessage();

    std::vector<MSSOTLPolicy5DStimulus*> getFamilies() {
        return family;
    }

    /*
     *	@brief Computes stimulus function
     *  stimulus = cox * exp(-pow(pheroIn - offsetIn, 2)/divisor -pow(pheroOut - offsetOut, 2)/divisor);
     */
    virtual double computeDesirability(double vehInMeasure,
                                       double vehOutMeasure);

    virtual double computeDesirability(double vehInMeasure, double vehOutMeasure, double vehInDispersionMeasure, double vehOutDispersionMeasure);
};

#endif /* MSSOTLPOLICY5DFAMILYSTIMULUS_H_ */

/****************************************************************************/
/// @file    CEP.h
/// @author  Martin Dippold
/// @author  Michael Behrisch
/// @date    July 2016
/// @version $Id: CEP.h 25997 2017-09-13 04:09:06Z behrisch $
///
//
/****************************************************************************/
// SUMO, Simulation of Urban MObility; see http://sumo.dlr.de/
// Copyright (C) 2016-2017 DLR (http://www.dlr.de/) and contributors
// PHEMlight module
// Copyright 2016 Technische Universitaet Graz, https://www.tugraz.at/
/****************************************************************************/
//
//   This file is part of SUMO.
//   SUMO is free software: you can redistribute it and/or modify
//   it under the terms of the GNU General Public License as published by
//   the Free Software Foundation, either version 3 of the License, or
//   (at your option) any later version.
//
/****************************************************************************/


#ifndef PHEMlightCEP
#define PHEMlightCEP

#define _USE_MATH_DEFINES
#include <string>
#include <map>
#include <vector>
#include <cmath>
#include <utility>

//C# TO C++ CONVERTER NOTE: Forward class declarations:
namespace PHEMlightdll { class Helpers; }


namespace PHEMlightdll {
    class CEP {
        //--------------------------------------------------------------------------------------------------
        // Constructors
        //--------------------------------------------------------------------------------------------------      

    public:
        CEP(bool heavyVehicle, double vehicleMass, double vehicleLoading, double vehicleMassRot, double crossArea, double cWValue, double f0, double f1, double f2, double f3, double f4, double axleRatio, std::vector<double>& transmissionGearRatios, double auxPower, double ratedPower, double engineIdlingSpeed, double engineRatedSpeed, double effictiveWheelDiameter, double pNormV0, double pNormP0, double pNormV1, double pNormP1, const std::string& vehicelFuelType, std::vector<std::vector<double> >& matrixFC, std::vector<std::string>& headerLinePollutants, std::vector<std::vector<double> >& matrixPollutants, std::vector<std::vector<double> >& matrixSpeedRotational, std::vector<std::vector<double> >& normedDragTable, double idlingFC, std::vector<double>& idlingPollutants);


        //--------------------------------------------------------------------------------------------------
        // Members 
        //--------------------------------------------------------------------------------------------------

    private:
        bool _heavyVehicle;
    public:
        const bool&  getHeavyVehicle() const;

    private:
        std::string _fuelType;
    public:
        const std::string&  getFuelType() const;

    public:
        enum NormalizingType {
            NormalizingType_RatedPower,
            NormalizingType_DrivingPower
        };
    private:
        NormalizingType _normalizingType;
    public:
        const NormalizingType&  getNormalizingTypeX() const;

    private:
        double _ratedPower;
    public:
        const double&  getRatedPower() const;
        void setRatedPower(const double&  value);

    private:
        double _normalizingPower;
    public:
        const double&  getNormalizingPower() const;

    private:
        double _drivingPower;
    public:
        const double&  getDrivingPower() const;
        void setDrivingPower(const double&  value);



    protected:
        double _massVehicle;
        double _vehicleLoading;
        double _vehicleMassRot;
        double _crossSectionalArea;
        double _cWValue;
        double _resistanceF0;
        double _resistanceF1;
        double _resistanceF2;
        double _resistanceF3;
        double _resistanceF4;
        double _axleRatio;
        double _auxPower;
        double _pNormV0;
        double _pNormP0;
        double _pNormV1;
        double _pNormP1;

        double _engineRatedSpeed;
        double _engineIdlingSpeed;
        double _effectiveWheelDiameter;

        std::vector<double> _speedPatternRotational;
        std::vector<double> _powerPatternFC;
        std::vector<double> _normalizedPowerPatternFC;
        std::vector<double> _normailzedPowerPatternPollutants;
        std::vector<double> _powerPatternPollutants;

        std::vector<double> _cepCurveFC;
        std::vector<double> _normedCepCurveFC;
        std::vector<double> _gearTransmissionCurve;
        std::vector<double> _speedCurveRotational;
        std::map<std::string, std::vector<double> > _cepCurvePollutants;
        std::map<std::string, std::vector<double> > _cepNormalizedCurvePollutants;
        double _idlingValueFC;
        std::map<std::string, double> _idlingValuesPollutants;

        std::vector<double> _nNormTable;
        std::vector<double> _dragNormTable;


        //--------------------------------------------------------------------------------------------------
        // Methods 
        //--------------------------------------------------------------------------------------------------

    public:
        double CalcPower(double speed, double acc, double gradient);

        double CalcEngPower(double power);

        double GetEmission(const std::string& pollutant, double power, double speed, Helpers* VehicleClass);


        double GetCO2Emission(double _FC, double _CO, double _HC, Helpers* VehicleClass);

        double GetDecelCoast(double speed, double acc, double gradient);

        double GetRotationalCoeffecient(double speed);


    private:
        void FindLowerUpperInPattern(int& lowerIndex, int& upperIndex, std::vector<double>& pattern, double value);

        double Interpolate(double px, double p1, double p2, double e1, double e2);

        //--------------------------------------------------------------------------------------------------
        // Operators for fleetmix
        //--------------------------------------------------------------------------------------------------


    private:
        void InitializeInstanceFields();
    };
}


#endif	//#ifndef PHEMlightCEP

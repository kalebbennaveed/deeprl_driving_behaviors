/*   
    Copyright (C) 2017 Mario Krumnow, Dresden University of Technology

    This file is part of TraaS.

    TraaS is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License.

    TraaS is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with TraaS.  If not, see <http://www.gnu.org/licenses/>.
*/

package de.tudresden.sumo.cmd;
import de.tudresden.sumo.config.Constants;
import de.tudresden.sumo.util.SumoCommand;
import de.tudresden.ws.container.SumoPosition2D;

/**
 * 
 * @author Mario Krumnow
 * @author Evamarie Wiessner
 *
 */

public class Simulation {

	//getter methods

	/**
	 * convert2D
	 * @param edgeID edge id
	 * @param pos pos 
	 * @param laneIndex index
	 * @param toGeo geo
	 * @return SumoCommand
	 */
	public static SumoCommand convert2D(String edgeID, double pos, byte laneIndex, String toGeo){
		Object[] array = new Object[]{pos, laneIndex, toGeo};
		return new SumoCommand(Constants.CMD_GET_SIM_VARIABLE, Constants.POSITION_CONVERSION, edgeID, array, Constants.RESPONSE_GET_SIM_VARIABLE, Constants.TYPE_STRINGLIST);
	}

	/**
	 * convert3D
	 * @return SumoCommand
	 * @param edgeID edge id
	 * @param pos pos
	 * @param laneIndex index
	 * @param toGeo geo
	 */
	public static SumoCommand convert3D(String edgeID, double pos, byte laneIndex, String toGeo){
		Object[] array = new Object[]{pos, laneIndex, toGeo};
		return new SumoCommand(Constants.CMD_GET_SIM_VARIABLE, Constants.POSITION_CONVERSION, edgeID, array, Constants.RESPONSE_GET_SIM_VARIABLE, Constants.TYPE_STRINGLIST);
	}
	
	
	/**
	 * convertGeo
	 * @return SumoCommand
	 * @param x x 
	 * @param y y
	 * @param fromGeo geo
	 */
	public static SumoCommand convertGeo(double x, double y, boolean fromGeo){
		
		 byte fromType = Constants.POSITION_2D;
		 byte toType = Constants.POSITION_LON_LAT;
		
		 if(fromGeo){
			 fromType = Constants.POSITION_LON_LAT;
		     toType = Constants.POSITION_2D;
		 }
		 
		Object[] array = new Object[]{fromType, x, y, toType};
		return new SumoCommand(Constants.CMD_GET_SIM_VARIABLE, Constants.POSITION_CONVERSION, "", array, Constants.RESPONSE_GET_SIM_VARIABLE, fromGeo ? Constants.POSITION_2D : Constants.POSITION_LON_LAT);
	}

	/**
	 * convertRoad
	 * @return SumoCommand
	 * @param x x
	 * @param y y
	 * @param isGeo geo
	 */
	public static SumoCommand convertRoad(double x, double y, String isGeo){
		Object[] array = new Object[]{y, isGeo};
		return new SumoCommand(Constants.CMD_GET_SIM_VARIABLE, Constants.VAR_POSITION, x, array, Constants.RESPONSE_GET_SIM_VARIABLE, Constants.POSITION_2D);
	}

	/**
	 * Returns a list of IDs of vehicles which arrived in this time step.
	 * @return list of vehicles
	 */

	public static SumoCommand getArrivedIDList(){
		return new SumoCommand(Constants.CMD_GET_SIM_VARIABLE, Constants.VAR_ARRIVED_VEHICLES_IDS, "", Constants.RESPONSE_GET_SIM_VARIABLE, Constants.TYPE_STRINGLIST);
	}

	/**
	 * Returns the number of vehicles which arrived in this time step.
	 * @return number of vehicles
	 */

	public static SumoCommand getArrivedNumber(){
		return new SumoCommand(Constants.CMD_GET_SIM_VARIABLE, Constants.VAR_ARRIVED_VEHICLES_NUMBER, "", Constants.RESPONSE_GET_SIM_VARIABLE, Constants.TYPE_INTEGER);
	}

	/**
	 * Returns the current waiting time on bus stops(in ms).
	 * @return waiting time
	 */

	public static SumoCommand getBusStopWaiting(){
		return new SumoCommand(Constants.CMD_GET_SIM_VARIABLE, Constants.VAR_BUS_STOP_WAITING, "", Constants.RESPONSE_GET_SIM_VARIABLE, Constants.TYPE_INTEGER);
	}

	/**
	 * getParkingEndingVehiclesIDList()
	 * @return number of vehicles
	 */

	public static SumoCommand getParkingEndingVehiclesIDList(){
		return new SumoCommand(Constants.CMD_GET_SIM_VARIABLE, Constants.VAR_PARKING_ENDING_VEHICLES_IDS, "", Constants.RESPONSE_GET_SIM_VARIABLE, Constants.TYPE_STRINGLIST);
	}

	
	/**
	 * getParkingEndingVehiclesNumber()
	 * @return number of vehicles
	 */

	public static SumoCommand getParkingEndingVehiclesNumber(){
		return new SumoCommand(Constants.CMD_GET_SIM_VARIABLE, Constants.VAR_PARKING_ENDING_VEHICLES_NUMBER, "", Constants.RESPONSE_GET_SIM_VARIABLE, Constants.TYPE_INTEGER);
	}

	/**
	 * getParkingStartingVehiclesIDList()
	 * @return number of vehicles
	 */

	public static SumoCommand getParkingStartingVehiclesIDList(){
		return new SumoCommand(Constants.CMD_GET_SIM_VARIABLE, Constants.VAR_PARKING_STARTING_VEHICLES_IDS, "", Constants.RESPONSE_GET_SIM_VARIABLE, Constants.TYPE_STRINGLIST);
	}
	

	/**
	 * getParkingStartingVehiclesNumber()
	 * @return number of vehicles
	 */

	public static SumoCommand getParkingStartingVehiclesNumber(){
		return new SumoCommand(Constants.CMD_GET_SIM_VARIABLE, Constants.VAR_PARKING_STARTING_VEHICLES_NUMBER, "", Constants.RESPONSE_GET_SIM_VARIABLE, Constants.TYPE_INTEGER);
	}
	
	
	/**
	 * getStopEndingVehiclesIDList()
	 * @return number of vehicles
	 */

	public static SumoCommand getStopEndingVehiclesIDList(){
		return new SumoCommand(Constants.CMD_GET_SIM_VARIABLE, Constants.VAR_STOP_ENDING_VEHICLES_IDS, "", Constants.RESPONSE_GET_SIM_VARIABLE, Constants.TYPE_STRINGLIST);
	}
	
	
	/**
	 * getStopEndingVehiclesNumber()
	 * @return number of vehicles
	 */

	public static SumoCommand getStopEndingVehiclesNumber(){
		return new SumoCommand(Constants.CMD_GET_SIM_VARIABLE, Constants.VAR_STOP_ENDING_VEHICLES_NUMBER, "", Constants.RESPONSE_GET_SIM_VARIABLE, Constants.TYPE_INTEGER);
	}
	
	/**
	 * getStopStartingVehiclesIDList()
	 * @return list of vehicles
	 */

	public static SumoCommand getStopStartingVehiclesIDList(){
		return new SumoCommand(Constants.CMD_GET_SIM_VARIABLE, Constants.VAR_STOP_STARTING_VEHICLES_IDS, "", Constants.RESPONSE_GET_SIM_VARIABLE, Constants.TYPE_STRINGLIST);
	}
	

	/**
	 * getStopStartingVehiclesIDList()
	 * @return list of vehicles
	 */

	public static SumoCommand getStopStartingVehiclesNumber(){
		return new SumoCommand(Constants.CMD_GET_SIM_VARIABLE, Constants.VAR_STOP_STARTING_VEHICLES_NUMBER, "", Constants.RESPONSE_GET_SIM_VARIABLE, Constants.TYPE_INTEGER);
	}
	
	
	/**
	 * getCurrentTime
	 * @return current time
	 */

	public static SumoCommand getCurrentTime(){
		return new SumoCommand(Constants.CMD_GET_SIM_VARIABLE, Constants.VAR_TIME_STEP, "", Constants.RESPONSE_GET_SIM_VARIABLE, Constants.TYPE_INTEGER);
	}

	/**
	 * getDeltaT
	 * @return delat time
	 */

	public static SumoCommand getDeltaT(){
		return new SumoCommand(Constants.CMD_GET_SIM_VARIABLE, Constants.VAR_DELTA_T, "", Constants.RESPONSE_GET_SIM_VARIABLE, Constants.TYPE_INTEGER);
	}

	/**
	 * Returns a list of IDs of vehicles which departed in this time step.
	 * @return  list of IDs of vehicles which departed in this time step.
	 */

	public static SumoCommand getDepartedIDList(){
		return new SumoCommand(Constants.CMD_GET_SIM_VARIABLE, Constants.VAR_DEPARTED_VEHICLES_IDS, "", Constants.RESPONSE_GET_SIM_VARIABLE, Constants.TYPE_STRINGLIST);
	}

	/**
	 * Returns the number of vehicles which departed in this time step.
	 * @return the number of vehicles which departed in this time step.
	 */

	public static SumoCommand getDepartedNumber(){
		return new SumoCommand(Constants.CMD_GET_SIM_VARIABLE, Constants.VAR_DEPARTED_VEHICLES_NUMBER, "", Constants.RESPONSE_GET_SIM_VARIABLE, Constants.TYPE_INTEGER);
	}

	/**
	 * Reads two coordinate pairs and an indicator whether the air or the driving distance shall be computed. Returns the according distance.
     */

	/**
	 * @param x1 x1
	 * @param y1 y1
	 * @param x2 x2
	 * @param y2 y2
	 * @param isGeo is geo
	 * @param isDriving is driving
	 * @return distance
	 */
	public static SumoCommand getDistance2D(double x1, double y1, double x2, double y2, boolean isGeo, boolean isDriving){
		Object[] array = new Object[]{new SumoPosition2D(x1, y1), new SumoPosition2D(x2, y2), isGeo, isDriving};
		return new SumoCommand(Constants.CMD_GET_SIM_VARIABLE, Constants.DISTANCE_REQUEST, array, Constants.RESPONSE_GET_SIM_VARIABLE, Constants.TYPE_DOUBLE);
	}

	/**
	 * getDistanceRoad
	 */

	/**
	 * @param edgeID1 first edge
	 * @param pos1 first position
	 * @param edgeID2 second edge
	 * @param pos2 second position
	 * @param isDriving is drinving
	 * @return the distance in [m]
	 */
	public static SumoCommand getDistanceRoad(String edgeID1, double pos1, String edgeID2, double pos2, boolean isDriving){
		Object[] array = new Object[]{edgeID1, pos1, edgeID2, pos2, isDriving};
		return new SumoCommand(Constants.CMD_GET_SIM_VARIABLE, Constants.DISTANCE_REQUEST, array, Constants.RESPONSE_GET_SIM_VARIABLE, Constants.TYPE_DOUBLE);
	}

	/**
	 * Returns a list of IDs of vehicles which ended to be teleported in this time step.
	 * @return SumoCommand
	 */

	public static SumoCommand getEndingTeleportIDList(){
		return new SumoCommand(Constants.CMD_GET_SIM_VARIABLE, Constants.VAR_TELEPORT_ENDING_VEHICLES_IDS, "", Constants.RESPONSE_GET_SIM_VARIABLE, Constants.TYPE_STRINGLIST);
	}

	/**
	 * Returns the number of vehicles which ended to be teleported in this time step.
 	 * @return SumoCommand
	 */

	public static SumoCommand getEndingTeleportNumber(){
		return new SumoCommand(Constants.CMD_GET_SIM_VARIABLE, Constants.VAR_TELEPORT_ENDING_VEHICLES_NUMBER, "", Constants.RESPONSE_GET_SIM_VARIABLE, Constants.TYPE_INTEGER);
	}

	/**
	 * Returns a list of IDs of vehicles which were loaded in this time step.
 	 * @return SumoCommand
	 */

	public static SumoCommand getLoadedIDList(){
		return new SumoCommand(Constants.CMD_GET_SIM_VARIABLE, Constants.VAR_LOADED_VEHICLES_IDS, "", Constants.RESPONSE_GET_SIM_VARIABLE, Constants.TYPE_STRINGLIST);
	}

	/**
	 * Return the number of vehicles which were loaded in this time step.	 * @return SumoCommand
	 * @return SumoCommand
	 */

	public static SumoCommand getLoadedNumber(){
		return new SumoCommand(Constants.CMD_GET_SIM_VARIABLE, Constants.VAR_LOADED_VEHICLES_NUMBER, "", Constants.RESPONSE_GET_SIM_VARIABLE, Constants.TYPE_INTEGER);
	}

	/**
	 * Returns the number of vehicles which are in the net plus the ones still waiting to start.
 	 * @return SumoCommand
	 */

	public static SumoCommand getMinExpectedNumber(){
		return new SumoCommand(Constants.CMD_GET_SIM_VARIABLE, Constants.VAR_MIN_EXPECTED_VEHICLES, "", Constants.RESPONSE_GET_SIM_VARIABLE, Constants.TYPE_INTEGER);
	}

	/**
	 * Returns the boundary box of the simulation network.
	 * @return SumoCommand
	 */
	public static SumoCommand getNetBoundary(){
		return new SumoCommand(Constants.CMD_GET_SIM_VARIABLE, Constants.VAR_NET_BOUNDING_BOX, "", Constants.RESPONSE_GET_SIM_VARIABLE, Constants.TYPE_BOUNDINGBOX);
	}

	/**
	 * Returns a list of IDs of vehicles which started to teleport in this time step.
 	 * @return SumoCommand
	 */

	public static SumoCommand getStartingTeleportIDList(){
		return new SumoCommand(Constants.CMD_GET_SIM_VARIABLE, Constants.VAR_TELEPORT_STARTING_VEHICLES_IDS, "", Constants.RESPONSE_GET_SIM_VARIABLE, Constants.TYPE_STRINGLIST);
	}

	/**
	 * Returns the number of vehicles which started to teleport in this time step.
	 * @return SumoCommand
	 */

	public static SumoCommand getStartingTeleportNumber(){
		return new SumoCommand(Constants.CMD_GET_SIM_VARIABLE, Constants.VAR_TELEPORT_STARTING_VEHICLES_NUMBER, "", Constants.RESPONSE_GET_SIM_VARIABLE, Constants.TYPE_INTEGER);
	}

	//setter methods

	/**
	 * Clear pending
	 * @param routeID route id
	 * @return SumoCommand
	 */

	public static SumoCommand clearPending(String routeID){
		return new SumoCommand(Constants.CMD_SET_SIM_VARIABLE, Constants.CMD_CLEAR_PENDING_VEHICLES, "", routeID);
	}

	/**
	 * save state
	 * @param filename
	 * @return SumoCommand
	 */

	public static SumoCommand saveState(String filename){
		return new SumoCommand(Constants.CMD_SET_SIM_VARIABLE, Constants.CMD_SAVE_SIMSTATE, "", filename);
	}
	
}
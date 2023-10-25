#ifndef AIRPORTANDGATE_H
#define AIRPORTANDGATE_H

#include <string>
#include <vector>
#include "Airplane.h"
#include <iostream>


class Airplane;
/*
 * Part 1.
 *
 * Create descriptive documentation of the Gate and Airport classes. For each class, provide a summary of the functionality
 * and purpose. This summary should be a MINIMUM of three full sentences. For each constructor and function of the class,
 * using a MINIMUM of two full sentences, describe:
 * 1. Parameter names, types, what the purpose of the parameter is
 * 2. What this function/constructor does. If it only assigns/returns variables, what is the purpose of this variable?
 *    Make sure to clearly explain the functionality and logic of the more complicated sections.
 * 3. What the return type and data is.
 *
 * Write documentation in this file as block comments, like this, ABOVE the class/function/constructor you are describing.
 *
 */

/*
 * The Gate class represents an individual gate at an airport. 
 * Each gate has a gate name and can have an airplane flight name, 
 * which represents the airplain that is currently at that gate.
 * It tracks and manages where each airplain is currently at.
*/
class Gate {
public:

    /*
     * Parameters: Parameters: name (const std::string&) - The name of the gate.
     *
     * This constructor initializes a Gate object with the gate name. 
     * It is used to create a gate which will have a name such as 'a1',
     * inorder to identify what gate we are currently at.
     * 
     * Return: None
    */
    Gate(const std::string& name) {
        this->gate_name = name;
    }

    /*
     * This function returns the name of the gate.
     * It helps to see what the current gate is.
     * 
     * Return: const std::string& - The name of the gate.
    */
    const std::string& getName() const {
        return this->gate_name;
    }

    /*
     * Parameters: flight_name (const std::string&) - The name of the flight at the gate.
     *
     * This function is to set a flight associated with the gate. 
     * Which means it sets the flight_name to the current gate object.
     * 
     * Return: None
    */
    void setFlight(const std::string& flight_name) {
        this->flight = flight_name;
    }

    /*
     * This function returns the name of the flight that is at the gate.
     * It helps to see what the current flight is at this gate.
     * 
     * Return: const std::string& - The name of the flight at the gate.
    */
    const std::string& getFlight() const {
        return this->flight;
    }

private:
    std::string flight;
    std::string gate_name;
};


/*
 * The Airport class represents an airport with a specific location ID. 
 * It manages a list of gates and handles the landing and launching of 
 * airplanes from those gates. The class provides information about gate 
 * statuses, the total number of gates, and the number of available gates.
*/

class Airport {
public:
    /*
     * Parameters: location_id (const std::string&) - The location ID for the airport.
     *
     * This constructor initializes an Airport object with the specified 
     * location identifier. It sets up an initial collection of gates.
     * 
     * Return: None
    */
    Airport(const std::string& location_id) {
        this->location_id = location_id;
    };

    /*
     * Parameters: ap (Airplane&) - A reference to an Airplane object 
     *                              representing an airplane for landing.
     *
     * This function attempts to assign an available gate to the given 
     * airplane for landing. It checks for available gates, and ensures that 
     * the airplane is not already assigned to a gate, and updates the airplane's
     * state and gate assignment accordingly.
     * 
     * Return: bool - true if the landing was successful, false otherwise.
     *  
    */
    bool landAirplane(Airplane& ap) {
        if (getFreeGates() > 0) {

            for (const Gate& g: this->gates) {
                if (g.getFlight() == ap.getFlightID()) {
                    return false;
                }
            }

            std::string assigned_gate = assignGate(ap);
            ap.setState("landed");
            ap.setGate(assigned_gate);
            return true;
        } else {
            return false;
        }
    }

    /*
     * Parameters: ap (Airplane&) - A reference to an Airplane object 
     *                              representing an airplane for launching.
     * 
     * This function attemps to removes the airplane from the gate and sets it to 
     * status of flying. This then sets the gate of the airplane to nothing "".
     * 
     * Return: bool - true if the launch was successful, false otherwise.
    */
    bool launchAirplane(Airplane& ap) {
        if (removeGate(ap)) {
            ap.setState("flying");
            ap.setGate("");
            return true;
        } else {
            return false;
        }
    }

    /*
     * This function prints the statuses of all gates at the airport.
     * Including the gate names and the flight names that each gate.
     * 
     * Return: None 
    */
    void gateStatuses() const {
        std::cout << "Gate statuses for airport " << this->location_id << ":\n";
        for (const Gate& g: this->gates) {
            std::cout << "\tGate " << g.getName() << ": " << g.getFlight() << "\n";
        }
    };

    /*
     * This function returns the total number of gates at the airport.
     * This indicates how many gates each airport has.
     * 
     * Return: int - The total number of gates.
    */
    int getTotalGates() const {
        return gates.size();
    };

    /*
     * This function returns the number of available gates at the airport.
     * This indicates back to the caller how many gates are open for airplanes.
     * 
     * Return: int - The number of available gates.
    */
    int getFreeGates() const {
        int free_gates = 0;
        for (const Gate& g: this->gates) {
            if (g.getFlight().length() == 0) {
                free_gates += 1;
            }
        }
        return free_gates;
    };

    /*
     * This function returns a reference to the location ID of the airport.
     * This tells what location this airport represents.
     * 
     * Return: std::string& - A reference to the location identifier.
    */
    std::string& getLocationID(){
        return this->location_id;
    }


private:

    /*
     * Parameters: ap (const Airplane&) - A reference to an Airplane object representing 
     *                                    the airplane to be assigned to a gate.
     *
     * This private function assigns a gate with the given airplane
     * It returns the name of the gate or an empty string if no gate is available.
     * 
     * Return: std::string - The name of the assigned gate or an empty string.
    */
    std::string assignGate(const Airplane& ap) {
        for (Gate& g: this->gates) {
            if (g.getFlight().length() == 0) {
                g.setFlight(ap.getFlightID());
                return g.getName();
            }
        }
        return "";
    };

    /*
     * Parameters: ap (const Airplane&) - A reference to an Airplane object representing 
     *                                    the airplane to be removed from a gate.
     * 
     * This private function removes an airplane from a gate.
     * This sets the gate to and empty stirng "" indicating its available.
     * 
     * Return: bool - true if the removal was successful, false otherwise.
    */
    bool removeGate(const Airplane& ap) { 
        for (Gate& g: this->gates) {
            if (g.getFlight() == ap.getFlightID()) {
                g.setFlight("");
                return true;
            }
        }
        return false;
    }

    std::string location_id;
    std::vector<Gate> gates{Gate("a1"), Gate("a2"), Gate("b1")};

};

#endif //AIRPORTANDGATE_H

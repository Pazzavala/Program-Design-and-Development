#include <iostream>

#include "Airplane.h"
#include "AirportAndGate.h"

/*
 * Part 1.
 *
 * See AirportAndGate.h
 *
 * Part 2.
 * See Airplane.h. Use this file to test functionality.
 */

/*
 * Part 3.
 * Add functionality to the main code below to let Airplanes follow an itinerary of Airports that they
 * should land at. 
 * 
 * - Airplanes will start at the first airport in their itinerary, then land and takeoff at each
 *      Airport in their itinerary until they land at their last destination. 
 * 
 * - Then, the Airplane will follow the itinerary in REVERSE order until it reaches its original starting Airport.
 * 
 *------------------------------------------------------------------------------------------------------------------
 *  1. You will create a new vector called "itinerary" that will contain pointers to Airport objects.
 *  
 *  2. This vector represents the Airports the Airplane will fly to, in order. 
 * 
 *  3. The Airplane class will contain this new "itinerary" vector.
 * 
 *  4. The vector should be created and populated in this main file, then passed into the Airplane class via its constructor.
 *
 * 
 * ------------------------------------------------------------------------------------------------------------------
 * In this file, you will add a loop that will run until every plane has returned to its first Airport. 
 * 
 *  1. In this loop, each plane will try to land at the next Airport in its itinerary. 
 *  
 *  2. Also in this loop, "cout" which Airport each Airplane is currently at. 
 *      - It may be helpful to add additional variables to the Airplane class to keep track of the
 *        current and previous Airport the Airplane has been at,
 * 
 *      - as well as which direction you are iterating through the vector. 
 * 
 *  3. Make sure to use setters/getters to access class member variables. 
 *      - All member variables should be private.
 * 
 *  4. Use the landPlane and launchPlane functions in this main.cc file to make Airplanes interact with Airports.
 */
 

/* ------------------------------------------------------------------------------------------------------------------
 * The Airplanes, Airports, and itineraries are shown below. The itineraries are for the forward trip only:
 * 
 * flightID AC1111: MSP -> YYZ
 * flightID AC2222: YYZ -> YQB -> MSP
 * flightID AC3333: YYZ -> YQB -> MSP
 * flightID JB1111: BOS -> TPA -> MSP
 * flightID JB2222: MSP -> BOS
 * flightID JB3333: BOS -> MSP
 */

int main() {

    // ===================== BEGIN Part 2 testing code =====================
    Airport msp("MSP");
    Airplane a1("a1-123");
    Airplane a2("a2-123");
    Airplane a3("a3-123");
    msp.gateStatuses();
    msp.landAirplane(a1);
    msp.landAirplane(a2);
    msp.gateStatuses();
    msp.landAirplane(a1); // <- Cannot land the same flightID twice, only 1 copy of the flightID will show up in gateStatuses
    msp.landAirplane(a3);
    msp.gateStatuses();
    msp.launchAirplane(a1);
    msp.gateStatuses();
    // ===================== END Part 2 testing code =====================

    // Create Airports
    Airport yyz("YYZ");
    Airport yqb("YQB");
    Airport bos("BOS");
    Airport tpa("TPA");

    // Create Itinerary's -> add Airports to vector
    std::vector<Airport*> it1{&msp, &yyz};
    std::vector<Airport*> it2{&yyz, &yqb, &msp};
    std::vector<Airport*> it3{&yyz, &yqb, &msp};
    std::vector<Airport*> it4{&bos, &tpa, &msp};
    std::vector<Airport*> it5{&msp, &bos};
    std::vector<Airport*> it6{&bos, &msp};

    // Create Airplanes with flight id and itinerary
    Airplane ac1("AC1111", it1);
    Airplane ac2("AC2222", it2);
    Airplane ac3("AC3333", it3);
    Airplane ac4("JB1111", it4);
    Airplane ac5("JB2222", it5);
    Airplane ac6("JB3333", it6);

    // Add Airplanes to vector
    std::vector<Airplane> airplanes{ac1, ac2, ac3, ac4, ac5, ac6};

    for (Airplane& plane: airplanes)
        plane.setIter(0);

    /*
     * While all planes are not at their original airport:
     *      for each airplane in the airplanes vector:
     *          if the airplane has landed at desired airport:
     *              launch the airplane from the previous airport
     *              increment itinerary index by 1
     *              ...
     *              ...
     *          cout the flight ID and current airport of the airplane
     */

    bool flightsNotComplete = true;
    int iteration = 0;
    while (flightsNotComplete) {

        for (Airplane& plane : airplanes) {
            std::vector<Airport*> itinerary = plane.getItinerary();
            long unsigned int index = plane.getIter();

            if (itinerary.at(index)->landAirplane(plane)) {
                itinerary.at(index)->launchAirplane(plane);
                plane.setCurrAirport(itinerary.at(index)->getLocationID());

                if (plane.getDirection() == "forward") {
                    if (index < itinerary.size() - 1) {
                        plane.incrementIter();
                    } 
                } else { // If plane going backwords decrement
                    if (index > 0) 
                        plane.decrementIter();
                }
                
            }       

            // If plane has reached the end of itinerary go back
            if (plane.getCurrAirport() == itinerary.at(itinerary.size() - 1)->getLocationID()) {
                plane.setDirection("backwords");
            }
            
            std::cout << "Airplane: " << plane.getFlightID() << " is at " << plane.getCurrAirport() << std::endl;

            // Check if plane is back at og airport and set if complete
            if (iteration != 0 && plane.getCurrAirport() == itinerary.at(0)->getLocationID())
                plane.setComplete(true);
        }

        std::cout << std::endl;

        bool allTrue = true;
            
        for (Airplane& plane : airplanes)
            allTrue = allTrue && plane.getComplete();

        if (allTrue)
            flightsNotComplete = false;

        iteration++;
    }

    return 0;
}
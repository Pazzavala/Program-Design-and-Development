// Make sure this file has header guards to prevent cyclical dependencies
#ifndef AIRPLANE_H
#define AIRPLANE_H

#include <string>
#include <vector>

class Airport;

/*
 * Part 2.
 *
 * The Airplane class interacts with the Airport class to land and takeoff from it. Use information from the
 * AirportAndGate.h file as well as comments from this file to:
 *  1. **Declare** all necessary functions, constructors, destructors, and member variables in this header file (.h file)
 *  2. **Implement** all declared functions, constructors, destructors in the .cc file
 *
 * Remember, member variables should be private and only use setters/getters to access them.
 */

/*
 * Part 3.
 *
 * Use forward declaration of the Airport class to make things easier.
 * Add any additional member variables or functions you need to work with the itinerary vector.
 */

class Airplane {
    /*
     * The Airplane class is fairly simple, as most logic for the program lies in the Airport class. Here is a list
     * of details the Airplane class must follow:
     *  1. Upon creation of a new object, an alphanumeric flight ID should be stored in the class.
     *  2. Variables representing state, and gate must be private member variables be stored in the class
     *      and must be accessed using setters/getters.
     *  3. The flight ID can only be accessed after instantiation, it cannot be changed.
     *  4. Any dynamically allocated memory must be free'd in the class's destructor.
     */

    public:
        // Constructor w/ 1 arguemnt flightID
        Airplane(const std::string& flightid);
        // Constructor w/ 2 arguments flightID and itinerary
        Airplane(const std::string& flightid, std::vector<Airport*> itinerary);
        // Deconstructor
        ~Airplane();


        // Setter for state
        void setState(std::string state);
        // Setter for gate
        void setGate(std::string gate);
        // Setter for itinerary
        void setItinerary(std::vector<Airport*> itinerary);
        // Setter for current Airport
        void setCurrAirport(std::string airport);
        // Setter for direction
        void setDirection(std::string direction);
        // Setter for complete
        void setComplete(bool complete);
        // Setter for iter
        void setIter(int iter);

        // Getter for flightID
        const std::string& getFlightID() const;
        // Getter for state
        std::string getState() const;
        // Getter for gate
        std::string getGate() const;
        // Getter for itinerary
        std::vector<Airport*> getItinerary();
        // Getter for current airport
        std::string getCurrAirport();
        // Getter for direction
        std::string getDirection();
        //Getter for complete
        bool getComplete();
        // Getter for iter
        int getIter();

        void incrementIter();
        void decrementIter();

    private:
        const std::string flightID;
        std::string state;
        std::string gate;
        std::vector<Airport*> itinerary;
        std::string airport;
        std::string direction;
        bool complete;
        int iter;

};

#endif //AIRPLANE_H

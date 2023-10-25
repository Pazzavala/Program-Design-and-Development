#include "Airplane.h"

/*
 * Implement the Airplane class here. Refer to Airplane.h for class details.
 */
Airplane::Airplane(const std::string& flightid): flightID(flightid) { }

Airplane::Airplane(const std::string& flightid, std::vector<Airport*> itinerary): flightID(flightid), itinerary(itinerary) {
    direction = "forward";
    complete = false;
 }

Airplane::~Airplane()
{
    
}

// Setters
void Airplane::setState(std::string state)
{
    this->state = state;
}

void Airplane::setGate(std::string gate)
{
    this->gate = gate;
}

void Airplane::setItinerary(std::vector<Airport*> itinerary)
{
    this->itinerary = itinerary;
}

void Airplane::setCurrAirport(std::string airport) {
    this->airport = airport;
}

void Airplane::setDirection(std::string direction) {
    this->direction = direction;
}

void Airplane::setComplete(bool complete) {
    this->complete = complete;
}

void Airplane::setIter(int iter) {
    this->iter = iter;
}

// Getters
const std::string& Airplane::getFlightID() const
{
    return flightID;
}

std::string Airplane::getState() const
{
    return state;
}

std::string Airplane::getGate() const
{
    return gate;
}

std::vector<Airport*> Airplane::getItinerary() {
    return itinerary;
}

std::string Airplane::getCurrAirport() {
    return airport;
}

std::string Airplane::getDirection() {
    return direction;
}

bool Airplane::getComplete() {
    return complete;
}

int Airplane::getIter() {
    return iter;
}


void Airplane::incrementIter() {
    iter++;
}

void Airplane::decrementIter() {
    iter--;
}
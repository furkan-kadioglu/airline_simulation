#include <iostream>
#include "Passenger.h"
using namespace std;

//Passenger Constructor 
Passenger::Passenger(
    int _id,
    int _arrival_time,
    int _flight_time,
    int _luggage_expended,
    int _security_expended,
    bool _security,
    bool _luggage
    ){

    this->id = _id;
    this->arrival_time = _arrival_time;
    this->flight_time = _flight_time;
    this->luggage_expended_time = _luggage_expended;
    this->security_expended_time = _security_expended;
    this->vip = _security;
    this->luggage = _luggage;
    
    
    
}

Passenger::Passenger() {
    this->id = -1;
    this->arrival_time = -1;
    this->flight_time = -1;
    this->luggage_expended_time = -1;
    this->security_expended_time = -1;
    this->vip = false;
    this->luggage = false;
}

Passenger::~Passenger(){
    
}
#ifndef PASSENGER_H
#define PASSENGER_H
#include <iostream>
using namespace std;

class Passenger {
    
    public:
        //given information as an input 
        int id;
        int arrival_time;
        int flight_time;
        int luggage_expended_time;
        int security_expended_time;
        bool vip;
        bool luggage;
        

        //calculated information from input 
        int luggage_counter_time;
        int security_counter_time;
        
        Passenger();
        
        Passenger(
            int _id,
            int _arrival_time,
            int _flight_time,
            int _luggage_expended,
            int _security_expended,
            bool _security,
            bool _luggage
            );
        ~Passenger();

};
#endif
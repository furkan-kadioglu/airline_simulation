#ifndef _MODEL_H_
#define _MODEL_H_
#include <iostream>
#include <vector>
#include "Passenger.h"
using namespace std;


class Model{
    public:
        vector<Passenger> passengers;
        int luggageCounterNumber;
        int securityCounterNumber;
        bool onlineCheckIn;
        bool vipService;
        bool flightPriority;

        Model();
        Model(
            vector<Passenger> _passengers,
            int _luggageCounterNumber,
            int _securityCounterNumber,
            bool _onlineCheckIn,
            bool _vipService,
            bool _flightPriority);
        ~Model();
        vector<Passenger> simulate();
    
        
};
#endif
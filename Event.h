#ifndef _EVENT_H_
#define _EVENT_H_
#include <iostream>
using namespace std;


class Event {
    
    public:
     

        /*
        type == 0
            passenger is arrived 
        type == 1
            luggage is done 
        type == 2
            security is done
        */
        int time;
        int typeOfEvent;
        int passengerId;
        int arrivalTime;

        Event();
        Event(
            int _time,
            int _typeOfEvent,
            int _passengerId,
            int _arrivalTime);
        bool operator<(const Event& _event)const;
        ~Event();

};
#endif
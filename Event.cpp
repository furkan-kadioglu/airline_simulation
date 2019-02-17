#include <iostream>
#include "Event.h"
using namespace std;

Event::Event(){
    time = 0;
    typeOfEvent = -1;
    passengerId = -1;
    arrivalTime = -1;

}

Event::Event(
    int _time,
    int _typeOfEvent,
    int _passengerId,
    int _arrivalTime){
    
    time = _time;
    typeOfEvent = _typeOfEvent;
    passengerId = _passengerId;
    arrivalTime = _arrivalTime;
}

bool Event::operator< (const Event& _event)const{
    
    if( time != _event.time){
        return time > _event.time;
    }else {
        if(typeOfEvent != _event.typeOfEvent){
            return typeOfEvent < _event.typeOfEvent;
        }else {
            return arrivalTime > _event.arrivalTime;
        }
    }
}
Event::~Event(){

}
#include <iostream>
#include "Model.h"
#include "Event.h"
#include <queue>
//#include <vector>
using namespace std;

Model::Model(){
    luggageCounterNumber = 0;
    securityCounterNumber = 0;
    onlineCheckIn = false;
    vipService = false;
    flightPriority = false;
}

Model::Model(
        vector<Passenger> _passengers,
        int _luggageCounterNumber,
        int _securityCounterNumber,
        bool _onlineCheckIn,
        bool _vipService,
        bool _flightPriority){

        passengers = _passengers;
        luggageCounterNumber = _luggageCounterNumber;
        securityCounterNumber = _securityCounterNumber;
        onlineCheckIn = _onlineCheckIn;
        vipService = _vipService;
        flightPriority = _flightPriority;
    
}


Model::~Model(){
    
}
vector<Passenger> Model::simulate(){
    priority_queue<Event> eventQueue;
    for(int i = 0; i < passengers.size();i++){
        eventQueue.push(Event(passengers[i].arrival_time,0,i,passengers[i].arrival_time));
    }
    priority_queue<pair<pair<int,int>,int>> luggageQueue;
    priority_queue<pair<pair<int,int>,int>> securityQueue;

    int availableLuggage = luggageCounterNumber;
    int availableSecurity = securityCounterNumber;
    int stabilizer = 0;
    
    while(!eventQueue.empty()){
        Event event = eventQueue.top();
        eventQueue.pop();
        Passenger &pass = passengers[event.passengerId];
        Passenger p;
        
        switch(event.typeOfEvent){  
            
            case 0: 
                if(onlineCheckIn && !pass.luggage){
                    pass.luggage_counter_time=event.time;
                    if(vipService && pass.vip){
                        pass.security_counter_time=event.time;
                        pass.security_expended_time=0;
                    }else {
                        if(securityQueue.empty() && availableSecurity > 0){
                            eventQueue.push(Event(event.time+pass.security_expended_time,2,pass.id,pass.arrival_time));
                            
                            pass.security_counter_time = event.time;
                            availableSecurity -= 1;
                        }else{
                            if(flightPriority){
                                securityQueue.push(make_pair(make_pair(-pass.flight_time,-pass.arrival_time),pass.id));
                            }else {
                                securityQueue.push(make_pair(make_pair(--stabilizer,0),pass.id));
                            }
                            
                        }
                    }
                    

                }else{
                    if(luggageQueue.empty() && availableLuggage > 0){
                        eventQueue.push(Event(event.time+pass.luggage_expended_time,1,event.passengerId,pass.arrival_time));
                        pass.luggage_counter_time=event.time;
                        availableLuggage -= 1;
                    }else {
                        if(flightPriority){
                            luggageQueue.push(make_pair(make_pair(-pass.flight_time,-pass.arrival_time)  ,pass.id));
                        }else{
                            luggageQueue.push(make_pair(make_pair(--stabilizer,0),pass.id));
                        }
                        
                    }
                } 
                
                break;
            case 1:
                if(vipService && pass.vip){
                    pass.security_counter_time=event.time;
                    pass.security_expended_time=0;
                }else{
                    if(securityQueue.empty() && availableSecurity > 0){
                        eventQueue.push(Event(event.time+pass.security_expended_time,2,pass.id,pass.arrival_time));
                        pass.security_counter_time = event.time;
                        availableSecurity -= 1;
                    }else{
                        if(flightPriority){
                            securityQueue.push(make_pair(make_pair(-pass.flight_time,-pass.arrival_time) ,pass.id));
                        }else{
                            securityQueue.push(make_pair(make_pair(--stabilizer,0),pass.id));
                        }
                        
                    }
                }
                

                if(!luggageQueue.empty()){
                    auto  id = luggageQueue.top().second;
                    
                    luggageQueue.pop();
                    eventQueue.push(Event(event.time+passengers[id].luggage_expended_time,1,id,passengers[id].arrival_time));
                    passengers[id].luggage_counter_time=event.time;
                }else{
                    availableLuggage += 1;
                }
                
                break;
            case 2:
                if(!securityQueue.empty()){
                    auto id = securityQueue.top().second;
                    
                    securityQueue.pop();
                    eventQueue.push(Event(event.time+passengers[id].security_expended_time,2,id,passengers[id].arrival_time));
                    passengers[id].security_counter_time=event.time;
                }else{
                    availableSecurity += 1;
                }
                
                break;
        }
    }

    return passengers;
}
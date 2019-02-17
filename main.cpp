#include <iostream>
#include <fstream>
#include <vector>
#include "Model.h"
#include "Passenger.h"

using namespace std;
void calculateWaitTime(ofstream& out,vector<Passenger> passengerVector){
    double sum = 0;
    int count = 0;
    for (const auto& p : passengerVector){
        count += ((p.security_counter_time + p.security_expended_time) > p.flight_time);
        sum+=(p.security_counter_time+p.security_expended_time - p.arrival_time );
    }

    out<<(double)sum/passengerVector.size()<<" "<<count<<endl;
}

int main(int argc, char* argv[]) {

    if (argc != 3) {
        cout << "Run the code with the following command: ./project2 [input_file] [output_file]" << endl;
        return 1;
    }

    
    ifstream infile(argv[1]);
    ofstream outfile(argv[2]);
    
    
    int numberOfPassenger;
    int numberOfLuggageCounter;
    int numberOfSecurityCounter;
    
    infile 
        >> numberOfPassenger 
        >> numberOfLuggageCounter 
        >> numberOfSecurityCounter;
    vector<Passenger> passengers(numberOfPassenger);
    
    for(int i=0; i<numberOfPassenger; i++){
        
        char vip,luggage;
        passengers[i].id=i;
        
        infile 
            >> passengers[i].arrival_time 
            >> passengers[i].flight_time
            >> passengers[i].luggage_expended_time
            >> passengers[i].security_expended_time
            >> vip 
            >> luggage;

        passengers[i].vip = (vip == 'V');
        passengers[i].luggage = (luggage == 'L');

    }
    infile.close();
    
    Model case1(passengers,numberOfLuggageCounter,numberOfSecurityCounter,false,false,false);
    auto passengerVector = case1.simulate();
    calculateWaitTime(outfile,passengerVector);
    Model case2(passengers,numberOfLuggageCounter,numberOfSecurityCounter,false,false,true);
    passengerVector = case2.simulate();
    calculateWaitTime(outfile,passengerVector);
    Model case3(passengers,numberOfLuggageCounter,numberOfSecurityCounter,false,true,false);
    passengerVector = case3.simulate();
    calculateWaitTime(outfile,passengerVector);
    Model case4(passengers,numberOfLuggageCounter,numberOfSecurityCounter,false,true,true);
    passengerVector = case4.simulate();
    calculateWaitTime(outfile,passengerVector);
    Model case5(passengers,numberOfLuggageCounter,numberOfSecurityCounter,true,false,false);
    passengerVector = case5.simulate();
    calculateWaitTime(outfile,passengerVector);
    Model case6(passengers,numberOfLuggageCounter,numberOfSecurityCounter,true,false,true);
    passengerVector = case6.simulate();
    calculateWaitTime(outfile,passengerVector);
    Model case7(passengers,numberOfLuggageCounter,numberOfSecurityCounter,true,true,false);
    passengerVector = case7.simulate();
    calculateWaitTime(outfile,passengerVector);
    Model case8(passengers,numberOfLuggageCounter,numberOfSecurityCounter,true,true,true);
    passengerVector = case8.simulate();
    calculateWaitTime(outfile,passengerVector);
    



    return 0;
}

// https://replit.com/@soulmachine/AirlineCalculator#main.cpp

/*
You're building a tool to estimate the cost of various airplane tickets based on the airline, distance and seating class. Your tool must take in this information as a series of inputs (one ticket calculation per line of input) and produce a list of output costs.

Each airline contains its own cost requirements. Ultimately, the airline is only interested in two major components: the space you take on the plane, and the distance you fly. You must generate ticket costs using this gathered data:

Airlines: United, Delta, Southwest, LuigiAir

Operating Costs:

 - Economy:  No charge
 - Premium:  $25
 - Business: $50 + $0.25/mile

Per-Airline Prices:

 - Delta charges $0.50/mile
   + OperatingCost
   
 - United charges $0.75/mile
   + OperatingCost
   + $0.10/mile for Premium seats

 - Southwest charges $1.00/mile

 - LuigiAir charges $100 or 2 * OperatingCost, whichever is higher

Keep in mind that, while there are only four airlines listed above, your solution should be able to expand to dozens of individual airlines,  whose ticket cost can be based on arbitrary functions of "Operating Costs", miles, and/or seating class.

You can assume that the input will be provided as a list of strings and that there could be millions of lines of input. Each string will provide the Airline, Distance and Seating Class. Please review the examples below:

Example Input:
-------------------------------------------
United 150.0 Premium
Delta 60.0 Business
Southwest 1000.0 Economy
LuigiAir 50.0 Business
-------------------------------------------

Example Output:
-------------------------------------------
152.50
95.00
1000.00
125.00
-------------------------------------------

Explanation of Output:
-------------------------------------------
152.50      (150.0 * (0.75 + 0.10) + 25)
95.00       (60.0 * (0.50 + 0.25) + 50)
1000.00     (1000.0 * 1.00)
125.00      (100 <= 2 * (50 + 50 * 0.25))
-------------------------------------------
*/

// Factory pattern + Singlton pattern

#include <cassert>
#include<iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

enum Seat { Economy, Premium, Business};

enum Airline { Delta, United, SouthWest};

unordered_map<string, Airline> airlines {
  {"Delta", Delta}, 
  {"United", United}, 
  {"SouthWest", SouthWest}
};

unordered_map<string, Seat> seats  {
  {"Economy", Economy}, 
  {"Premium", Premium}, 
  {"Business",Business}
};

struct Ticket {
    Airline airline;
    Seat seat;
    float distance; // in miles
};

class AirlineCalculator{
public:
    // Factory pattern
    static AirlineCalculator* create(Airline airline);
    // Calculate total cost
    virtual float calculate(const Ticket& ticket) const = 0;
    virtual ~AirlineCalculator() = default;

protected:
    // Calculate operating cost
    virtual float getOpCost (Ticket ticket) const {
        float opCost = 0.;
        switch(ticket.seat) {
            case(Economy): 
                opCost = getEconomyOpCost(ticket.distance);
                break;
            case(Premium): 
                opCost = getPremiumOpCost(ticket.distance);
                break;
            case(Business):
                opCost = getBusinessOpCost(ticket.distance);
        }
        return opCost;
    }
    virtual float getEconomyOpCost (float d) const {
        return 0.0;
    }
    virtual float getPremiumOpCost (float d) const {
        return 25.0;
    }
    virtual float getBusinessOpCost (float d) const {
        return 50.0 + 0.25 * d;
    }
};

class DeltaCalculator:public AirlineCalculator{
public:
    float calculate(const Ticket& ticket) const override {
        float opCost = getOpCost(ticket);
        return opCost + ticket.distance * 0.5;
    }
    
    // Meyers' Singleton
    static AirlineCalculator* instance(){
        static DeltaCalculator calc;
        return &calc;
    }

    virtual ~DeltaCalculator() = default;
  
private:
    DeltaCalculator() = default;
};
 
class UnitedCalculator:public AirlineCalculator{
public:
    float calculate(const Ticket& ticket) const override {
        float opCost = getOpCost(ticket);
        return opCost + ticket.distance * 0.75;
    }
    
    static AirlineCalculator* instance(){
        static UnitedCalculator calc;
        return &calc;
    }

    virtual ~UnitedCalculator() = default;

private:
    UnitedCalculator() = default;

protected:
    float getPremiumOpCost(float d) const override {
        return 25. + 0.1 * d;
    }
};
 
class SouthwestCalculator:public AirlineCalculator{
public:
    
    float calculate(const Ticket& ticket) const override{
        return 1. * ticket.distance;
    }

    static AirlineCalculator* instance() {
        static SouthwestCalculator calc;
        return &calc;
    }

    virtual ~SouthwestCalculator() = default;

private:
    SouthwestCalculator() = default;
};
 
// Factory pattern
AirlineCalculator*  AirlineCalculator::create(Airline airline){
    switch(airline) {
        case Delta:
            // Singleton pattern
            return DeltaCalculator::instance();
        case United:
            // Singleton pattern
            return UnitedCalculator::instance();
        case SouthWest:
            // Singleton pattern
            return SouthwestCalculator::instance();
    }
}

static Ticket parse_ticket(const string& s) {
    // split by space
    vector<string> arr;
    std::stringstream ss(s);
    std::string token;
    while (std::getline(ss, token, ' ') ) {
        arr.push_back(token);
    }
    assert(arr.size()== 3);
    assert(airlines.count(arr[0]));
    assert(seats.count(arr[2]));

    Ticket ticket;
    ticket.airline = airlines[arr[0]];
    ticket.seat = seats[arr[2]];
    ticket.distance = std::stof(arr[1]);
    return ticket;
}
 
// unordered_map<string, AirlineCalculator*> airclcs{{"Delta",DeltaCalculator::instance()}, {"United",UnitedCalculator::instance()}, {"SouthWest",SouthwestCalculator::instance()}};

vector<float> process_tickets(vector<string> tickets){
    vector<float> costs;
    for(const string& ticket_str : tickets) {
        Ticket ticket = parse_ticket(ticket_str);
 
        AirlineCalculator* clc = AirlineCalculator::create(ticket.airline);
        costs.push_back(clc->calculate(ticket));
    }
    return costs;
}
 
int main() {
    vector<string> input{"United 150.0 Premium", "United 120.0 Economy","United 100.0 Business","Delta 60.0 Economy","Delta 60.0 Premium","Delta 60.0 Business", "SouthWest 1000.0 Economy", "SouthWest 4000.0 Economy"};
    vector<float> costs = process_tickets(input);
    for(int i = 0 ; i < input.size(); i++){
        cout << input[i] << " cost: $" << costs[i]<< endl;
    }
    return 0;
}
#include <iostream>
#include <vector>
#include <sstream>
#include <string>

#include "flight_ticket.h"

void parseTicketString(std::vector<std::string>& ticketElements, const std::string& ticketString) {
    std::stringstream ticketStream(ticketString);
    std::string stringToken;
    while(std::getline(ticketStream, stringToken, ' ')) {
        ticketElements.emplace_back(stringToken);
    }
}

int main() {
    std::vector<std::string> ticketInputs {
        "United 150.0 Premium", "United 120.0 Economy",
        "United 100.0 Business", "Delta 60.0 Economy",
        "Delta 60.0 Premium", "Delta 60.0 Business", 
        "SouthWest 1000.0 Economy", "SouthWest 4000.0 Economy",
        "SouthWest 4000.0 Economy hhhhhhhh", "LuigiAir 50.0 Business"
    };

    for (const auto& ticketString: ticketInputs) {
        std::vector<std::string> ticketElements;
        parseTicketString(ticketElements, ticketString);

        std::string airline = ticketElements[0];
        // std::transform(airline.begin(), airline.end(), airline.begin(), ::tolower);

        std::string seat = ticketElements[2];
        // std::transform(seat.begin(), seat.end(), seat.begin(), ::tolower);

        if (ticketElements.size() != 3)
            std::cout << "The ticket: " << ticketString << " is invalid." << std::endl;
        // Store lower case and match lower case
        else if (!airline::airlineMappings.count(airline))
            std::cout << "The airline: " << ticketElements[0] << " is currently not supported." << std::endl;
        
        else if (!airline::seatingClassMappings.count(seat))
            std::cout << "The seat: " << ticketElements[2] << " is invalid." << std::endl;

        else {
            airline::AirlineTicket airlineTicket(airline, seat, std::stof(ticketElements[1]));
            float ticketPrice = airline::AirlineTicketPricingSystem::getInstance(airlineTicket.airline)->caluclateTicketFare(airlineTicket);
            std::cout << "Price for the ticket: " << ticketString << " is: $" << ticketPrice << std::endl;
        }
    }

    return 0;
}
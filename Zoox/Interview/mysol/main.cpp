#include <iostream>
#include <unordered_map>
#include <vector>
#include <sstream>
#include <algorithm>

enum class SeatingClass {
    Economy, Premium, Business
};

enum class Airline {
    Delta, United, Southwest, LuigiAir
};

// const std::unordered_map<std::string, Airline> airlineMappings {
//     { "Delta", Airline::Delta },
//     { "United", Airline::United },
//     { "Southwest", Airline::Southwest },
//     { "LuigiAir", Airline::LuigiAir }
// };

const std::unordered_map<std::string, Airline> airlineMappings {
    { "delta", Airline::Delta },
    { "united", Airline::United },
    { "southwest", Airline::Southwest },
    { "luigiair", Airline::LuigiAir }
};

// const std::unordered_map<std::string, SeatingClass> seatingClassMappings {
//     { "Economy", SeatingClass::Economy },
//     { "Premium", SeatingClass::Premium },
//     { "Business", SeatingClass::Business }
// };

const std::unordered_map<std::string, SeatingClass> seatingClassMappings {
    { "economy", SeatingClass::Economy },
    { "premium", SeatingClass::Premium },
    { "business", SeatingClass::Business }
};

class AirlineTicket {
// private:
public:
    Airline airline;
    SeatingClass seatingClass;
    float travelDistance;
// public:
    AirlineTicket() = delete;

    AirlineTicket(std::string& str_airline, std::string& str_seatingClass, float distance)
        : airline(airlineMappings.at(str_airline)), seatingClass(seatingClassMappings.at(str_seatingClass)), travelDistance(distance) {}

};

class AirlineTicketPricingSystem {
public:
    static AirlineTicketPricingSystem* getInstance(const Airline& airline);

    float calculateAirlineOperationalCost(const AirlineTicket& airlineTicket) const {
        if (SeatingClass::Economy == airlineTicket.seatingClass)
            return 0.0;
        else if (SeatingClass::Premium == airlineTicket.seatingClass)
            return 25.0;
        else if (SeatingClass::Business == airlineTicket.seatingClass)
            return (50.0 + airlineTicket.travelDistance * 0.25);
        else
            return 0.0;
    }

    virtual float caluclateTicketFare(const AirlineTicket& airlineTicket) const = 0;
};

class DeltaAirlineTicketPricingSystem: public AirlineTicketPricingSystem {
private:
    DeltaAirlineTicketPricingSystem() = default;

public:
    static AirlineTicketPricingSystem* getInstance() {
        static DeltaAirlineTicketPricingSystem _instance;
        return &_instance;
    }

    virtual float caluclateTicketFare(const AirlineTicket& airlineTicket) const override {
        return 0.50 * airlineTicket.travelDistance + calculateAirlineOperationalCost(airlineTicket);
    }
};

class UnitedAirlineTicketPricingSystem: public AirlineTicketPricingSystem {
private:
    UnitedAirlineTicketPricingSystem() = default;

public:
    static AirlineTicketPricingSystem* getInstance() {
        static UnitedAirlineTicketPricingSystem _instance;
        return &_instance;
    }

    virtual float caluclateTicketFare(const AirlineTicket& airlineTicket) const override {
        return 0.75 * airlineTicket.travelDistance + calculateAirlineOperationalCost(airlineTicket) + 0.10 * airlineTicket.travelDistance * (SeatingClass::Premium == airlineTicket.seatingClass);
    }
};

class SouthwestAirlineTicketPricingSystem: public AirlineTicketPricingSystem {
private:
    SouthwestAirlineTicketPricingSystem() = default;

public:
    static AirlineTicketPricingSystem* getInstance() {
        static SouthwestAirlineTicketPricingSystem _instance;
        return &_instance;
    }

    virtual float caluclateTicketFare(const AirlineTicket& airlineTicket) const override {
        return 1 * airlineTicket.travelDistance;
    }
};

class LuigiAirAirlineTicketPricingSystem: public AirlineTicketPricingSystem {
private:
    LuigiAirAirlineTicketPricingSystem() = default;

public:
    static AirlineTicketPricingSystem* getInstance() {
        static LuigiAirAirlineTicketPricingSystem _instance;
        return &_instance;
    }

    virtual float caluclateTicketFare(const AirlineTicket& airlineTicket) const override {
        return std::max(100.0, 2.0 * calculateAirlineOperationalCost(airlineTicket));
    }
};

AirlineTicketPricingSystem* AirlineTicketPricingSystem::getInstance(const Airline& airline) {
    if (Airline::Delta == airline)
        return DeltaAirlineTicketPricingSystem::getInstance();
    else if (Airline::United == airline)
        return UnitedAirlineTicketPricingSystem::getInstance();
    else if (Airline::Southwest == airline)
        return SouthwestAirlineTicketPricingSystem::getInstance();
    else if (Airline::LuigiAir == airline)
        return LuigiAirAirlineTicketPricingSystem::getInstance();
    else
        return nullptr;
}

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
        std::transform(airline.begin(), airline.end(), airline.begin(), ::tolower);

        std::string seat = ticketElements[2];
        std::transform(seat.begin(), seat.end(), seat.begin(), ::tolower);

        if (ticketElements.size() != 3)
            std::cout << "The ticket: " << ticketString << " is invalid." << std::endl;
        // Store lower case and match lower case
        else if (!airlineMappings.count(airline))
            std::cout << "The airline: " << ticketElements[0] << " is currently not supported." << std::endl;
        
        else if (!seatingClassMappings.count(seat))
            std::cout << "The seat: " << ticketElements[2] << " is invalid." << std::endl;

        else {
            AirlineTicket airlineTicket(airline, seat, std::stof(ticketElements[1]));
            float ticketPrice = AirlineTicketPricingSystem::getInstance(airlineTicket.airline)->caluclateTicketFare(airlineTicket);
            std::cout << "Price for the ticket: " << ticketString << " is: $" << ticketPrice << std::endl;
        }
    }
}
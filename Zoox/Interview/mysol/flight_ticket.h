#ifndef FLIGHT_TICKTET_H_
#define FLIGHT_TICKTET_H_

#include <iostream>
#include <unordered_map>

namespace airline {

    enum class SeatingClass {
        Economy, Premium, Business
    };

    enum class Airline {
        Delta, United, Southwest, LuigiAir
    };

    const std::unordered_map<std::string, Airline> airlineMappings {
        { "Delta", Airline::Delta },
        { "United", Airline::United },
        { "Southwest", Airline::Southwest },
        { "LuigiAir", Airline::LuigiAir }
    };

    const std::unordered_map<std::string, SeatingClass> seatingClassMappings {
        { "Economy", SeatingClass::Economy },
        { "Premium", SeatingClass::Premium },
        { "Business", SeatingClass::Business }
    };

    class AirlineTicket {
    public:
        Airline airline;
        SeatingClass seatingClass;
        float travelDistance;

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
}

#endif
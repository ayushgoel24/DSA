#ifndef FLIGHT_TICKTET_H_
#define FLIGHT_TICKTET_H_

#include <iostream>
#include <unordered_map>

namespace zoox {

    inline void PrintTest() {
        std::cout << "Test hello world!!!\n";
    };

    enum class SeatLevel {
        Economy, Premium, Business
    };

    enum class Airline {
        Delta, United, SouthWest, LuigiAir
    };

    std::unordered_map<std::string, SeatLevel> seat_level_map_{
        {"Economy", SeatLevel::Economy},
        {"Premium", SeatLevel::Premium},
        {"Business", SeatLevel::Business}
    };

    const std::unordered_map<std::string, Airline> airline_map_{
    {"Delta", Airline::Delta},
    {"United", Airline::United},
    {"SouthWest", Airline::SouthWest},
    {"LuigiAir", Airline::LuigiAir}
    };

    struct FlightTicket {
        double distance;
        SeatLevel seat_level;
        Airline airline;
        FlightTicket() = delete;
        FlightTicket(const double dist, const std::string level_str, 
                    const std::string& airline_str) {
            distance = dist;
            seat_level = seat_level_map_.at(level_str);
            airline = airline_map_.at(airline_str);
        }
    };

    class FlightTicketSystem {
        public:
        static FlightTicketSystem* Instance(const Airline airline);

        double GetOperationCost(const FlightTicket& ticket) const {
            if (ticket.seat_level == SeatLevel::Economy) {
            return 0.0;
            } else if (ticket.seat_level == SeatLevel::Premium) {
            return 25.0;
            } else if (ticket.seat_level == SeatLevel::Business) {
            return 50.0 + ticket.distance*0.25;
            }
            return 0.0;
        }

        virtual double GetTicketPrice(const FlightTicket& ticket) const = 0;
    };

    class Delta : public FlightTicketSystem {
        public:
        static FlightTicketSystem* Instance() {
            if (!instance_) {
                instance_ = new Delta();
            }
            return instance_; 
        } 

        virtual double GetTicketPrice(const FlightTicket& ticket) const override {
            return GetOperationCost(ticket) + 0.5 * ticket.distance;
        }

        static Delta *instance_;
    };

    class United : public FlightTicketSystem {
        public:
        static United* Instance() {
            if (!instance_) {
                instance_ = new United();
            }
            return instance_; 
        } 

        double GetTicketPrice(const FlightTicket& ticket) const override {
            return GetOperationCost(ticket) + 0.75 * ticket.distance + 0.1 * ticket.distance
                * (ticket.seat_level == SeatLevel::Premium);
        }

        static United *instance_;
    };

    class SouthWest : public FlightTicketSystem {
        public:
        static SouthWest* Instance() {
            if (!instance_) {
            instance_ = new SouthWest();
            }
            return instance_; 
        } 
        
        double GetTicketPrice(const FlightTicket& ticket) const override {
            return 1.0 * ticket.distance;
    }

     static SouthWest *instance_;
    };

    class LuigiAir : public FlightTicketSystem {
    public:
    static LuigiAir* Instance() {
        if (!instance_) {
        instance_ = new LuigiAir();
        }
        return instance_; 
    } 

    double GetTicketPrice(const FlightTicket& ticket) const override {
        return std::max(100.0, GetOperationCost(ticket)*2.0);
    }

    static LuigiAir *instance_;
    };

    FlightTicketSystem* FlightTicketSystem::Instance(const Airline airline) {
        if (airline == Airline::Delta) {
        return Delta::Instance();
        } else if (airline == Airline::United) {
        return United::Instance();
        } else if (airline == Airline::SouthWest) {
        return SouthWest::Instance();
        } else if (airline == Airline::LuigiAir) {
        return LuigiAir::Instance();
        }
        return nullptr;
    }

    Delta* Delta::instance_ = nullptr;
    United* United::instance_ = nullptr;
    SouthWest* SouthWest::instance_ = nullptr;
    LuigiAir* LuigiAir::instance_ = nullptr;

} // namespace zoox

#endif
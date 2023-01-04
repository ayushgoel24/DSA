#include <iostream>
#include <vector>
#include <sstream>
#include <string>

#include "flight_ticket.h"

namespace zoox {

namespace {

constexpr int kTicketSize = 3;

}  // namespace

std::vector<std::string> ParseTicketString(const std::string& ticket) {
  std::vector<std::string> ticket_str;
  std::istringstream str_input(ticket);
  std::string cur_str;
  while (std::getline(str_input, cur_str, ' ')) {
    ticket_str.emplace_back(cur_str);
  }
  return ticket_str;
}

void RunMain() {
  PrintTest();

  std::vector<std::string> input_tickets
    {"United 150.0 Premium", "United 120.0 Economy",
     "United 100.0 Business", "Delta 60.0 Economy",
     "Delta 60.0 Premium", "Delta 60.0 Business", 
     "SouthWest 1000.0 Economy", "SouthWest 4000.0 Economy",
     "SouthWest 4000.0 Economy hhhhhhhh", "LuigiAir 50.0 Business"};   

  std::string::size_type sz; 
  for (const auto& ticket : input_tickets) {
    const std::vector<std::string> ticket_strs = ParseTicketString(ticket); 
    if (ticket_strs.size() != kTicketSize) {
      std::cout << "Illegal ticket " << ticket << std::endl;
    } else {
      const FlightTicket flight_ticket(std::stod(ticket_strs[1]),
           ticket_strs[2], ticket_strs[0]);
      const double price = 
        FlightTicketSystem::Instance(flight_ticket.airline)
         ->GetTicketPrice(flight_ticket);
      std::cout << "Ticket " << ticket << " 's cost " << price << std::endl;     
    }
  }
}

} // namespace zoox

int main() {
  zoox::RunMain();

  return 0;
}
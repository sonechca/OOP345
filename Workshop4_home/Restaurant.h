// Name: Mintae Kim
// Seneca Student ID: 141915181
// Seneca email: mkim221@myseneca.ca
// Date of completion: Oct 5, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_RESTAURANT_H
#define SDDS_RESTAURANT_H
#include <iostream>
#include "Reservation.h"
namespace sdds {
class Restaurant {
    Reservation* rev;
    size_t numOfReserv;
public:
    Restaurant();
    Restaurant(Reservation* reservations[], size_t cnt);
    Restaurant(const Restaurant& copy);
    Restaurant(Restaurant&& move);
    ~Restaurant();
    size_t size() const;
//    Restaurant& operator=(const Restaurant& cp);
//    Restaurant& operator=(Restaurant&& mv);
    friend std::ostream& operator<<(std::ostream& os, const Restaurant& res);
};
}
#endif /* Restaurant_hpp */

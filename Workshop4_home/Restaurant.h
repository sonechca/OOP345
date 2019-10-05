//
//  Restaurant.hpp
//  S3 Workshop 4 lab
//
//  Created by Mintae Kim on 2019-10-04.
//  Copyright © 2019 Mintae Kim. All rights reserved.
//

#ifndef SDDS_RESTAURANT_H
#define SDDS_RESTAURANT_H
#include <iostream>
#include "Reservation.h"
namespace sdds {
class Restaurant {
    Reservation* rev;
    size_t numOfReserv;
public:
    Restaurant(Reservation* reservations[], size_t cnt);
    Restaurant(const Restaurant& copy);
    size_t size() const;
    friend std::ostream& operator<<(std::ostream& os, const Restaurant& res);
};
}
#endif /* Restaurant_hpp */

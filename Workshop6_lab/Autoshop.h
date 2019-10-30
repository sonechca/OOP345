//
//  Autoshop.hpp
//  s3 Workshop6 lab
//
//  Created by Mintae Kim on 2019-10-29.
//  Copyright © 2019 Mintae Kim. All rights reserved.
//

#ifndef Autoshop_h
#define Autoshop_h
#include <iostream>
#include <vector>
#include "Vehicle.h"

namespace sdds {
class Autoshop {
    std::vector<Vehicle*> m_vehicles;
public:
    Autoshop& operator+=(Vehicle* theVehicle);
    void display(std::ostream& out) const;
    friend std::ostream& operator<<(std::ostream& os , const Autoshop& obj);
};
}

#endif /* Autoshop_hpp */

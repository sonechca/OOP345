//
//  Car.hpp
//  s3 Workshop6 lab
//
//  Created by Mintae Kim on 2019-10-29.
//  Copyright © 2019 Mintae Kim. All rights reserved.
//

#ifndef SDDS_CAR_H
#define SDDS_CAR_H

#include <fstream>
#include <iostream>
#include <string>
#include <locale>
#include <iomanip>
#include "Vehicle.h"
namespace sdds{
class Car : public Vehicle{
    std::string c_tag;
    std::string c_maker;
    std::string c_cond;
    double c_topSpeed;
public:
    Car(std::istream&);
    std::string condition() const;
    std::string makers() const;
    double topSpeed() const;
    void display(std::ostream& out) const;
    friend std::ostream& operator<<(std::ostream& os, const Car& obj);
};
}
#endif /* Car_hpp */

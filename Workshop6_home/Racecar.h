//
//  Racecar.hpp
//  s3 Workshop6 lab
//
//  Created by Mintae Kim on 2019-11-02.
//  Copyright © 2019 Mintae Kim. All rights reserved.
//

#ifndef Racecar_hpp
#define Racecar_hpp

#include "Car.h"
namespace sdds {
class Racecar : public Car {
    double m_booster;
public:
    Racecar(std::istream& in);
    void display(std::ostream& out) const;
    double topSpeed() const;
    friend std::ostream& operator<<(std::ostream& os, const Racecar& obj);
};
}
#endif /* Racecar_hpp */

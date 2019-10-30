//
//  Utilities.hpp
//  s3 Workshop6 lab
//
//  Created by Mintae Kim on 2019-10-29.
//  Copyright © 2019 Mintae Kim. All rights reserved.
//

#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H
#include <iostream>
#include <sstream>
#include "Car.h"
#include "Vehicle.h"

namespace sdds {

Vehicle* createInstance(std::istream& in);

}

#endif /* Utilities_hpp */

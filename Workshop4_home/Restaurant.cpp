//
//  Restaurant.cpp
//  S3 Workshop 4 lab
//
//  Created by Mintae Kim on 2019-10-04.
//  Copyright © 2019 Mintae Kim. All rights reserved.
//
#include <iostream>
#include "Restaurant.h"

namespace sdds {
Restaurant::Restaurant(Reservation* reservations[], size_t cnt){
    numOfReserv = cnt;
    rev = new Reservation[numOfReserv];
    for(size_t i = 0; i < numOfReserv; i++){
        rev[i] = *reservations[i];
    }
}
size_t Restaurant::size() const {
    return numOfReserv;
}
std::ostream& operator<<(std::ostream& os, const Restaurant& res){
        if(res.numOfReserv == 0){
            os << "--------------------------" << std::endl;
            os << "Fancy Restaurant" << std::endl;
            os << "--------------------------" << std::endl;
            os << "The object is empty!" << std::endl;
            os << "--------------------------" << std::endl;
        }
        else{
            os << "--------------------------" << std::endl;
            os << "Fancy Restaurant" << std::endl;
            os << "--------------------------" << std::endl;
            for(size_t i = 0; i < res.size(); i++){
                os << res.rev[i];
            }
            os << "--------------------------" << std::endl;
            
        }
    
    
    return os;
}
}

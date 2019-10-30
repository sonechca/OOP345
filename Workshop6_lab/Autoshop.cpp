//
//  Autoshop.cpp
//  s3 Workshop6 lab
//
//  Created by Mintae Kim on 2019-10-29.
//  Copyright © 2019 Mintae Kim. All rights reserved.
//

#include "Autoshop.h"
namespace sdds {
Autoshop& Autoshop::operator+=(Vehicle* theVehicle){
    m_vehicles.push_back(theVehicle);
    return *this;
}
void Autoshop::display(std::ostream& out) const {
    out << "--------------------------------" << std::endl;
    out << "| Cars in the autoshop!        |" << std::endl;
    out << "--------------------------------" << std::endl;
    for(auto elem : this->m_vehicles){
        elem->display(out);
        out << std::endl;
    }
    out << "--------------------------------" << std::endl;
}
std::ostream& operator<<(std::ostream& os, const Autoshop& obj) {
    obj.display(os);
    return os;
}
}

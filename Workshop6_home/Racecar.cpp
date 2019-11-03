//
//  Racecar.cpp
//  s3 Workshop6 lab
//
//  Created by Mintae Kim on 2019-11-02.
//  Copyright © 2019 Mintae Kim. All rights reserved.
//

#include "Racecar.h"
namespace sdds {
Racecar::Racecar(std::istream& in):Car::Car(in){
    char deli;
    in >> deli >> m_booster;
////    Car::setTag('r');
//    std::string carData = Car::getTempSpeed();
//    std::string tmpSpeed = "";
//
//    size_t speedField = carData.find(',') + 1;
//    tmpSpeed = carData.substr(0, speedField -1);
//    tmpSpeed.erase(0,tmpSpeed.find_first_not_of(" "));
//    tmpSpeed.erase(tmpSpeed.find_last_not_of(" ") + 1);
//    Car::setTempSpeed(tmpSpeed);
//
//    size_t boostField = carData.length();
//    try{
//        m_booster = std::stod(carData.substr(speedField, boostField - speedField));
//    }catch(...){
//        throw "Invalid record!";
//    }
    
    
    
}

void Racecar::display(std::ostream &out) const {
    Car::display(out);
    if(m_booster){
        out << "*";
    }
}

double Racecar::topSpeed() const{
    return Car::topSpeed() * (1+m_booster);
}

std::ostream& operator<<(std::ostream& os, const Racecar& obj){
    obj.display(os);
    return os;
}
}

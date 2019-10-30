//
//  Car.cpp
//  s3 Workshop6 lab
//
//  Created by Mintae Kim on 2019-10-29.
//  Copyright © 2019 Mintae Kim. All rights reserved.
//

#include "Car.h"
namespace sdds {
Car::Car(std::istream& is){
    bool valid = true;
    std::string tmp = "";
    std::getline(is, tmp);
    size_t fieldOfTag = tmp.find(',');
    c_tag = tmp.substr(0, fieldOfTag);
    c_tag.erase(0,c_tag.find_first_not_of(" "));
    c_tag.erase(c_tag.find_last_not_of(" ") + 1);
    if(c_tag != "C" || c_tag != "c"){
        valid = false;
    }
        
    
    size_t fieldOfMaker = tmp.find(',', fieldOfTag + 1);
    c_maker = tmp.substr(fieldOfTag + 1, fieldOfMaker - fieldOfTag - 1);
    c_maker.erase(0, c_maker.find_first_not_of(" "));
    c_maker.erase(c_maker.find_last_not_of(" ") + 1);
    
    size_t fieldOfCondition = tmp.find(',', fieldOfMaker + 1);
    c_cond = tmp.substr(fieldOfMaker + 1, fieldOfCondition - fieldOfMaker - 1);
    c_cond.erase(0, c_cond.find_first_not_of(" "));
    c_cond.erase(c_cond.find_last_not_of(" ") + 1);
    if(c_cond != "n" || c_cond != "u" || c_cond != "b")
        valid = false;
    
    size_t fieldOfSpeed = tmp.length();
    c_topSpeed = std::stod(tmp.substr(fieldOfCondition + 1, fieldOfSpeed - fieldOfCondition - 1));
    if(!isdigit(c_topSpeed))
        valid = false;
    
}
std::string Car::condition() const {
    std::string tmp = "";
    if(c_cond == "n")
        tmp = "new";
    else if(c_cond == "u")
        tmp = "used";
    else if(c_cond == "b")
        tmp = "broken";
    
    return tmp;
}
std::string Car::makers() const {
    return c_maker;
}
double Car::topSpeed() const {
    return c_topSpeed;
}
void Car::display(std::ostream& out) const {
    out << "| " << std::setw(10) << makers() << " | " << std::setw(6) << condition() << " | " << std::setw(6) << std::fixed << std::setprecision(2) << topSpeed() << " |";
}
std::ostream& operator<<(std::ostream& os, const Car& obj){
    obj.display(os);
    return os;
}
}

// Name: Mintae Kim
// Seneca Student ID: 141915181
// Seneca email: mkim221@myseneca.ca
// Date of completion: Oct 31, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include "Car.h"
namespace sdds {
Car::Car(std::istream& is) {
    std::string tmpCond;
    
    std::getline(is, c_maker, ',');
    c_maker.erase(0, c_maker.find_first_not_of(" "));
    c_maker.erase(c_maker.find_last_not_of(" ") + 1);
    
    std::getline(is, tmpCond, ',');
    tmpCond.erase(0, tmpCond.find_first_not_of(" "));
    tmpCond.erase(tmpCond.find_last_not_of(" ") + 1);
    if(tmpCond.length() == 0){
        c_cond = "new";
    }
    else {
        switch(tmpCond[0]) {
            case 'n':
                c_cond = "new";
                break;
            case 'u':
                c_cond = "used";
                break;
            case 'b':
                c_cond = "broken";
                break;
            default:
                throw "Invalid record!";
        }
    }
    
    is >> c_topSpeed;
    if(is.fail()){
        throw "Invalid record!";
    }
//    std::string tmp;
//    std::getline(is, tmp, '\n');
//    // find the tag
//    size_t fieldOfTag = tmp.find(',');
//    c_tag = tmp.substr(0, fieldOfTag);
//    c_tag.erase(0, c_tag.find_first_not_of(" "));
//    c_tag.erase(c_tag.find_last_not_of(" ") + 1);
//
//    // find the maker
//    size_t fieldOfMaker = tmp.find(',', fieldOfTag + 1);
//    c_maker = tmp.substr(fieldOfTag + 1, fieldOfMaker - fieldOfTag - 1);
//    c_maker.erase(0, c_maker.find_first_not_of(" "));
//    c_maker.erase(c_maker.find_last_not_of(" ") + 1);
//
//    //find the condition
//    size_t fieldOfCondition = tmp.find(',', fieldOfMaker + 1);
//    c_cond = tmp.substr(fieldOfMaker + 1, fieldOfCondition - fieldOfMaker - 1);
//    c_cond.erase(0, c_cond.find_first_not_of(" "));
//    c_cond.erase(c_cond.find_last_not_of(" ") + 1);
//    try{
//        if(c_cond == ""){
//            c_cond = "n";
//        }
//        else if(c_cond != "n" && c_cond != "u" && c_cond != "b"){
//            throw "Invalid record!";
//        }
//    }catch (...){
//        throw "Invalid record!";
//    }
//
//    //find the speed
//    size_t fieldOfSpeed = tmp.find('\n', fieldOfCondition + 1);
//    double tmp_speed;
//    try{
//        tmp_speed = std::stod(tmp.substr(fieldOfCondition + 1, fieldOfSpeed - fieldOfCondition - 1));
//        c_topSpeed = tmp.substr(fieldOfCondition + 1, fieldOfSpeed - fieldOfCondition - 1);
//        c_topSpeed.erase(0, c_cond.find_first_not_of(" "));
//
//    }catch(...){
//        throw "Invalid record!";
//    }
    
}
// check the condition value and return the full value for printing
std::string Car::condition() const {
    return c_cond;
//    std::string tmp = "";
//    if(c_cond == "n")
//        tmp = "new";
//    else if(c_cond == "u")
//        tmp = "used";
//    else if(c_cond == "b")
//        tmp = "broken";
//    else if(c_cond == "")
//        tmp = "new";
//    return tmp;
}

std::string Car::makers() const {
    return c_maker;
}
double Car::topSpeed() const {
    return c_topSpeed;
}

void Car::display(std::ostream& out) const {
    out << "| " << std::setw(10) << makers() << " | " << std::left << std::setw(6) << condition() << std::right << " | " << std::setw(6) << std::fixed << std::setprecision(2) << topSpeed() << " |";
}
std::ostream& operator<<(std::ostream& os, const Car& obj){
    obj.display(os);
    return os;
}
//double Car::getTempSpeed() const{
//    return c_topSpeed;
//}
//void Car::setTempSpeed(std::string tmp){
//    c_topSpeed = tmp;
//}
//void Car::setTag(char t){
//    c_tag = t;
//}
//char Car::getTag() const {
//    return c_tag;
//}
}

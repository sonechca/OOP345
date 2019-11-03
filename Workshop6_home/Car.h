// Name: Mintae Kim
// Seneca Student ID: 141915181
// Seneca email: mkim221@myseneca.ca
// Date of completion: Oct 31, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_CAR_H
#define SDDS_CAR_H

#include <sstream>
#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>
#include "Vehicle.h"
namespace sdds{
class Car : public Vehicle{
    std::string c_tag;
    std::string c_maker;
    std::string c_cond;
    double c_topSpeed;
public:
    Car(std::istream&) ;
    std::string condition() const;
    std::string makers() const;
//    std::string getTempSpeed() const;
//    void setTag(char tag);
//    char getTag() const;
//    void setTempSpeed(std::string tmp);
    double topSpeed() const;
    void display(std::ostream& out) const;
    friend std::ostream& operator<<(std::ostream& os, const Car& obj);
};
}
#endif /* Car_hpp */

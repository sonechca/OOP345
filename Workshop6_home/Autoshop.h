// Name: Mintae Kim
// Seneca Student ID: 141915181
// Seneca email: mkim221@myseneca.ca
// Date of completion: Oct 31, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_AUTOSHOP_H
#define SDDS_AUTOSHOP_H
#include <iostream>
#include <vector>
#include <list>
#include "Vehicle.h"

namespace sdds {
class Autoshop {
    std::vector<Vehicle*> m_vehicles;
public:
    Autoshop& operator+=(Vehicle* theVehicle);
    void display(std::ostream& out) const;
    ~Autoshop();
    template<typename T>
    void select(T test, std::list<const Vehicle*>& vehicles){
        for(auto it = m_vehicles.begin(); it != m_vehicles.end(); it++){
            if(test(*it)){
                vehicles.push_back(*it);
            }
        }
    }
    friend std::ostream& operator<<(std::ostream& os , const Autoshop& obj);
};
}

#endif /* Autoshop_hpp */

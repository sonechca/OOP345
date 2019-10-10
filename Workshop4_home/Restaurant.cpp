// Name: Mintae Kim
// Seneca Student ID: 141915181
// Seneca email: mkim221@myseneca.ca
// Date of completion: Oct 5, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include <iostream>
#include "Restaurant.h"

namespace sdds {
Restaurant::Restaurant(){
    rev = nullptr;
    numOfReserv = 0;
}
Restaurant::Restaurant(Reservation* reservations[], size_t cnt){

        numOfReserv = cnt;
           rev = new Reservation[numOfReserv]; //dynamic allocated array for saving reservaton
           for(size_t i = 0; i < numOfReserv; i++){
               rev[i] = *reservations[i];
           }
    
   
}
Restaurant::Restaurant(const Restaurant& copy){
    if(this != &copy){
        numOfReserv = copy.numOfReserv;
        if(copy.rev != nullptr){
            rev = new Reservation[numOfReserv];
            for(size_t i = 0; i < numOfReserv; i++){
                rev[i] = copy.rev[i];
            }
        }
        else{
            rev = nullptr;
        }
    }
}
Restaurant::Restaurant(Restaurant&& move){
    numOfReserv = move.numOfReserv;
    move.numOfReserv = 0;
    rev = move.rev;
    move.rev = nullptr;
}
Restaurant::~Restaurant(){ // destructor
    delete [] rev;
}
size_t Restaurant::size() const {
    return numOfReserv; // return size of reservation
}

//Restaurant& Restaurant::operator=(const Restaurant &cp){ // copy operator
//    if(this != &cp){
//        numOfReserv = cp.numOfReserv;
//        delete [] rev;
//        if(cp.rev != nullptr){
//            rev = new Reservation[numOfReserv];
//            for(size_t i = 0; i < numOfReserv; i++){
//                rev[i] = cp.rev[i];
//            }
//        }
//        else{
//            rev = nullptr;
//        }
//    }
//    return *this;
//}
//Restaurant& Restaurant::operator=(Restaurant&& mv){ // move operator
//    if(this != &mv){
//        numOfReserv = mv.numOfReserv;
//        mv.numOfReserv = 0;
//        rev = mv.rev;
//        mv.rev = nullptr;
//    }
//    return *this;
//}

std::ostream& operator<<(std::ostream& os, const Restaurant& res){
        os << "--------------------------" << std::endl
            << "Fancy Restaurant" << std::endl
            << "--------------------------" << std::endl;
        if(res.numOfReserv == 0){
            os << "The object is empty!" << std::endl;
        }
        else{
            for(size_t i = 0; i < res.numOfReserv; i++){
                os << res.rev[i];
            }
        }
        os << "--------------------------" << std::endl;
    
    return os;
}
}

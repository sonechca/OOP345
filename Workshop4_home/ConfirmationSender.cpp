// Name: Mintae Kim
// Seneca Student ID: 141915181
// Seneca email: mkim221@myseneca.ca
// Date of completion: Oct 5, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include <iostream>
#include "ConfirmationSender.h"

namespace sdds {
ConfirmationSender::ConfirmationSender(){
    revPointer = nullptr;
    numOfConfirm = 0;
}
ConfirmationSender::ConfirmationSender(const ConfirmationSender& copy){
    numOfConfirm = copy.numOfConfirm;
    if(numOfConfirm > 0){
        revPointer = const_cast<const Reservation**>(new Reservation*[numOfConfirm]); // dynamic allocated with const cast
        for(size_t i = 0; i < numOfConfirm; i++){
            revPointer[i] = copy.revPointer[i];
        }
    }
    else{
        revPointer = nullptr;
    }
}
ConfirmationSender::ConfirmationSender(ConfirmationSender&& move){
    revPointer = move.revPointer;
    numOfConfirm = move.numOfConfirm;
    move.revPointer = nullptr;
    move.numOfConfirm = 0;
}
ConfirmationSender::~ConfirmationSender(){
    delete [] revPointer;
}

ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res){
    bool existed = true;
    
    for(size_t i = 0; i < numOfConfirm && existed; i++){
        if(revPointer[i] == &res){ // compare existed array with &res
            existed = false; // operator does nothing
        }
    }
    
    if(existed) {
        Reservation** tmp = new Reservation*[numOfConfirm+1]; // dynamic allocate in temporary
        for(size_t i = 0; i < numOfConfirm; i++){
            tmp[i] = const_cast<Reservation*>(revPointer[i]); // copy the value using const cast
        }
        delete [] revPointer; // deallocate original variable
        revPointer = const_cast<const Reservation**>(tmp);
        revPointer[numOfConfirm++] = &res;
    }
    

    return *this;
}
ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res){
    bool existed = true;
    size_t i = 0;
    for(; i < numOfConfirm && existed; i++){ // compare existed array with &res
        if(revPointer[i] == &res){
            existed = false;
        }
    }
    
    if(!existed) { // if value is in the original array
        Reservation** tmp = new Reservation*[numOfConfirm--];
        if( i > 0){
            for(size_t j = 0; j < i; j++){ //copy the value before the existed value
                tmp[j] = const_cast<Reservation*>(revPointer[j]);
            }
        }
        for(size_t j = i; j< numOfConfirm; j++){ // copy after existed value
            tmp[j] = const_cast<Reservation*>(revPointer[j + 1]);
        }
        delete [] revPointer;
        revPointer = const_cast<const Reservation**>(tmp);
    }
    return *this;
}

ostream& operator<<(ostream& os, const ConfirmationSender& con){
        os << "--------------------------" << std::endl;
        os << "Confirmations to Send" << std::endl;
        os << "--------------------------" << std::endl;
    if(con.numOfConfirm == 0){
        os << "The object is empty!" << std::endl;
    }
    else{
        for(size_t i = 0; i < con.numOfConfirm; i++){
            os << *con.revPointer[i];
        }
    }
    os << "--------------------------" << std::endl;
    return os;
}
}

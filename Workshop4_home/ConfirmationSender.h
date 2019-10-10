// Name: Mintae Kim
// Seneca Student ID: 141915181
// Seneca email: mkim221@myseneca.ca
// Date of completion: Oct 5, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_CONFIRMATIONSENDER_H
#define SDDS_CONFIRMATIONSENDER_H

#include <iostream>
#include "Restaurant.h"
#include "Reservation.h"
namespace sdds {
class ConfirmationSender{
    const Reservation** revPointer;
    size_t numOfConfirm;
public:
    ConfirmationSender();
    ConfirmationSender(const ConfirmationSender& copy);
    ConfirmationSender(ConfirmationSender&& move);
    ~ConfirmationSender();
    ConfirmationSender& operator+=(const Reservation& res);
    ConfirmationSender& operator-=(const Reservation& res);
    friend std::ostream& operator<<(std::ostream& os, const ConfirmationSender& con);
};
}

#endif /* ConfirmationSender_hpp */

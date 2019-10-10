// Name: Mintae Kim
// Seneca Student ID: 141915181
// Seneca email: mkim221@myseneca.ca
// Date of completion: Oct 5, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_RESERVATION_H
#define SDDS_RESERVATION_H

#include <iostream>
#include <string>
using namespace std;

namespace sdds {
    class Reservation{
        string res_id;
        string res_name;
        string res_email;
        size_t res_num;
        int p_day;
        int p_hour;
    public:
        Reservation();
        Reservation(const std::string& m_res);
        friend ostream& operator<<(ostream& os,const Reservation& obj);
    };
}

#endif /* Reservation_hpp */

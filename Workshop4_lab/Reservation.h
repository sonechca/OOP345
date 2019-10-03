//
//  Reservation.hpp
//  S3 Workshop 4 lab
//
//  Created by Mintae Kim on 2019-10-02.
//  Copyright © 2019 Mintae Kim. All rights reserved.
//

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
        int p_time;
    public:
        Reservation();
        Reservation(const std::string& m_res);
        friend ostream& operator<<(ostream& os,const Reservation& obj);
    };
}

#endif /* Reservation_hpp */

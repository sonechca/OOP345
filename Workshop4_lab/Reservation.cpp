#include <iostream>
#include <iomanip>
#include <cstring>
#include "Reservation.h"
using namespace std;

namespace sdds {
    Reservation::Reservation(){
        res_id = "";
        res_name = "";
        res_email = "";
        res_num = 0;
        p_day = 0;
        p_time = 0;
    }
    Reservation::Reservation(const std::string& m_res){
        size_t id_fieldEnd = m_res.find(':'); // 8
        size_t name_fieldEnd = m_res.find(','); // 18
        size_t email_fieldEnd = m_res.find(',',name_fieldEnd + 1); // 37
        size_t num_fieldEnd = m_res.find(',', email_fieldEnd + 1); // 50
        auto day_fieldEnd = m_res.find(',', num_fieldEnd + 1); // 55
        auto time_fieldEnd = m_res.length(); // end of line
        res_id = m_res.substr(0,id_fieldEnd); // get string from id_field
        res_name = m_res.substr(id_fieldEnd+1,name_fieldEnd - id_fieldEnd - 1);
        res_name.erase(remove(res_name.begin(),res_name.end(), ' '), res_name.end());
        res_email = m_res.substr(name_fieldEnd+1,email_fieldEnd - name_fieldEnd - 1);
        res_email.erase(remove(res_email.begin(), res_email.end(), ' '), res_email.end());
        res_email.append(">");
        res_num = stoi(m_res.substr(email_fieldEnd + 1, num_fieldEnd - email_fieldEnd - 1));
        p_day = stoi(m_res.substr(num_fieldEnd + 1, day_fieldEnd - num_fieldEnd - 1));
        p_time = stoi(m_res.substr(day_fieldEnd + 1, time_fieldEnd - day_fieldEnd - 1));
        
    }
    ostream& operator<<(ostream& os,const Reservation& obj){
        string tmp;
        if(obj.p_time >= 6 && obj.p_time <= 9)
            tmp = "Breakfast on day";
        else if(obj.p_time >= 11 && obj.p_time <= 15)
            tmp = "Lunch on day";
        else if(obj.p_time >= 17 && obj.p_time <= 21)
            tmp = "Dinner on day";
        else
            tmp = "Drinks on day";
            
        os << "Reservation" <<  obj.res_id << setw(11)  << right <<  obj.res_name << "  <" << setw(23) << left << obj.res_email << tmp << " " << obj.p_day << " @ " << obj.p_time << ":00 for " << obj.res_num << endl;
        return os;
    }
}

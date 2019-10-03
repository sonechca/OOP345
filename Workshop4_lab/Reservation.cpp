// Name: Mintae Kim
// Seneca Student ID: 141915181
// Seneca email: mkim221@myseneca.ca
// Date of completion: Oct 3, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include "Reservation.h"
using namespace std;

namespace sdds {
    Reservation::Reservation(){ //default constructor
        res_id = "";
        res_name = "";
        res_email = "";
        res_num = 0;
        p_day = 0;
        p_hour = 0;
    }
    Reservation::Reservation(const std::string& m_res){
        auto id_fieldEnd = m_res.find(':') + 1; // value is 9
        auto name_fieldEnd = m_res.find(','); // value is 18
        auto email_fieldEnd = m_res.find(',',name_fieldEnd + 1); // value is 37
        auto num_fieldEnd = m_res.find(',', email_fieldEnd + 1); // value is 50
        auto day_fieldEnd = m_res.find(',', num_fieldEnd + 1); // values is 55
        auto time_fieldEnd = m_res.length(); // end of line
        res_id = m_res.substr(0,id_fieldEnd); // get string from id_field
        res_id.erase(remove(res_id.begin(), res_id.end(), ' '), res_id.end()); // remove the ' '
        res_name = m_res.substr(id_fieldEnd+1,name_fieldEnd - id_fieldEnd - 1); // get string between res_id and res_name field
        res_name.erase(remove(res_name.begin(),res_name.end(), ' '), res_name.end()); //remove the ' '
        res_email = m_res.substr(name_fieldEnd+1,email_fieldEnd - name_fieldEnd - 1); // get string betwwen res_name and res_email field
        res_email.erase(remove(res_email.begin(), res_email.end(), ' '), res_email.end()); // remove the ' '
        res_email.append(">"); // append the > for print out
        res_num = stoi(m_res.substr(email_fieldEnd + 1, num_fieldEnd - email_fieldEnd - 1)); // get interger of people number number using stoi
        p_day = stoi(m_res.substr(num_fieldEnd + 1, day_fieldEnd - num_fieldEnd - 1)); // get interger of day number number using stoi
        p_hour = stoi(m_res.substr(day_fieldEnd + 1, time_fieldEnd - day_fieldEnd - 1)); // get interger of hour(time) number number using stoi
        
    }
    ostream& operator<<(ostream& os,const Reservation& obj){
        // Condition - Check the time and put proper string in tmp;
        string tmp;
        if(obj.p_hour >= 6 && obj.p_hour <= 9)
            tmp = "Breakfast on day";
        else if(obj.p_hour >= 11 && obj.p_hour <= 15)
            tmp = "Lunch on day";
        else if(obj.p_hour >= 17 && obj.p_hour <= 21)
            tmp = "Dinner on day";
        else
            tmp = "Drinks on day";
        // Print ID:NAME,EMAIL,PARTY SIZE,DAY,HOUR
        os << "Reservation " <<  obj.res_id << setw(11)  << right <<  obj.res_name << "  <" << setw(23) << left << obj.res_email << tmp << " " << obj.p_day << " @ " << obj.p_hour << ":00 for " << obj.res_num << " people." << endl;
        return os;
    }
}

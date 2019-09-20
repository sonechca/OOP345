// Name: Mintae Kim
// Seneca Student ID: 141915181
// Seneca email: mkim221@myseneca.ca
// Date of completion: Sept 19, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include <iostream>
#include <chrono>
#include <iomanip>
#include "TimedEvents.h"
namespace sdds {
    //Default constructor
    TimedEvents::TimedEvents(): start_time{}
    , end_time{}{
        
    }
    
    //Check the Start time when call startClock() function
    void TimedEvents::startClock(){
        start_time = std::chrono::steady_clock::now();
    }
    
    //Check the End time when call stopClock() function
    void TimedEvents::stopClock(){
        end_time = std::chrono::steady_clock::now();
    }
    
    //Record event with struct array
    void TimedEvents::recordEvent(const char* str){
        arrayRecords[numOfRecordStored].event_name = str;
        arrayRecords[numOfRecordStored].units_time = "nanoseconds";
        arrayRecords[numOfRecordStored].dur_time= end_time - start_time;
        numOfRecordStored++;
    }
    
    //Friend output operator
    std::ostream& operator <<(std::ostream& os, TimedEvents& obj){
        os << "--------------------------" << std::endl;
        os << "Execution Times:" <<std::endl;
        os << "--------------------------" << std::endl;
        for(int i = 0; i < obj.numOfRecordStored; i++){
            // used duration_cast for change nanoseconds
            os << std::left << std::setw(20) << obj.arrayRecords[i].event_name << " " << std::right << std::setw(12) << std::chrono::duration_cast<std::chrono::nanoseconds>(obj.arrayRecords[i].dur_time).count() << " " << obj.arrayRecords[i].units_time << std::endl;
        }
        os << "--------------------------" << std::endl;
        return os;
    }
}

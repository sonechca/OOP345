// Name: Mintae Kim
// Seneca Student ID: 141915181
// Seneca email: mkim221@myseneca.ca
// Date of completion: Sept 22, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_TIMEDEVENTS_H
#define SDDS_TIMEDEVENTS_H
#include <iostream>
#include <chrono>
#include <string>
#define MAXIMUM_RECORD_OBJECTS 7

namespace sdds {
    class TimedEvents {
        int numOfRecordStored = 0;
        std::chrono::steady_clock::time_point start_time;
        std::chrono::steady_clock::time_point end_time;
        struct {
            std::string event_name;
            std::string units_time;
            std::chrono::steady_clock::duration dur_time;
        }arrayRecords[MAXIMUM_RECORD_OBJECTS];
    
    public:
        TimedEvents();
        void startClock();
        void stopClock();
        void recordEvent(const char* str);
        friend std::ostream& operator <<(std::ostream& os, TimedEvents& obj);
    };
    
}

#endif

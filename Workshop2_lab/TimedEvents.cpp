#include <iostream>
#include <chrono>
#include <iomanip>
#include <utility>
#include "TimedEvents.h"
namespace sdds {

    TimedEvents::TimedEvents(): start_time{}
    , end_time{}{
        
    }
    void TimedEvents::startClock(){
        start_time = std::chrono::steady_clock::now();
    }
    void TimedEvents::stopClock(){
        end_time = std::chrono::steady_clock::now();
    }
    void TimedEvents::recordEvent(const char* str){
        arrayRecords[numOfRecordStored].event_name = str;
        arrayRecords[numOfRecordStored].dur_time= end_time - start_time;
    }
    std::ostream& operator <<(std::ostream& os, TimedEvents& obj){
        os << "Execution Times:" <<std::endl;
        for(int i = 0; i < obj.numOfRecordStored; i++){
            os << "--------------------------" << std::endl;
            os << obj.arrayRecords[i].event_name << " " << std::chrono::duration_cast<std::chrono::nanoseconds>(obj.arrayRecords[i].dur_time).count() << " " <<  obj.arrayRecords[i].units_time << std::endl;
            os << "--------------------------" << std::endl;
        }
        return os;
    }
}

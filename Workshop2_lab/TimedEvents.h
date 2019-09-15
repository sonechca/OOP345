//
//  TimedEvents.h
//  S3 Workshop2_lab
//
//  Created by Mintae Kim on 2019-09-15.
//  Copyright © 2019 Mintae Kim. All rights reserved.
//

#ifndef SDDS_TimedEvents_H
#define SDDS_TimedEvents_H
#include <iostream>
#include <chrono>
#include <string>
#define MAXIMUM_RECORD_OBJECTS 7

namespace sdds {
    class TimedEvents {
        static int numOfRecordStored;
        std::chrono::steady_clock::time_point start_time;
        std::chrono::steady_clock::time_point end_time;
        struct {
            const char* event_name;
            const char* units_time;
            std::chrono::steady_clock::duration dur_time;
        };
    public:
        TimedEvents();
        void startClock();
        void stopClock();
        void recordEvent(const char* str);
        friend std::ostream operator <<(std::ostream& os, TimedEvents& obj);
    };
    
}

#endif

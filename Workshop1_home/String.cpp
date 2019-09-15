#include <iostream>
#include <cstring>
#include "String.h"

namespace sdds {
    unsigned int g_maxSize = 3; //Extern definition
    
    String::String(const char* str) {
        if (str != nullptr && str[0] != '\0') { //check the str address
            s_str = new char[g_maxSize+1]; // dynamic allocated memory
            strncpy(s_str, str, g_maxSize); // copy the string from parameter
            s_str[g_maxSize] = '\0'; // locate null-terminator
        }
        else {
            s_str = nullptr;
        }
    }
    
    void String::display(std::ostream& os) const {
        os << s_str;
    }
    std::ostream& operator<<(std::ostream& os, const String& obj) {
        static int count; // static value: initializing one time
        count++; // add 1 when call this operator
        os << count << ":" ;
        obj.display(os); 
        return os;
    }
}

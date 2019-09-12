#include <iostream>
#include <cstring>
#include "String.h"

namespace sdds {
    unsigned int g_maxSize = 3;
    
    String::String(const char* str) {
        if (str != nullptr && str[0] != '\0') {
            strncpy(m_string, str, 3);
            m_string[3] = '\0';
        }
        else {
            m_string[0] = '\0';
        }
    }
    
    void String::display(std::ostream& os) const {
        os << m_string;
    }
    std::ostream& operator<<(std::ostream& os, const String& obj) {
        static int count = 0;
        count++;
        os << count << ":" ;
        obj.display(os);
        return os;
    }
}

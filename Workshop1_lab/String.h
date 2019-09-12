
#ifndef SDDS_STRING_H
#define SDDS_STRING_H
#include <iostream>
namespace sdds {
    extern unsigned int g_maxSize;
    class String {
        char m_string[4];
    public:
        String(const char* str);
        void display(std::ostream& os) const;
    };
    std::ostream& operator<<(std::ostream& os, const String& obj);
}

#endif // !_STRING_H

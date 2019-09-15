
#ifndef SDDS_STRING_H
#define SDDS_STRING_H
#include <iostream>
namespace sdds {
    extern unsigned int g_maxSize; //Extern declaration
    class String {
        char* s_str; // use char pointer for dynamic dynamic allocated memory
    public:
        String(const char* str);// constructor with an argument
        void display(std::ostream& os) const; //display member value using ostream
    };
    std::ostream& operator<<(std::ostream& os, const String& obj); // Help function for using ostream
}

#endif // !_STRING_H

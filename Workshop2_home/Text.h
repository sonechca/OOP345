// Name: Mintae Kim
// Seneca Student ID: 141915181
// Seneca email: mkim221@myseneca.ca
// Date of completion: Sept 19, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_TEXT_H
#define SDDS_TEXT_H
#include <string>
namespace sdds {
    class Text {
        unsigned int numOfRecord; //count the words in file
        std::string* f_name; //string pointer for using dynamic allocated memory
        
    public:
        Text();
        Text(const char* name);
        Text(const Text& copy);
        Text(Text&& move);
        Text& operator=(const Text& copy);
        Text& operator=(Text&& move);
        ~Text();
        size_t size() const;
    };
}

#endif /* Text_h */

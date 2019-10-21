// Name: Mintae Kim
// Seneca Student ID: 141915181
// Seneca email: mkim221@myseneca.ca
// Date of completion: Oct 17, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_SPELLCHECKER_H
#define SDDS_SPELLCHECKER_H

#include <iostream>
namespace sdds{
class SpellChecker {
    std::string m_badWords[5];
    std::string  m_goodWords[5];
public:
    SpellChecker(const char* filename);
    void operator()(std::string& text) const;
};
}
#endif /* SpellChecker_hpp */

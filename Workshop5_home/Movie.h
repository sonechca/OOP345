// Name: Mintae Kim
// Seneca Student ID: 141915181
// Seneca email: mkim221@myseneca.ca
// Date of completion: Oct 17, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H

#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
namespace sdds{
class Movie {
    std::string titles;
    size_t yearOfRlease;
    std::string desc;
public:
    Movie();
    const std::string& title() const;
    Movie(const std::string& strMovie);
    template <typename T>
    void fixSpelling(T spellChecker){
        spellChecker(titles);
        spellChecker(desc);
    }
    friend std::ostream& operator<<(std::ostream& os, const Movie& obj);
};
}

#endif /* Movie_hpp */

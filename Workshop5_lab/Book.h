// Name: Mintae Kim
// Seneca Student ID: 141915181
// Seneca email: mkim221@myseneca.ca
// Date of completion: Oct 10, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H

#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>

namespace sdds{
class Book {
    std::string author;
    std::string titles;
    std::string c_public;
    size_t yearOfPub;
    double priceOfBook;
    std::string desc;
public:
    Book();
    const std::string& title() const;
    const std::string& country() const;
    const size_t& year() const;
    double& price();
    Book(const std::string& strBook);
    friend std::ostream& operator<<(std::ostream& os, const Book& bk);
};
}

#endif /* Book_hpp */

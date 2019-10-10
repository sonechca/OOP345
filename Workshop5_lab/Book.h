//
//  Book.hpp
//  S3 Workshop 5 lab
//
//  Created by Mintae Kim on 2019-10-10.
//  Copyright © 2019 Mintae Kim. All rights reserved.
//

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

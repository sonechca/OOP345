//
//  Book.cpp
//  S3 Workshop 5 lab
//
//  Created by Mintae Kim on 2019-10-10.
//  Copyright © 2019 Mintae Kim. All rights reserved.
//
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include "Book.h"

namespace sdds {
Book::Book(){
    author = "";
    titles = "";
    c_public = "";
    yearOfPub = 0;
    priceOfBook = 0.0;
    desc = "";
}
const std::string& Book::title() const{
    return titles;
}
const std::string& Book::country() const{
    return c_public;
}
const size_t& Book::year() const{
    return yearOfPub;
}
double& Book::price() {
    return priceOfBook;
}
Book::Book(const std::string& strBook){ // separate the field and set data
    auto author_field = strBook.find(',');
    auto title_field = strBook.find(',', author_field+1);
    auto country_field = strBook.find(',', title_field+1);
    auto price_field = strBook.find(',', country_field + 1);
    auto years_field = strBook.find(',', price_field + 1);
    auto desc_field = strBook.length();
    author = strBook.substr(0,author_field);
    author.erase(0,author.find_first_not_of(" "));
    titles = strBook.substr(author_field+1,title_field - author_field - 1);
    titles.erase(0, titles.find_first_not_of(" "));
    c_public = strBook.substr(title_field + 1, country_field - title_field -1);
    c_public.erase(0,c_public.find_first_not_of(" "));
    priceOfBook = stod(strBook.substr(country_field + 1, price_field - country_field - 1));
    yearOfPub = stoi(strBook.substr(price_field + 1, years_field - price_field -1));
    desc = strBook.substr(years_field + 1, desc_field - years_field - 1);
    desc.erase(0,desc.find_first_not_of(" "));
}
std::ostream& operator<<(std::ostream& os, const Book& bk){
    os << std::setw(20) << bk.author << " | "
        << std::setw(22) << bk.titles << " | "
        << std::setw(5) << bk.c_public << " | "
        << std::setw(4) << bk.yearOfPub << " | "
        << std::setw(6) << std::fixed << std::setprecision(2) << bk.priceOfBook << " | "
    << bk.desc << std::endl;
    return os;
}
}

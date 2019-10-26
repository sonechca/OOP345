// Name: Mintae Kim
// Seneca Student ID: 141915181
// Seneca email: mkim221@myseneca.ca
// Date of completion:
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SDDS_ITEM_H
#define SDDS_ITEM_H

#include <iostream>
#include <string>
#include <iomanip>
#include "Utilities.h"
namespace sdds {
class Item {
    std::string m_name;
    std::string m_description;
    unsigned int m_serialNumber;
    unsigned int m_quantity;
    Utilities util;
public:
    Item(const std::string str);
    const std::string& getName() const;
    const unsigned int getSerialNumber();
    const unsigned int getQuantity();
    void updateQuantity();
    void display(std::ostream& os, bool full) const;
};
}

#endif /* Item_hpp */

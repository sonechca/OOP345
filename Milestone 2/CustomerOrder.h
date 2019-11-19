// Name: Mintae Kim
// Seneca Student ID: 141915181
// Seneca email: mkim221@myseneca.ca
// Date of completion: Nov 15, 2019
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef CustomerOrder_hpp
#define CustomerOrder_hpp

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "Utilities.h"
#include "Item.h"
struct ItemInfo
{
    std::string m_itemName;
    unsigned int m_serialNumber = 0;
    bool m_fillState = false;

    ItemInfo(std::string src) : m_itemName(src) {};
};

class CustomerOrder {
    std::string m_name;
    std::string m_product;
    unsigned int m_cntItem;
    ItemInfo** m_lstItem;
    static size_t m_widthField;
    Utilities util;
public:
    CustomerOrder();
    CustomerOrder(const std::string& str);
    CustomerOrder(CustomerOrder& copy);
    CustomerOrder(CustomerOrder&& move) noexcept;
    CustomerOrder& operator=(CustomerOrder&& mv);
    ~CustomerOrder();
    bool getItemFillState(std::string) const;
    bool getOrderFillState() const;
    void fillItem(Item& item, std::ostream&);
    void display(std::ostream&) const;
};

#endif /* CustomerOrder_hpp */

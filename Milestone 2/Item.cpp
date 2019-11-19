// Name: Mintae Kim
// Seneca Student ID: 141915181
// Seneca email: mkim221@myseneca.ca
// Date of completion: Nov 15, 2019
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "Item.h"

Item::Item(const std::string str) {
    try{
        
        size_t tmp_pos = -1;
        bool check = true;
        m_name = util.extractToken(str, tmp_pos, check);
        m_serialNumber = std::stoi(util.extractToken(str, tmp_pos, check));
        m_quantity = std::stoi(util.extractToken(str, tmp_pos, check));
        m_description = util.extractToken(str, tmp_pos, check);
        
        if(util.getFieldWidth() < m_name.size())
            util.setFieldWidth(m_name.size());
    }catch (const char* msg){//get error message using exception
        std::cout << msg;
        exit(1);
    }
    
}
const std::string& Item::getName() const {
    return m_name;
}

const unsigned int Item::getSerialNumber() {
    return m_serialNumber++;
}
const unsigned int Item::getQuantity() {
    return m_quantity;
}
void Item::updateQuantity() {
    m_quantity -= 1;
}
void Item::display(std::ostream &
                   os , bool full) const{
    size_t width = util.getFieldWidth();
    if(full == false){
        os << std::left << std::setw(static_cast<int>(width)) << getName();
        os << " [" << std::right << std::setw(6) << std::setfill('0') << m_serialNumber << "]" << std::setfill(' ') << std::endl;
    }
    
    else {
        os << std::left <<std::setw(static_cast<int>(width)) << getName();
        os << " [" << std::right << std::setw(6) << std::setfill('0') << m_serialNumber << "] " << std::setfill(' ') << "Quantity: " << std::setw(static_cast<int>(width)) << std::left << m_quantity << " Description: " << m_description << std::endl;
    }
}



// Name: Mintae Kim
// Seneca Student ID: 141915181
// Seneca email: mkim221@myseneca.ca
// Date of completion: Nov 15, 2019
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "CustomerOrder.h"
size_t CustomerOrder::m_widthField = 0;

CustomerOrder::CustomerOrder(){
    m_name = "";
    m_product = "";
    m_cntItem = 1;
    m_lstItem = nullptr;
}
CustomerOrder::CustomerOrder(const std::string& str){
    
    size_t tmp_pos = -1;
    bool check = false;
    std::vector<ItemInfo*> tmpVec;
    m_name = util.extractToken(str, tmp_pos, check);
    m_product = util.extractToken(str, tmp_pos, check);
    
    while(check){
        tmpVec.push_back(new ItemInfo(util.extractToken(str, tmp_pos, check)));
    }
    m_cntItem = static_cast<unsigned int>(tmpVec.size());
    m_lstItem = new ItemInfo*[m_cntItem];
    for(size_t i = 0; i < m_cntItem; i++){
        m_lstItem[i] = std::move(tmpVec[i]);
    }
    
    if(util.getFieldWidth() < m_name.size()){
               util.setFieldWidth(m_name.size());
           }
    if(util.getFieldWidth() < m_product.size()){
        util.setFieldWidth(m_product.size());
    }
    
}
CustomerOrder::CustomerOrder(CustomerOrder& copy){
    throw "ERROR: Cannot make copies.";
}
CustomerOrder::CustomerOrder(CustomerOrder&& move) noexcept{
    *this = std::move(move);
}
CustomerOrder& CustomerOrder::operator=(CustomerOrder &&mv){
    if(this != &mv){
        m_name = mv.m_name;
        m_product = mv.m_product;
        m_cntItem = mv.m_cntItem;
        m_lstItem = mv.m_lstItem;
        m_widthField = mv.m_widthField;
        
        mv.m_name = "";
        mv.m_product = "";
        mv.m_cntItem = 0;
        mv.m_lstItem = nullptr;
        mv.m_widthField = 0;
    }
    return *this;
}
CustomerOrder::~CustomerOrder(){
    delete [] m_lstItem;
    m_lstItem = nullptr;
}
bool CustomerOrder::getItemFillState(std::string str) const{
    for(size_t i = 0; i < m_cntItem; i++){
        if(m_lstItem[i]->m_itemName == str){
            if(!m_lstItem[i]->m_fillState){
                return false;
            }
        }
    }
    return true;
}

bool CustomerOrder::getOrderFillState() const{
    for(size_t i = 0; i < m_cntItem; i++){
        if(m_lstItem[i]->m_fillState == false)
            return false;
    }
    return true;
}

void CustomerOrder::fillItem(Item &item, std::ostream & os) {
    for(size_t i = 0; i < m_cntItem; i++){
        if(m_lstItem[i]->m_itemName == item.getName()){
            m_lstItem[i]->m_serialNumber = item.getSerialNumber();
            m_lstItem[i]->m_fillState = true;
            
            os << (m_lstItem[i]->m_fillState ? "Filled" : "Unfilled") << " "
            << m_name << ", " << m_product << "[" << m_lstItem[i]->m_itemName << "]" << std::endl;
            
        }
    }
}

void CustomerOrder::display(std::ostream & os) const {
    m_widthField = util.getFieldWidth();
    os << m_name << " - " << m_product << std::endl;
    for(size_t i = 0; i < m_cntItem; i++){
        os << std::setw(6) << std::setfill('0')<< "[" << m_lstItem[i]->m_serialNumber << "] " << std::setfill(' ') << std::setw(static_cast<int>(m_widthField)) << m_lstItem[i]->m_itemName << " - ";
        os << (getItemFillState(m_lstItem[i]->m_itemName) ? "Filled" : "MISSING") << std::endl;
    }
    
}

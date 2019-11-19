// Name: Mintae Kim
// Seneca Student ID: 141915181
// Seneca email: mkim221@myseneca.ca
// Date of completion: Nov 15, 2019
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "Utilities.h"


size_t Utilities::m_widthField = 1; // static value defalut is 1
char Utilities::m_delimiter = '\0'; // static value default is null

void Utilities::setFieldWidth(size_t f_width) {
    m_widthField = f_width;
}

size_t Utilities::getFieldWidth() const {
    return m_widthField;
}
const std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {
    
    std::string tmp = "";
    size_t fieldOfDelimiter = str.find(m_delimiter, next_pos + 1);
    if(fieldOfDelimiter < str.length()){
        more = true; // it is mean that there are more string in the line
    }
    else{
        fieldOfDelimiter = str.length();
        more = false; // string is not anymore in the line
    }
    tmp = str.substr(next_pos + 1, fieldOfDelimiter - next_pos -1);
    next_pos = fieldOfDelimiter; // for next delimeter, I set the new starting point


    if(tmp == "") //"" means they had two delimeter
        throw "Error - 2 delimiter";
    return tmp;
}
void Utilities::setDelimiter(const char deli) {
    m_delimiter = deli;
}
const char Utilities::getDelimiter() const {
    return m_delimiter;
}


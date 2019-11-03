// Name: Mintae Kim
// Seneca Student ID: 141915181
// Seneca email: mkim221@myseneca.ca
// Date of completion: Oct 31, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include "Utilities.h"
namespace sdds {
Vehicle* createInstance(std::istream& in){
    std::string line = "";
    
    std::getline(in, line, '\n');
    std::stringstream buf(line);
    
    std::getline(buf, line, ',');
    line.erase(0,line.find_first_not_of(" "));
    line.erase(line.find_last_not_of(" ")+1);
    
    if(in.fail() || line.length() != 1)
        return nullptr;
    if(line[0] == 'c' || line[0] == 'C') {
        return new Car(buf);
    }
    else if(line[0] == 'r' || line[0] == 'R'){
        return new Racecar(buf);
    }
    else{
        throw line[0];
    }
    
}
}

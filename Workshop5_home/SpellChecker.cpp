// Name: Mintae Kim
// Seneca Student ID: 141915181
// Seneca email: mkim221@myseneca.ca
// Date of completion: Oct 17, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#include <iostream>
#include <fstream>
#include <string>
#include "SpellChecker.h"
namespace sdds {
SpellChecker::SpellChecker(const char* filename){
    std::ifstream file(filename);
    std::string line;
    std::string temp[10];
    size_t index = 0;
    
    if(!file){ // open the file and if had error, throw error message
        throw "Bad file name!";
    }
    do {
        std::getline(file,line);
        if(line[0] != '\0'){
            temp[index] = line;
            index++;
        }
    }while(file);
    
    for(size_t i = 0; i < index; i++){
        auto bad_field = temp[i].find(' '); // find the bad words
        m_badWords[i] = temp[i].substr(0, bad_field); // until white space
        m_badWords[i].erase(0, m_badWords[i].find_first_not_of(" "));
        m_badWords[i].erase(m_badWords[i].find_last_not_of(" ") + 1);
       
       
        auto good_field = temp[i].find('\r', bad_field + 1); // find the good words after white space
        m_goodWords[i] = temp[i].substr(bad_field + 1, good_field - bad_field - 1);
        m_goodWords[i].erase(0, m_goodWords[i].find_first_not_of(" "));
        m_goodWords[i].erase(m_goodWords[i].find_last_not_of(" ") + 1);
    }
    
    file.close();
}
void SpellChecker::operator()(std::string& text) const {
    size_t index;
    for(size_t i = 0; i < 5; i++){
        index = text.find(m_badWords[i]); // find the bad words in the file
        while(index != std::string::npos) {
            text.replace(index,m_badWords[i].size(),m_goodWords[i]); // replace good words
            index = text.find(m_badWords[i]);
        }
    }
}
}

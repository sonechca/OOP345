#include <iostream>
#include <fstream>
#include <string>
#include "Text.h"

namespace sdds {
    Text::Text(){
        f_name = nullptr;
    }
    Text::Text(const char* name){
        std::ifstream f_file;
        f_file.open(name);
        
        if(f_file.is_open()){
            for (std::string word; f_file >> word; ++numOfRecord) {}
        }
        
        f_name = new std::string[numOfRecord];
        
        for (int i = 0; i < numOfRecord; i++) {
            std::getline(f_file, f_name[i]);
        }
        
    }
    Text::Text(const Text& copy){
        *this = copy;
    }
    
    Text& Text::operator=(const Text& copy){
        if(this != &copy){
            numOfRecord = copy.numOfRecord;
            delete [] f_name;
            
            f_name = new std::string[numOfRecord];
            for (int i = 0; i < numOfRecord; i++) {
                f_name[i] = copy.f_name[i];
            }
        }
        return *this;
    }
    Text::~Text(){
        delete [] f_name;
        f_name = nullptr;
    }
    size_t Text::size() const{
        return numOfRecord;
    }
}

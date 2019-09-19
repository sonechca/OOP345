#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "Text.h"

namespace sdds {
    Text::Text(){
        f_name = nullptr;
    }
    Text::Text(const char* name){
        std::ifstream f_file;
        f_file.open(name);
        std::string word;
        char c;
        word.clear();
        if(!f_file){
            return;
        }
        else{
            while(!f_file.eof()){
                c = f_file.get();
                if(c == ' '){
                    numOfRecord++;
                }
            }
        }
        
        
//        if(f_file.is_open()){
//            do {
//                getline(f_file, word, ' ');
//                numOfRecord++;
//            } while(!f_file.eof());
//        }
//        else{
//            return;
//        }
        
        
        f_name = new std::string[numOfRecord];

        for (unsigned int i = 0; i < numOfRecord; i++) {
            getline(f_file, f_name[i]);
        }
        
    }
    Text::Text(const Text& copy){
        *this = copy;
    }
    
    Text& Text::operator=(const Text& copy){
        if(this != &copy){
            numOfRecord = copy.numOfRecord;
            delete [] f_name;
            if(copy.f_name != nullptr){
                f_name = new std::string[numOfRecord];
                
                for (size_t i = 0; i < numOfRecord; i++) {
                    f_name[i] = copy.f_name[i];
                }
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

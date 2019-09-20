// Name: Mintae Kim
// Seneca Student ID: 141915181
// Seneca email: mkim221@myseneca.ca
// Date of completion: Sept 19, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "Text.h"

namespace sdds {
    
    // Constructor
    Text::Text(){
        f_name = nullptr;
        numOfRecord = 0;
    }
    
    // 1 argument Constructor
    Text::Text(const char* name){
        std::ifstream f_file;
        f_file.open(name);

        char c;
        if(!f_file){
            return;
        }
        else{
            while(!f_file.eof()){
                c = f_file.get(); // Get words one by one
                if(c == ' '){ // Check the ' ' and count words
                    numOfRecord++;
                }
            }
        }
        
// My first trial but not working
//        if(f_file.is_open()){
//            do {
//                getline(f_file, word, ' ');
//                numOfRecord++;
//            } while(!f_file.eof());
//        }
//        else{
//            return;
//        }
        
        
        f_name = new std::string[numOfRecord]; // allocate dynamic memory

        for (unsigned int i = 0; i < numOfRecord; i++) {
            getline(f_file, f_name[i],' ');
        }
        
    }
    
    // Copy constructor
    Text::Text(const Text& copy){
        *this = copy;
    }
    
    // Copy operator
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
        else {
            *this = Text();
        }
        
        return *this;
    }
    
    // Destructor, deallocate f_name pointer
    Text::~Text(){
        delete [] f_name;
        f_name = nullptr;
    }
    
    // Return record size
    size_t Text::size() const{
        return numOfRecord;
    }
}

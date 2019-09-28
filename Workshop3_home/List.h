// Name: Mintae Kim
// Seneca Student ID: 141915181
// Seneca email: mkim221@myseneca.ca
// Date of completion: Sep 26, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_LIST_H
#define SDDS_LIST_H
#include <iostream>

namespace sdds {
    template <typename T, int N> // Declare template with a non-type template parameter>
    class List {
        T a[N];
        size_t addListElement = 0; // variable for adding list elements
    public:
        size_t size() const{
            return addListElement;
        }
        const T& operator[](size_t i) const{
            return a[i]; 
        }
        void operator+=(const T& tt){
            if(addListElement < N){ // check the List number, it is under the maximum number or not
                a[addListElement] = tt;
                addListElement++; // add element and add size
            }
        }
};
}
#endif /* List_hpp */

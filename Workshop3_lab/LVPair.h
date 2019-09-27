// Name: Mintae Kim
// Seneca Student ID: 141915181
// Seneca email: mkim221@myseneca.ca
// Date of completion: Sep 26, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_LVPAIR_H
#define SDDS_LVPAIR_H

#include <iostream>
namespace sdds {
    template <typename L, typename V>
    class LVPair {
        L typeName;
        V typeValue;
    public:
        LVPair(): typeName{}, typeValue{} {} // Constuctor
        LVPair(const L& aa, const V& bb): typeName(aa),typeValue(bb){}; //constuctor with parameters
        const L& key() const{
            return typeName;
        }
        const V& value() const{
            return typeValue;
        }
        void display(std::ostream& os) const{
            os << key() << " : " << value() << std::endl; //output
        }
    };
// helper function for helping display
template <typename L, typename V>
std::ostream& operator<<(std::ostream& os, const sdds::LVPair<L, V>& pair){
    pair.display(os);
    return os;
}
}

#endif /* LVPair_hpp */

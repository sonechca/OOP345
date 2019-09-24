//
//  LVPair.hpp
//  S3 workshop 3 lab
//
//  Created by Mintae Kim on 2019-09-24.
//  Copyright © 2019 Mintae Kim. All rights reserved.
//

#ifndef SDDS_LVPAIR_H
#define SDDS_LVPAIR_H

#include <iostream>
namespace sdds {
    template <typename L, typename V>
    class LVPair {
        L typeName;
        V typeValue;
    public:
        LVPair();
        LVPair(const L& aa, const V& bb);
        const L& key() const;
        const V& value() const;
        void display(std::ostream& os) const;
    };

template <typename L, typename V>
std::ostream& operator<<(std::ostream& os, const sdds::LVPair<L, V>& pair);
}

#endif /* LVPair_hpp */

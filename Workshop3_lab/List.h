//
//  List.hpp
//  S3 workshop 3 lab
//
//  Created by Mintae Kim on 2019-09-24.
//  Copyright © 2019 Mintae Kim. All rights reserved.
//

#ifndef SDDS_LIST_H
#define SDDS_LIST_H
#include <iostream>

namespace sdds {
    template <typename T, int N>
    class List {
        T a[N];
    public:
        size_t size() const;
        const T& operator[](size_t i) const;
        void operator+=(const T& tt);
};
}
#endif /* List_hpp */

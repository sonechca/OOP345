//
//  Utilities.cpp
//  s3 Workshop6 lab
//
//  Created by Mintae Kim on 2019-10-29.
//  Copyright © 2019 Mintae Kim. All rights reserved.
//

#include "Utilities.h"
namespace sdds {
Vehicle* createInstance(std::istream& in){
    std::stringstream buf;
    std::string line;
    std::getline(in, line);
    buf << line;
    char tag;
    buf >> tag;
    if(tag == 'c' || tag == 'C'){
        return new Car(buf);
    }
    else{
        return nullptr;
    }
    
}
}

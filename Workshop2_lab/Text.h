//
//  Text.h
//  S3 Workshop2_lab
//
//  Created by Mintae Kim on 2019-09-15.
//  Copyright © 2019 Mintae Kim. All rights reserved.
//

#ifndef SDDS_TEXT_H
#define SDDS_TEXT_H
#include <string>
namespace sdds {
    class Text {
        static unsigned int numOfRecord;
        std::string* f_name;
        
    public:
        Text();
        Text(const char* name);
        Text(const Text& copy);
        Text& operator=(const Text& copy);
        ~Text();
        size_t size() const;
    };
}

#endif /* Text_h */

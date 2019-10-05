//
//  ConfirmationSender.hpp
//  S3 Workshop 4 lab
//
//  Created by Mintae Kim on 2019-10-04.
//  Copyright © 2019 Mintae Kim. All rights reserved.
//

#ifndef SDDS_CONFIRMATIONSENDER_H
#define SDDS_CONFIRMATIONSENDER_H

#include <iostream>
#include "Restaurant.h"
#include "Reservation.h"
namespace sdds {
class ConfirmationSender{
    const sdds::Reservation** revPointer;
    size_t numOfConfirm;
public:
    ConfirmationSender& operator+=(const Reservation& res);
    ConfirmationSender& operator-=(const Reservation& res);
    friend std::ostream& operator<<(std::ostream& os, const ConfirmationSender& con);
};
}

#endif /* ConfirmationSender_hpp */

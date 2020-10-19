//
// Created by Cezary Petryka on 19.10.2020.
//

#ifndef CINEMAS_SEAT_HPP
#define CINEMAS_SEAT_HPP

#include "../libs/libs.hpp"

struct Seat {
    int id;
    int cinema_room_id;
    int row;
    int place;
};

#endif //CINEMAS_SEAT_HPP

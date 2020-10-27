//
// Created by Cezary Petryka on 21.10.2020.
//

#ifndef CINEMAS_CINEMA_MANAGEMENT_HPP
#define CINEMAS_CINEMA_MANAGEMENT_HPP

#include "../repository/cinema_repository.hpp"
#include "../repository/cinema_room_repository.hpp"
#include "../repository/seat_repository.hpp"

class CinemaManagement {
    json get_data_from_json_file(const std::string &file_name) const;
    void add_datas_to_the_database(const std::string &file_name) const;
public:
    explicit CinemaManagement(const std::string& file_name);
};


#endif //CINEMAS_CINEMA_MANAGEMENT_HPP
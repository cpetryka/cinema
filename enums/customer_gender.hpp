//
// Created by Cezary Petryka on 20.01.2021.
//

#ifndef CINEMAS_CUSTOMER_GENDER_HPP
#define CINEMAS_CUSTOMER_GENDER_HPP

#include "../libs/libs.hpp"

namespace CustomerGender
{
    enum class Type
    {
        MALE = 0, FEMALE = 1
    };

    static Type Types[] = { Type::MALE, Type::FEMALE };
    static int SIZE = 2;

    static Type from_string(const std::string& value)
    {
        std::string lowercase = value;
        std::transform(value.begin(), value.end(), lowercase.begin(), [](const char& c) { return tolower(c); });

        if (lowercase == "male")
        {
            return Type::MALE;
        }
        else
        {
            return Type::FEMALE;
        }
    }

    static std::string to_string(Type type)
    {
        std::string customer_genders_str[] = { "MALE", "FEMALE" };
        return customer_genders_str[static_cast<int>(type)];
    }

    static Type at(const int pos)
    {
        if (pos < 0 || pos >= SIZE)
        {
            throw std::runtime_error("no gender with index " + std::to_string(pos));
        }

        return Types[pos];
    }
}

using customer_gender = CustomerGender::Type;

#endif //CINEMAS_CUSTOMER_GENDER_HPP

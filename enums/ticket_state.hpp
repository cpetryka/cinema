//
// Created by Cezary Petryka on 20.01.2021.
//

#ifndef CINEMAS_TICKET_STATE_HPP
#define CINEMAS_TICKET_STATE_HPP

namespace TicketState
{
    enum class Type
    {
        ORDERED = 0, RESERVED = 1, CANCELLED = 2
    };

    static Type Types[] = { Type::ORDERED, Type::RESERVED, Type::CANCELLED };
    static int SIZE = 3;

    static Type from_string(const std::string& value)
    {
        std::string lowercase = value;
        std::transform(value.begin(), value.end(), lowercase.begin(), [](const char& c) { return tolower(c); });

        if (lowercase == "ordered")
        {
            return Type::ORDERED;
        }
        else if(lowercase == "reserved") {
            return Type::RESERVED;
        }
        else
        {
            return Type::CANCELLED;
        }
    }

    static std::string to_string(Type type)
    {
        std::string ticket_states_str[] = { "ORDERED", "RESERVED", "CANCELLED" };
        return ticket_states_str[static_cast<int>(type)];
    }

    static Type at(const int pos)
    {
        if (pos < 0 || pos >= SIZE)
        {
            throw std::runtime_error("no ticket state with index " + std::to_string(pos));
        }

        return Types[pos];
    }
}

using ticket_state = TicketState::Type;

#endif //CINEMAS_TICKET_STATE_HPP

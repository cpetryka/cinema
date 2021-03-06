//
// Created by Cezary Petryka on 08.10.2020.
//

#ifndef CINEMAS_LIBS_HPP
#define CINEMAS_LIBS_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <exception>
#include <optional>
#include <algorithm>
#include <typeinfo>
#include <thread>
#include <functional>

#include "sqlite3.h"
#include "json.hpp"
#include "date.hpp"

using json = nlohmann::json;
using namespace date;
using namespace std::chrono;

#endif //CINEMAS_LIBS_HPP

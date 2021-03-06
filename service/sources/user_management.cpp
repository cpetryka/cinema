//
// Created by Cezary Petryka on 27.10.2020.
//

#include "../user_management.hpp"

json UserManagement::get_data_from_json_file(const std::string &file_name) const {
    std::ifstream reading(file_name);
    json j;

    if(reading.is_open()) {
        reading >> j;
        reading.close();
    }
    else {
        throw std::runtime_error{"the file '" + file_name + "' could not be opened"};
    }

    return j;
}

void UserManagement::change_password(const int customer_id) {
    std::cout << "Enter new password: " << std::endl;
    std::string new_password;
    std::getline(std::cin, new_password);

    CustomerRepository cr;
    auto customer = cr.find_by_id(customer_id).value();

    UserRepository ur;
    auto user = ur.find_by_id(customer->user_id).value();
    ur.update(user->id, User{user->id, user->username, new_password, user->role});
}

UserManagement::UserManagement(const std::string &file_name) {
    get_users_to_the_database(file_name);
}

void UserManagement::get_users_to_the_database(const std::string &file_name) const {
    json data = get_data_from_json_file(file_name);

    std::for_each(data.begin(), data.end(), [](const auto& one_user) {
        std::string user_role_tmp = one_user["role"];
        User u {0, one_user["username"], one_user["password"], user_role_tmp};

        // If there is no such user, this adds it
        if(!UserRepository::find_pos(u).has_value()) {
            UserRepository ur;
            ur.insert(u);
        }

        if(UserRole::to_string(u.role) == "CUSTOMER") {
            CustomerRepository cr;
            auto user_id = UserRepository::find_pos(u).value();
            std::string gender_tmp = one_user["gender"];
            Customer c{0, one_user["name"], one_user["surname"], one_user["age"], gender_tmp, one_user["city"], user_id};

            if(!CustomerRepository::find_pos(c).has_value()) {
                cr.insert(c);
            }
        }
    });
}

int UserManagement::sign_in() {
    auto counter = 0;
    std::string username, password;
    std::optional<int> found_customer;

    do {
        std::cout << "Enter your username:" << std::endl;
        std::getline(std::cin, username);

        std::cout << "Enter your password:" << std::endl;
        std::getline(std::cin, password);

        found_customer = CustomerRepository::find_customer_by_username_and_password(username, password);
    } while(++counter < 3 && !found_customer.has_value());

    if(!found_customer.has_value()) {
        throw std::runtime_error{"There is no user with a given login or password."};
    }

    return found_customer.value();
}

void UserManagement::account_management() {
    auto customer_id = sign_in();
    auto user_choice = 0;

    while(true) {
        std::cout << "================ ACCOUNT MENU ================" << std::endl;
        std::cout << "== 1. CHANGE PASSWORD" << std::endl;
        std::cout << "== 9. EXIT" << std::endl;
        std::cout << "==============================================" << std::endl;

        std::cout << "Your choice: " << std::endl;
        std::cin >> user_choice; std::cin.get();

        switch (user_choice) {
            case 1:
                change_password(customer_id);
                break;
            case 9:
                return;
            default:
                std::cout << "There is no such option! Try again." << std::endl;
        }
    }
}
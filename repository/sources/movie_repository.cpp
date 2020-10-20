//
// Created by Cezary Petryka on 20.10.2020.
//

#include "../movie_repository.hpp"

void MovieRepository::insert(const Movie &movie) {
    const auto connection = DbConnection::get_instance()->get_connection();
    const std::string sql = "insert into movies(title, genre, author) values (?, ?, ?)";
    sqlite3_stmt* stmt = nullptr;
    sqlite3_prepare_v2(connection, sql.c_str(), -1, &stmt, nullptr);
    sqlite3_bind_text(stmt, 1, movie.title.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, movie.genre.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, movie.author.c_str(), -1, SQLITE_STATIC);
    const auto result = sqlite3_step(stmt);

    if(SQLITE_DONE != result) {
        sqlite3_errmsg(connection);
        throw std::exception{sqlite3_errmsg(connection)};
    }

    sqlite3_finalize(stmt);
}

void MovieRepository::update(const int id, const Movie &movie) {
    const auto connection = DbConnection::get_instance()->get_connection();
    const std::string sql = "update movies set title = ?, genre = ?, author = ? where id = ?";
    sqlite3_stmt* stmt = nullptr;
    sqlite3_prepare_v2(connection, sql.c_str(), -1, &stmt, nullptr);
    sqlite3_bind_text(stmt, 1, movie.title.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, movie.genre.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, movie.title.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 4, id);
    const auto result = sqlite3_step(stmt);

    if(SQLITE_DONE != result) {
        sqlite3_errmsg(connection);
        throw std::exception{sqlite3_errmsg(connection)};
    }

    sqlite3_finalize(stmt);
}

void MovieRepository::remove(const int id) {
    const auto connection = DbConnection::get_instance()->get_connection();
    const std::string sql = "delete from movies where id = ?";
    sqlite3_stmt* stmt = nullptr;
    sqlite3_prepare_v2(connection, sql.c_str(), -1, &stmt, nullptr);
    sqlite3_bind_int(stmt, 1, id);
    const auto result = sqlite3_step(stmt);

    if(SQLITE_DONE != result) {
        sqlite3_errmsg(connection);
        throw std::exception{sqlite3_errmsg(connection)};
    }

    sqlite3_finalize(stmt);
}

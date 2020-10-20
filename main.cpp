#include "repository/cinema_repository.hpp"
#include "repository/cinema_room_repository.hpp"
#include "repository/seat_repository.hpp"
#include "repository/movie_repository.hpp"
#include "repository/seance_repository.hpp"
#include "repository/user_repository.hpp"
#include "repository/customer_repository.hpp"
#include "repository/ticket_repository.hpp"

int main() {
    try {
         /*Cinema c{0, "MULTIKINO", "WARSOW"};
         CinemaRepository cinema_repository;
         cinema_repository.insert(c);
         cinema_repository.update(1, c);
         cinema_repository.remove(2);*/

         /*CinemaRoom cr{0, "THE BEST ONE", 2, 30, 40};
         CinemaRoomRepository crr;
         crr.insert(cr);
         crr.update(2, cr);
         crr.remove(1);*/

        /*Seat s{0, 1, 2, 4};
        Seat s2{0, 2, 3, 10};
        SeatRepository sr;
        sr.insert(s);
        sr.update(2, s2);
        sr.remove(5);*/

        /*Movie m{0, "SPIDER-MAN", "ACTION", "SAM RAIMI"};
        Movie m2{0, "SPIDER-MAN", "FICTION", "SAM RAIMI"};
        MovieRepository mr;
        mr.insert(m);
        mr.insert(m);
        mr.insert(m);
        mr.update(2, m2);
        mr.remove(3);*/

        /*Seance s{0, 1, 2, "2020-12-20 16:00:00"};
        Seance s2{0, 1, 2, "2020-12-20 18:00:00"};
        SeanceRepository sr;
        sr.insert(s);
        sr.insert(s2);
        sr.insert(s2);*/

        /*User u{0, "cezxxx", "cpp", "admin"};
        User u2{0, "adkk", "adkk", "customer"};
        UserRepository ur;
        ur.insert(u);
        ur.update(4, u2);
        ur.insert(u2);
        ur.remove(2);*/

        /*Customer c{0, "ADAM", "NOWAK", 20, "MALE", "WARSAW", 4};
        Customer c2{0, "CEZARY", "STOBOGA", 30, "MALE", "CRACOW", 1};
        CustomerRepository cr;
        cr.insert(c);
        cr.insert(c2);
        cr.remove(3);*/

        /*Ticket t {0, 1, 1, 1, 20, "ORDERED"};
        Ticket t2 {0, 2, 3, 2, 40, "ORDERED"};
        TicketRepository tr;
        tr.insert(t2);
        tr.insert(t2);
        tr.update(1, t);
        tr.remove(2);*/
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
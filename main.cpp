#include "service/cinema_management.hpp"
#include "service/movie_and_seance_management.hpp"
#include "service/user_management.hpp"
#include "service/ticket_management.hpp"

int main() {
    try {
        /*CinemaManagement cm{"cinemas.json"};
        MovieAndSeanceManagement masm{"movies.json", "seances.json"};
        UserManagement am{"users.json"};*/

        /*TicketManagement tm;
        tm.buy_ticket();*/

        // "ACTION", "WARSAW", "2020-11-10", "14"
        // ACTION,WARSAW,2020-11-10,14

        /*const auto x = TicketRepository::find_reserved_seats(41);
        for(const auto& xx : x) {
            std::cout << xx << std::endl;
        }*/
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}

/*
 * user -> role -> mozna zrobic enum / walidacje
 * customer -> gender -> mozna zrobic enum / walidacje
 * ticket -> status -> mozna zrobic enum / walidacje
 * seance -> date_time -> teraz jest jako napis, mozna zrobic jako 'datetime',
 *                        ale i tak bedzie przekonwertowany na typ 'numeric'
 */

/*
* A. "AKCJA,WARSZAWA,21" -> szukam pasujace seansy -> zwraca liste pasujacych seansow
* B. user wybiera || -> zwracam informacje o miejscach (tablica dwuwymiarowa) ->
*    user wybiera miejsca do zarezerwowania + rezerwacja/kupno
* C. analiza miejsca (ok, czy zajete) -> wyliczenie ceny + zapisanie do db + email
* D. kiedy rezerwacja przydzielic unikalne oznaczenie, ktore user moze wykorzystac
*    analiza stanu zarezerwowanych biletow co 15 minut - CZY TO MOZE BYC PO PROSTU TICKET_ID?
* */
/*
@author Saitcan Baskol
@studentid 21803589
*/
    #include <iostream>
    #include <string>
    #include "Flight.h"
    #include "Reservation.h"
    using namespace std;


    class ReservationSystem {
    public:
    ReservationSystem();
    ~ReservationSystem();
    ReservationSystem(const ReservationSystem& rightVal);
    ReservationSystem& operator=(const ReservationSystem& rightVal);
    void addFlight( const int flightNo, const int rowNo, const int seatNo );
    void cancelFlight( const int flightNo );
    void showAllFlights();
    void showFlight( const int flightNo );
    int makeReservation( const int flightNo, const int numPassengers,
    const int *seatRow, const char *seatCol );
    void showReservation( const int resCode );
    void cancelReservation( const int resCode );
    int totalFlights;
    Flight* flightArr;
    Reservation* ticketArray;
    int totalTickets;
    };














    /**
void cancelReservation( const int resCode );


    */

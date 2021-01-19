#include <iostream>
#include <string>
using namespace std;
/*
@author Saitcan Baskol
@studentid 21803589
*/


class Reservation {
public:
    int* rowRes;
    char* seatRes;
    int flight;
    int numOfPas;
    int ticketCode;
    Reservation();
    Reservation(int flight,int numOfPas,const int* rowRes,const char* seatRes);
    ~Reservation();
    Reservation(const Reservation& rightVal);
    Reservation& operator=(const Reservation& rightVal);




};


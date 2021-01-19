#include <iostream>
#include <string>
using namespace std;
/*
@author Saitcan Baskol
@studentid 21803589
*/

class Flight {
public:
     int flightNumber;
     int row;
     int seat;
     bool** seatReserv;
    Flight();
    Flight(int fly,int rw,int st);
    ~Flight();
    Flight(const Flight& rightVal);
    Flight& operator=(const Flight& rightVal);

};


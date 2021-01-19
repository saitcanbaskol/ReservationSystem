#include "Reservation.h"
#include <iostream>
#include <string>
using namespace std;
/*
@author Saitcan Baskol
@studentid 21803589
*/

Reservation::Reservation(){
    flight = 0;
    numOfPas = 1;
    ticketCode = 0;
    rowRes = new int[numOfPas];
    seatRes = new char[numOfPas];

}
  Reservation::Reservation(int fly,int numpass,const int* row,const char* seat)
    {
        ticketCode = 0;
        flight = fly;
        numOfPas = numpass;
       rowRes = new int[numOfPas];
       seatRes= new char[numOfPas];
       for(int i = 0; i  < numpass;i++)
        {
        rowRes[i] = row[i];
        seatRes[i] = seat[i];
        }

    }
   Reservation::~Reservation()
    {
        delete[] rowRes;
        delete[] seatRes;


    }
   Reservation::Reservation(const Reservation& rightVal)
    {
        flight = rightVal.flight;
        numOfPas = rightVal.numOfPas;
        ticketCode = rightVal.ticketCode;
        rowRes = new int[numOfPas];
        seatRes = new char[numOfPas];
        for(int i = 0; i < numOfPas; i++)
        {
                rowRes[i] = rightVal.rowRes[i];
                seatRes[i] = rightVal.seatRes[i];
        }
    }
    Reservation& Reservation::operator=(const Reservation& rightVal)
    {
        delete[] rowRes;
        delete[] seatRes;
        flight = rightVal.flight;
        numOfPas = rightVal.numOfPas;
        ticketCode = rightVal.ticketCode;
        rowRes = new int[numOfPas];
        seatRes = new char[numOfPas];
        for(int i = 0; i < numOfPas; i++)
        {
                rowRes[i] = rightVal.rowRes[i];
                seatRes[i] = rightVal.seatRes[i];
        }
        return *this;



    }



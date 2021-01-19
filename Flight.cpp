/*
@author Saitcan Baskol
@studentid 21803589
*/
#include <iostream>
#include <string>
using namespace std;
#include "Flight.h"

        Flight::Flight()
        {
            flightNumber = 0;
            row = 2;
            seat = 2;

            seatReserv = new bool*[row];
            for(int i = 0; i < row;i++)
            {
                seatReserv[i] = new bool[seat];
                for(int j = 0;j < seat; j++)
                {
                    seatReserv[i][j] = true;
                }
            }

        }
        Flight::Flight(int fly,int rw,int st)
        {
            flightNumber = fly;
            row = rw;
            seat = st;
            seatReserv = new bool*[row];
            for(int i = 0; i < row;i++)
            {
                seatReserv[i] = new bool[seat];
                for(int j = 0;j < seat; j++)
                {
                    seatReserv[i][j] = true;
                }
            }



        }
        Flight::~Flight()
        {
             for(int i = 0; i < row; i++)
            {
                delete[] seatReserv[i];
            }
            delete [] seatReserv;


        }
        Flight::Flight(const Flight& rightVal)
        {
            flightNumber = rightVal.flightNumber;
            row = rightVal.row;
            this->seatReserv = new bool*[row];

            for (int i = 0; i < this->row; i++)
                {
                this->seatReserv[i] = new bool[seat];
                for (int j = 0; j < this->seat; j++)
                    {
                      this->seatReserv[i][j] = rightVal.seatReserv[i][j];
                    }
       }
        }
        Flight& Flight::operator=(const Flight& rightVal)
        {
            if(this != &rightVal)
            {
                for(int i = 0; i < row; i++)
                {
                    delete[] seatReserv[i];
                }
                delete [] seatReserv;
                flightNumber = rightVal.flightNumber;
                row = rightVal.row;
                seat = rightVal.seat;
                seatReserv = new bool*[row];

                for(int r = 0; r < row; r++)
                {
                    seatReserv[r] = new bool[seat];
                }

                for(int k = 0; k < row; k++)
                {
                    for(int m = 0; m < seat; m++)
                    {
                        seatReserv[k][m] = rightVal.seatReserv[k][m];
                    }
                }

            }

            return *this;

        }










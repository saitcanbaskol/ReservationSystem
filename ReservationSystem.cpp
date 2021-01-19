            #include <iostream>
            #include <string>
            using namespace std;
            #include "ReservationSystem.h"
            /*
            @author Saitcan Baskol
            @studentid 21803589
            */



        ReservationSystem::ReservationSystem()
        {
            totalTickets = 1;
            totalFlights = 1;
            flightArr = new Flight[totalFlights];
            ticketArray = new Reservation[totalTickets];
        }
        ReservationSystem::~ReservationSystem()
        {
            delete[] flightArr;
            delete[] ticketArray;

        }
        ReservationSystem::ReservationSystem(const ReservationSystem& rightVal)
        {
            totalFlights = rightVal.totalFlights;
            totalTickets = rightVal.totalTickets;
            flightArr = new Flight[totalFlights];
            ticketArray = new Reservation[totalTickets];

        }
        ReservationSystem& ReservationSystem::operator=(const ReservationSystem& rightVal)
        {
            delete[] flightArr;
            delete[] ticketArray;
            totalFlights = rightVal.totalFlights;
            totalTickets = rightVal.totalTickets;
            flightArr = new Flight[totalFlights];
            ticketArray = new Reservation[totalTickets];
            for(int i = 0; i < totalFlights; i++){
                flightArr[i] = rightVal.flightArr[i];

            }
            for(int i = 0; i < totalTickets; i++)
            {
                ticketArray[i] = rightVal.ticketArray[i];
            }

        }
        void ReservationSystem::addFlight(const int flightNo, const int rowNo, const int seatNo)
        {
            Flight* temp = new Flight[totalFlights + 1];
            bool uniq = true;

            for (int i = 0; i < totalFlights; i++)
            {
                temp[i] = flightArr[i];
            }
            for(int i = 0; i < totalFlights; i++)
            {
                if(flightArr[i].flightNumber == flightNo)
                    uniq = false;


            }
            if(uniq == true)
                {
                    if( rowNo > 0 && seatNo > 0)
                    {
                        temp[totalFlights] = Flight(flightNo,rowNo,seatNo);
                delete[] flightArr;
                flightArr = temp;
                totalFlights++;
                cout << "Flight" << flightNo << " Has been added!"<<endl;
                    }
                     else
                     {
                         temp[totalFlights] = Flight(flightNo,rowNo,seatNo);
                        delete[] flightArr;
                         flightArr = temp;
                          totalFlights++;
                        cout << "Flight" << flightNo << " Has been added! with default row and seats which is 10"<<endl;
                    }

                }
            if(uniq == false)
                {
                    cout << "Flight no must be unique for each flight!"<<endl;
                }


        }
        void ReservationSystem::cancelFlight( const int flightNo )
        {
            bool error = true;
            int index;
            int indexTicket;
            for(int i = 0; i < totalFlights; i++){
                if(flightArr[i].flightNumber == flightNo)
                {
                        error = false;
                        index = i;
                    Flight* temp = new Flight[totalFlights - 1];
                    for(int j = 0; j < index; j++)
                    {
                        temp[j] = flightArr[j];
                    }
                    for(int k = index; k < totalFlights -1; k++)
                    {
                        temp[k] = flightArr[k + 1];
                    }
                    for(int i = 0; i < totalTickets;i++)
                    {
                        if(ticketArray[i].flight == flightArr[index].flightNumber)
                        {
                            ticketArray[i].ticketCode = -1;
                        }
                    }
                    delete [] flightArr;
                    flightArr = temp;
                    totalFlights--;
                    cout << "Flight " << flightNo << " Has been cancelled!"<<endl;

                }


            }
            if(error)
            {
                cout<< "There is no such flight to cancel!"<<endl;
            }


}
void ReservationSystem::showAllFlights()
{
    int totalSeats;
    cout << "Flights currently operated:"<<endl;

    for(int i = 1; i < totalFlights; i++)
    {
            totalSeats = (flightArr[i].row) * (flightArr[i].seat);

        cout << "Flight " << flightArr[i].flightNumber << " ( " << totalSeats  << " available seats )"<<endl;
    }


}

void ReservationSystem::showFlight(const int flightNo)
{
    bool found = false;
    int index;
    char letter;
    int count = 0;
    for(int i = 0; i < totalFlights; i++)
    {
            if(flightArr[i].flightNumber == flightNo)
            {
                found = true;
                index = i;
            }

    }
    if(found)
    {
        for(int i = 0; i < flightArr[index].row;i++)
        {
            for(int j = 0; j < flightArr[index].seat;j++)
            {
                if(flightArr[index].seatReserv[i][j] == false)
                {
                    count++;
                }
            }
        }
        cout<<"Flight "<<flightArr[index].flightNumber<< " Has "<< ((flightArr[index].seat) * (flightArr[index].row) - count)<< " Seats available"<<endl;
            for(int i = 0; i < flightArr[index].seat;i++)
            {
                letter = i + 65;
                cout<<" "<< letter;
            }
            cout<<endl;
            for(int i = 0; i < flightArr[index].row;i++)
            {
                    cout<<i+1<<" ";
                for(int j = 0; j < flightArr[index].seat;j++)
                {
                    if(flightArr[index].seatReserv[i][j] == true)
                    {
                        cout<< "o"<<" ";
                    }
                   else if(flightArr[index].seatReserv[i][j] == false)
                    {
                        cout<< "x"<< " ";
                    }

                }
                cout<<endl;
            }

    }
    else
    {
        cout<<"There is no flight with given flightNo";
    }
    cout<<endl;
}

int ReservationSystem::makeReservation( const int flightNo, const int numPassengers,
    const int *seatRow, const char *seatCol )
    {
        bool exist = false;
        int index;
        for(int i = 0; i < totalFlights; i++)
        {
            if(flightArr[i].flightNumber == flightNo)
            {
                exist = true;
                index = i;
            }

        }
        if(exist)
        {

            for(int i = 0; i < numPassengers;i++)
            {
                if(flightArr[index].seatReserv[seatRow[i]-1][seatCol[i]-65] == true)
                {
                    flightArr[index].seatReserv[seatRow[i]-1][seatCol[i]-65] = false;

                }
                else
                {
                    cout<<"Seats are not available"<<endl;
                    return -1;
                }

            }
            Reservation* temp = new Reservation[totalTickets + 1];
            for(int i = 0; i < totalTickets; i++)
            {
                temp[i] = ticketArray[i];

            }

            temp[totalTickets] = Reservation(flightNo,numPassengers,seatRow,seatCol);
            delete[] ticketArray;
            ticketArray = temp;
           ticketArray[totalTickets].ticketCode = totalTickets;
            totalTickets++;
            return (totalTickets - 1);

        }

        else
        {
            cout<<"There is no flight with given flight no : "<< flightNo<<endl;
            return -1;
        }


    }

void ReservationSystem::showReservation(const int rcode)
{
    bool exist = false;
    int index;
    for(int i = 0; i < totalTickets; i++)
    {
        if(ticketArray[i].ticketCode == rcode)
        {
            index = i;
            exist = true;
        }
    }
    if(exist == true)
    {
        for(int i = 0; i < ticketArray[index].numOfPas;i++)
        {
            cout<<ticketArray[index].rowRes[i]<<ticketArray[index].seatRes[i]<<" ";

        }
        cout<<endl;

    }
    else
    {
        cout<<"There is no flight with this reservation code!"<<endl;
    }
}
void  ReservationSystem::cancelReservation( const int resCode )
{
    bool exist = false;
    int index;
    int index2;
    for(int i = 0; i < totalTickets; i++)
    {
        if(ticketArray[i].ticketCode == resCode && ticketArray[i].ticketCode != -1)
        {
            index = i;
            exist = true;
        }
    }
    if(exist)
    {
        cout<<"Reservation: "<<resCode<<" has cancelled. "<<endl;
        ticketArray[index].ticketCode = -1;
        for(int i = 0; i < totalFlights;i++)
        {
            if(ticketArray[index].flight == flightArr[i].flightNumber)
            {
                index2 = i;
            }
        }
         cout<<"Seats: ";
         for(int i = 0; i < ticketArray[index].numOfPas;i++)
        {
            cout<<" "<<ticketArray[index].rowRes[i]<<ticketArray[index].seatRes[i];

        }
        cout<<" has been cancelled"<<endl;
        for(int i = 0; i < ticketArray[index].numOfPas;i++)
        {
            flightArr[index2].seatReserv[ticketArray[index].rowRes[i]-1][ticketArray[index].seatRes[i]-65] = true;
        }
    }
    else
    {
        cout<<"There is no reservation to cancel under this code"<<endl;
    }
    cout<<endl;
}






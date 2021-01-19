#include <iostream>
#include <string>
using namespace std;
#include "ReservationSystem.h"


int main() {
ReservationSystem R;
R.showAllFlights();
R.addFlight(104, 4, 5);
R.addFlight(234, 8, 3);
R.addFlight(76, 6, 2);
R.showAllFlights();
int rowRes1[4] = {3, 3, 1, 1};
char colRes1[4] = {'A', 'B', 'B', 'C'};
int code1 = R.makeReservation(104, 4, rowRes1, colRes1);
if (code1 != -1)
cout << "Your reservation code is " << code1 << endl;
int rowRes2[4] = {1, 2,2, 3};
char colRes2[4] = {'A', 'B', 'C', 'C'};
int code2 = R.makeReservation(104, 4, rowRes2, colRes2);
if (code2 != -1)
cout << "Your reservation code is " << code2 << endl;
R.showReservation(1);
R.showReservation(2);
R.showFlight(104);
R.cancelFlight(104);
R.showReservation(1);
R.showReservation(2);






return 0;
}


//        Name: Brandon McFarlane
//  Assignment: hw3
//    Due Date: 03/07/2022
// Description: Accept a random point from the keyboard
//              in the unit square (x_org, y_org). generate 10
//              random points in the unit square and output the
//              random point generated which has the largest
//              distance to point (x_org, y_org).
//        File: hw3.cpp

#include <iostream>
#include <iomanip>
#include <cmath>

double random ( unsigned int &seed );
unsigned int seed = 5;

using namespace std;

int main()
{
   double x_org, y_org, x, y, distance;
   double farthest = 0, farthest_x, farthest_y;

   cout << endl;
   cout << "Enter an x-coordinate between 0.0000 and 1.0000: ";
   cin >> x_org;
   cout << "Enter a  y-coordinate between 0.0000 and 1.0000: ";
   cin >> y_org;

   for (int i = 1; i < 11; ++i)
   {
      x = random(seed);
      y = random(seed);
      
      distance = sqrt(pow((x_org - x), 2) + pow((y_org - y), 2));
      if (distance > farthest)
      {
	  farthest = distance;
	  farthest_x = x;
	  farthest_y = y;
      }
    }

   cout << endl;
   cout << fixed << showpoint << setprecision(4);
   cout << "                       x       y" << endl;
   cout << "Point of origin:       ";
   cout << setw(6) << x_org << ", " << setw(6) << y_org << endl;
   cout << "Farthest random point: ";
   cout << setw(6) << farthest_x << ", " << setw(6) << farthest_y << endl;
   cout << endl;
   cout << "Distance:              " << setw(6) << farthest << endl;
   cout << endl;
       
   return 0;
}

double random( unsigned int &seed )
{
    const int MODULUS = 15749;
    const int MULTIPLIER = 69069;
    const int INCREMENT = 1;

    seed = ((MULTIPLIER * seed) + INCREMENT) % MODULUS;

    return double (seed) / MODULUS;
}

/*
Sample Output:
=============
/u/erdos/students/bmcfarlane4
[bmcfarlane4@erdos ~]$ hw3

Enter an x-coordinate between 0.0000 and 1.0000: 0.6435
Enter a  y-coordinate between 0.0000 and 1.0000: 0.1111

                       x       y
Point of origin:       0.6435, 0.1111
Farthest random point: 0.0429, 0.6736

Distance:              0.8229

[bmcfarlane4@erdos ~]$ 
*/

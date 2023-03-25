//          Name: Brandon McFarlane
//    Assignment: hw06
//      Due date: 03/28/2022
//   Description: Write a program that outputs a root of a given function f(x) by using a bi-section method.
//                f(x) = x3 + 5x2 +7x +2

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double a = -100, b = 100;
//bisection(a, b);

double func(double x)
{
   return pow(x, 3) + 5 * pow(x, 2), + 7 * x + 2;
}

int main ()
{

if ((func(a) * func(b) >= 0))
{
   cout << "You have not assumed right a and b " << endl;

   return 0; 
}
   double c = a;
   while ((b-a) >= 0.01) 
{
   // Find middle point
      c = (a+b)/2;

   // Check if middle point is root
      if (func(c) == 0.0)
         break;
   // Decide the side to repeat the steps
      else if (func(c)*func(a) < 0)
         b = c;
      else
         a = c;
}

   cout << "The value of root is : " << c << endl;

   return 0;
}
/*
Sample Output:
==============
[bmcfarlane4@erdos ~]$ g++ hw06.cpp
[bmcfarlane4@erdos ~]$ ./a.out

a:-100
b: 100

The value of root is : -0.286865

[bmcfarlane4@erdos ~]$
*/  
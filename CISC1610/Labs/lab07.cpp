//          Name: Brandon McFarlane
//    Assignment: Lab07
//      Due date: 03/28/2022
//   Description: Write a program that given function f(x)
//                f(x) = x3 + 5x2 +7x +2
//                that determines the values x_left and x_right such that 
//                the sign of (f(x_left)) is oposite
//                to the sign of f(x_right).
//                generate 2 random # x_left, x_right until sign (f(x_left)) != sign (f(x_right))

#include <iostream>
#include <iomanip>
#include <cmath>
#include <ctime>


using namespace std;

double random(unsigned int &seed);
double func(double x);
int sign (double x);

unsigned int seed = time(0);

int main ()
{

double x_left, x_right, y_left, y_right;

x_left =  -100 + (200) * random(seed);

y_left = func(x_left);

do{
    x_right = -100 + (200) * random(seed);
    y_right = func(x_right);
}while(sign(y_left) == sign(y_right));

   cout << endl;
   cout << fixed << showpoint << setprecision(2);
   cout << "x left: "  << setw(4) << x_left << endl;
   cout << "x right: " << setw(4) << x_right << endl;
   cout << endl;
   
   return 0;

}
double func(double x)
{
   return pow(x, 3) + 5 * pow(x, 2), + 7 * x + 2;
}

int sign (double x) 
{
    return x/abs(x);
}

double random (unsigned int &seed)
{
    const int MODULUS = 15749;
    const int MULTIPLIER = 69069;
    const int INCREMENT = 1;
    seed = ((MULTIPLIER * seed)+ INCREMENT)% MODULUS;

    return double (seed)/MODULUS;
}

/*
Sample Output:
==============
[bmcfarlane4@erdos ~]$ g++ lab07.cpp
[bmcfarlane4@erdos ~]$ ./a.out

Two Random Points Generated

x_right:  6.61
x_left: -57.80


    
[bmcfarlane4@erdos ~]$
*/  
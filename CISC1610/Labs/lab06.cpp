//          Name: Brandon McFarlane
//    Assignment: lab06
//      Due date: 03/21/2022
//   Description: Write a program that accepts form a keyboard 2 sides, a and b, of a triangle and randomly generate side c of a triangle.
//          File: lab06

#include <iostream>
#include <iomanip>
#include <cmath>


double random(unsigned int &seed);
unsigned int seed = 5;

using namespace std;

int main()

{
    double a, b, c = 0;
  
    cout << "Enter A: ";
    cin >> a;
    
    cout << "Enter B: ";
    cin >> b;

    c = 25 *  random(seed);
    
    while ( a + b <= c || b + c <= a || c + a <= b)
    {
      c = 25 * random(seed);
    }
 
   cout << endl;
   cout << fixed << showpoint << setprecision(2);
   cout << "Side A " << setw(5) << a << endl;
   cout << "Side B " << setw(5) << b << endl;
   cout << "Side C " << setw(5) << c << endl;
   cout << endl;

    return 0;
  
}

  double random (unsigned int &seed)
  {
     const int MODULUS = 15749;
     const int MULTIPLIER = 69069;
     const int INCREMENT = 1;
     seed = ((MULTIPLIER * seed)+ INCREMENT)%MODULUS;

     return double (seed)/MODULUS;
  }
  
/*
Sample Output:
==============
[bmcfarlane4@erdos ~]$ g++ lab06.cpp
[bmcfarlane4@erdos ~]$ ./a.out

Enter side a:8
Enter side b:9

Side A:  8.00
Side B:  9.00
Side C: 12.19
    
[bmcfarlane4@erdos ~]$
*/    
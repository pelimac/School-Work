//        Name: Brandon McFarlane
//  Assignment: hw4
//    Due Date: 03/21/2022
// Description: Write a program that computes Sqrt of x according to Newtown's Formula
//    File: hw4.cpp
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;
int main()
{
  double x, difference = 1, next = 0, previous = 1;

  cout << "Please input a number for x: ";
  cin >> x;
  if (x < 1)
  {
    previous = x;
    next = 1;
  }
  else
  {
    previous = 1;
    next = x;
  }
    
    while (difference > 0.05)
    {
    next = (previous + (x/previous))*(0.5);
    difference = abs(next-previous);
    previous = next;
    cout << next << endl;
     }

    cout << "The root is: " << next << endl;
    cout << sqrt(x);

    return 0;
}

/*
Sample Output:
=============
/u/erdos/students/bmcfarlane4
[bmcfarlane4@erdos ~]$ hw3

Please input a number for x: 36
18.5
10.223
6.87223
6.05535
6.00025
6
The root is: 6
6

[bmcfarlane4@erdos ~]$ 
*/

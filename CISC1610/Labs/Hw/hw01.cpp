//        Name: Brandon McFarlane
//  Assignment: hw1
//        Due date: 02/10/2022
//  Description: Write a program that uses function formula (x) to compute and output the value of: formula (x)= ((x*x)- sqrt(x) + abs(x))/(2*x)
//        File: hw1.cpp


#include <iostream>
#include <iomanip>
#include <cmath>

double function_1(double x);

using namespace std;

int main()
{
  double x;

  cout << "Enter X value: ";
  cin >>  x;
  
 double function_1 = ((x*x)- sqrt(x) +abs(x))/(2*x);
  
 cout << "f(x)=" << function_1;
 
 return x;
}
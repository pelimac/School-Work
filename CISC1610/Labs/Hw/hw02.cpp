//        Name: Brandon McFarlane
//  Assignment: hw2
//    Due Date: 02/17/2021
// Description: write the program that accepts from the keyboard three coeffiecients of a quadratic equation. your program must not fail.
//        File: hw2.cpp

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double real_roots (double a,double b,double c);  // Function prototype for calculating real roots of a quadratic equation

int main ()
{
  bool keep_going = true;  // Boolean variable to control the program loop
  int answer = 1;  // Variable to store user's choice to continue or exit the program
  
  while(keep_going == true) 
  {
   double a,b,c;  // Variables to hold the coefficients of the quadratic equation
   cout << "enter the coefficeints" << endl; // Calling the function to calculate and display the real roots

   cout << "a:";
   cin >> a;
   cout << "b:";
   cin >> b; 
   cout << "c:";
   cin >> c;
   cout << real_roots(a,b,c) << endl; // Exiting the program loop if the user chooses to stop
   cout << "continue program?(0 = No/1 = Yes)";
   cin >> answer;
   if (answer == 0)
   {
     keep_going = false;
   }
  }
  
}
double real_roots (double a,double b,double c) 
{
  double x1 = ((-b) / (2 * a) + (sqrt(abs(b * b - 4 * a * c)))) / (2 * a);  // Calculating the first real root using the quadratic formula

  double x2 = ((-b) / (2 * a) - (sqrt(abs(b * b - 4 * a * c)))) / (2 * a);  // Calculating the second real root using the quadratic formula
  
  return x1- x2;  // Returning the difference between the two real roots
}   





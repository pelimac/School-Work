//        Name: Brandon McFarlane
//  Assignment: hw2
//    Due Date: 02/17/2021
// Description: write the program that accepts from the keyboard three coeffiecients of a quadratic equation. your program must not fail.
//        File: hw2.cpp

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double real_roots (double a,double b,double c);

int main ()
{
  bool keep_going = true;
  int answer = 1;
  
  while(keep_going == true)
  {
   double a,b,c;
   cout << "enter the coefficeints" << endl; 
   cout << "a:";
   cin >> a;
   cout << "b:";
   cin >> b; 
   cout << "c:";
   cin >> c;
   cout << real_roots(a,b,c) << endl; 
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
  double x1 = ((-b) / (2 * a) + (sqrt(abs(b * b - 4 * a * c)))) / (2 * a);
  double x2 = ((-b) / (2 * a) - (sqrt(abs(b * b - 4 * a * c)))) / (2 * a);
  return x1- x2;
}   





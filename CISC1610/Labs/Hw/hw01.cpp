//        Name: Brandon McFarlane
//  Assignment: hw1
//        Due date: 02/10/2022
//  Description: Write a program that uses function formula (x) to compute and output the value of: formula (x)= ((x*x)- sqrt(x) + abs(x))/(2*x)
//        File: hw1.cpp


#include <iostream> // Required for input/output operations
#include <iomanip> // Required for manipulating output format
#include <cmath> // Required for mathematical functions

double function_1(double x); // Function prototype for function_1

using namespace std;

int main()
{
double x; // Variable to hold the input value of x

cout << "Enter X value: "; // Prompting the user to enter the value of x
cin >> x; // Accepting the input value of x from the user

double function_1 = ((xx) - sqrt(x) + abs(x))/(2x); // Evaluating the formula for the given value of x and assigning the result to a variable called function_1

cout << "f(x)=" << function_1; // Outputting the result of the computation

return x; // Returning the value of x (Note: It seems like an incorrect value is being returned here since x is of type double, and the return type of main is int.)
}







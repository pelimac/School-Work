/* Brandon McFarlane
Recursion.cpp
*/
//demonstrates Recursion 
///Write the three recursive functions in the slides

#include <iostream>

using namespace std;

int bunnyEars(int n);
int sumDigits(int number);
int rangeSum(int from, int to);

int bunnyEars(int n) 
{
    if (n == 0) 
    {
        return 0;
    } 
    else if (n % 2 == 0) 
    {  // even
        return 3 + bunnyEars(n - 1);
    } 
    else 
    {  // odd
        return 2 + bunnyEars(n - 1);
    }
}


int sumDigits(int number) 
{
    if (number == 0) 
    {
        return 0;
    }
    else 
    {
        return (number % 10) + sumDigits(number / 10);
    }
}

int rangeSum(int from, int to) 
{
    if (from == to) 
    {
        return to;
    }
    else 
    {
        return to + rangeSum(from + 1, to);
    }
}


int main() 
{
    int numBunnies, numDigits, from, to;
    cout << "Enter the number of bunnies: ";
    cin >> numBunnies;
    cout << "Enter a number to sum its digits: ";
    cin >> numDigits;
    cout << "Enter the 'from' value for the range sum: ";
    cin >> from;
    cout << "Enter the 'to' value for the range sum: ";
    cin >> to;

    cout << "Bunny ears: " << bunnyEars(numBunnies) << endl;
    cout << "Sum of digits: " << sumDigits(numDigits) << endl;
    cout << "Range sum: " << rangeSum(from, to) << endl;

    return 0;
}
 
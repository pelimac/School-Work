//          Name: Brandon McFarlane
//    Assignment: lab05
//      Due date: 03/7/2022
//   Description: Write a program that ask user to enter 10 characters from the keyboard and outputs the # of characters a, capital or not, entered.

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() 
{
    char input;
    int counter = 0;

    for (int i = 0; i <10; ++i)
    {
        cout << "Enter a character: ";
        cin >> input;
    if (input == 'a' || input == 'A')
         counter++;
    }

    cout << "The number of a's in your inputs: "<< counter << endl;
    
    return 0;
}

/*
[bmcfarlane4@erdos ~]$ g++ lab05.cpp
[bmcfarlane4@erdos ~]$ ./a.out

  the # of characters a, capital or not, entered.
   counter # of a entered, capital or not.
    
[bmcfarlane4@erdos ~]$
*/    
    
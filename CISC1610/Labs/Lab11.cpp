//          Name: Brandon McFarlane
//    Assignment: Lab11
//      Due date: 04/25/2022
//   Description:Design and test function digital_root (N), 
//               where n is a positive integer and the digital route of n is defined as the sum of all digits of n, 
//               computed for as long as the sum is greater or equal to 10.

using namespace std;

#include <iostream>
#include <iomanip>

int digital_root (int n);

int main ()
{
    int n;

    cout << "Enter a positive integer you want to find the digital root for: "<< endl;
    cin >> n ;
    cout << "The digital root is: "<< endl;
    cout << digital_root(n);
    cout << endl;

    return 0;
}

int digital_root (int n)
{
    int sum;
    do 
    {
        sum = 0;

        while (n > 0) 
        {
            sum += n % 10;
                n /= 10;
        }
        n = sum;
    }while (n >= 10);
    
    return sum;
}

/*
Sample Output:
==============
[bmcfarlane4@erdos ~]$ g++ lab11.cpp
[bmcfarlane4@erdos ~]$ ./a.out

enter a positive integer you want to find the digital root for:
117
the digital root is: 
9

[bmcfarlane4@erdos ~]$
*/  


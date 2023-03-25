//          Name: Brandon McFarlane
//    Assignment: lab08
//      Due date: 04/04/2022
// Description: Write a program that declares a character array while small random letter
//              the array should be printed one character per line.
//              for example, the output of your program could  be: 
//              a [0] = m
//              a [1] = t

#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

double random(unsigned int & seed);
const int Size = 10;
unsigned int seed =time(0);

int main ()
{
    char a[10];
    for (int i = 0; i < Size; ++i)
    {
        a[i] = char(int( 'a'+ 26 * random (seed)));
        cout << "a["<< i <<"] = " << a[i] << endl;
    }
    return 0;
}
double random(unsigned int & seed)
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
[bmcfarlane4@erdos ~]$ g++ lab08.cpp
[bmcfarlane4@erdos ~]$ ./a.out

a[0] = b
a[1] = h
a[2] = p
a[3] = u
a[4] = t
a[5] = r
a[6] = k
a[7] = i
a[8] = g
a[9] = y
    
[bmcfarlane4@erdos ~]$
*/   
//          Name: Brandon McFarlane
//    Assignment: hw07
//      Due date: 04/04/2022
//   Description: Write a program that declares and fills an interger array of
//                size 20 with random integers each range [0,20] 
//                and ouputs all positions in the array that 
//                contain maximum number in the array.
//                For example, if the array is: 3 5 9 1 0 9
//                The output of your program should be: 3 5


#include <iostream>
#include <iomanip>

using namespace std;

double random(unsigned int & seed);
const int size = 20;
unsigned int seed =time(0);


int main ()
{
    int a[20];
    for (int i = 0; i < size; ++i)
    {
        a[i] = (int( size * random (seed)));
        //cout << "a["<< i <<"] = " << a[i] << endl;
    }
    int max = a[0];
    
    for (int j = 0; j < size; ++j)
    {
    if  (a[j] > max ) 
     {
        max = a[j];
     }
    }
    for (int k = 0; k < size; ++k)

      if (a[k] == max)
      {
        cout << " " << k;
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
[bmcfarlane4@erdos ~]$ g++ hw07.cpp
[bmcfarlane4@erdos ~]$ ./a.out

7 13
    
[bmcfarlane4@erdos ~]$
*/   
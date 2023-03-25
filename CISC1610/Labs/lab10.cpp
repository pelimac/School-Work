//          Name: Brandon McFarlane
//    Assignment: lab10
//      Due date: 04/11/2022
//   Description: Write a program that uses function fill_array (a)
//                to assign unique random intergers to array a

#include <iostream>
#include <iomanip>
#include <ctime>


const int SIZE = 10;
const int RANGE = 12;

unsigned int seed =time(0);

double random(unsigned int & seed);
void fill_array ( int a[] );
void print_array ( const int a[] );

using namespace std;

int main()
{
    int a [SIZE];
    
    fill_array (a);
    print_array (a);
    
    return 0;
}
    
void fill_array (int a[] )
{
    int i, r, current = 0;
    bool number_found;
    
    do 
    {
        r = int((RANGE + 1) * random(seed));
        number_found = false;
        i = 0;
        while( !number_found && i < current )
        {
            if ( a[i] == r ) 
                number_found = true; 
            ++i;
        }
        if ( !number_found )
        {
            a[current] = r;
            ++current;
        }
    }   while( current < SIZE);
}

void print_array ( const int a[] )
{
    cout << "array:  " ;
    for ( int i = 0; i < SIZE; ++i )
        cout << setw(4) << a[i];
    cout << endl;
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
=============
/u/erdos/students/bmcfarlane4
[bmcfarlane4@erdos ~]$ hw5

array:    3   6   0   5   1   8  12  11   7   9

[bmcfarlane4@erdos ~]$
*/
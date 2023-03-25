//          Name: Brandon McFarlane
//    Assignment: lab09
//      Due date: 04/04/2022
//   Description: 1. Declare three arrays of intergers, characters and double respectively
//                each array of size 10
//                2. while functions fill_array to populate each array, seperately
//                3. print all values in all arrays as shown below: 
//                 


#include <iostream>
#include <iomanip>

double random(unsigned int & seed);

const int SIZE = 10;

unsigned int seed =time(0);

void fill_array (int a[]);
void fill_array (char b[]);
void fill_array (double c[]);
void print_arrays ( const int a[], const char b[], const double c[]);

using namespace std;

int main ()
{
    int a[SIZE];
    char b[SIZE];
    double c[SIZE];

    fill_array (a);
    fill_array (b);
    fill_array (c);

    print_arrays( a, b, c);
    
    return 0;
}
    
void fill_array (int a[])
{
    for (int i = 0; i < SIZE; ++i)
        a[i] = (int)(11 * random (seed));
}

void fill_array (char b[])
{
    for (int i = 0; i < SIZE; ++i)
        b[i] = char(int( 'a'+ 26 * random (seed)));
}
    
void fill_array (double c[])
{
    for(int i = 0; i < SIZE; ++i)
        c[i] =  10 * random (seed);
}

void print_arrays (const int a[], const char c[], const double d[])
{
    cout << fixed << showpoint << setprecision (2);
    cout << "intger....character....double" << endl;
    for (int i=0; i < SIZE; ++i)
{
        cout << setw(4) << a[i] << "    ";
        cout << setw(5) << c[i] << "    ";
        cout << setw(7) << d[i] << "    " << endl;
}       
}

double random(unsigned int & seed)
{
    const int MODULUS = 15749;
    const int MULTIPLIER = 69069;
    const int INCREMENT = 1;
    seed = ((MULTIPLIER * seed)+ INCREMENT)% MODULUS;

    return double (seed)/MODULUS;
}
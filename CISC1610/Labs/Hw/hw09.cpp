//          Name: Brandon McFarlane
//    Assignment: hw09
//      Due date: 04/14/2022
//   Description: Write a function Partition (f, l, p, a) 
//which partitions array a into two parts, left and right.Elements of a in the left part should be smaller than p, and the elements of a great than or eqaul to p should be in the right part. 
//F should set to the first element of a partition of array a to be partioned,
//and l is the left element of a to be subjected to the partition.

#include <iostream>
#include <iomanip>
#include <ctime>


const int SIZE = 10;
unsigned int seed = time(0);

double random(unsigned int& seed);
void fill_array (int a[]);
void print_arrays (const int a[]);
void partition(int f, int l, int p, int a[]);
void swap(int &a, int &b);

using namespace std;

int main ()
{
    int f, l, p;
    int a[SIZE];
    
    fill_array(a);
  
    cout << "Original Array: " <<endl;
    print_arrays(a);
    cout<<endl;

    p = int ((SIZE+1) * random(seed));
    
    f = int ((SIZE-1) * random(seed));

    do 
  {
        l = int(SIZE * random(seed));
  } 
    while(l<=f);

        cout<<"First: "<<f<<endl;
        cout<<"Pivot: "<<p<<endl;
        cout<<"Last: "<<l<<endl;

    partition(f, l, p, a);
    
    cout << "Partitioned Array: " << endl;
    print_arrays(a);

  return 0;

} 

void fill_array(int a[])
{
    for (int i = 0; i < SIZE; i++) {
      a[i] = (int)(11 * random (seed));
    }
}

void swap(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void partition(int f, int l, int p, int a[])
{
    while (f < l)
    {

        while (f < l && a[f] < p) 
            f++;
    
        while (l > f && a[l] >= p) 
            l--;
      

        swap(a[f], a[l]);
    }
  }

void print_arrays(const int a[])
{
    for (int i=0; i < SIZE; ++i)
        cout << setw(4) << a[i] << "    ";
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
[bmcfarlane4@erdos ~]$ g++ hw09.cpp
[bmcfarlane4@erdos ~]$ ./a.out

   4      10       3       4       3       3       8       8       0       9    
First: 7
Pivot: 7
Last: 9
   4      10       3       4       3       3       8       0       8       9 
    
[bmcfarlane4@erdos ~]$
*/ 
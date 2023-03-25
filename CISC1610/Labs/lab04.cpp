//        Name: Brandon McFarlane
//  Assignment: lab04
//    Due date: 03/1/2022
// Description: Write a program that uses the function random(seed) to compute the value of pi

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double random(unsigned int & seed);
unsigned int seed = 20;

int main() 
{
  double x,y;
  int i, n_c = 0, total = 1000000;

  for ( i=0; i<total ; ++i)
  {
    x = random(seed);
    y = random(seed);  
      
    if(sqrt(x*x + y*y) < 1)
       ++n_c;
  }
  cout << fixed << showpoint << setprecision(4) << setw(8) << endl;
  cout << "pi = " << ((4.0 * n_c)/total) << endl;
  
  return 0;
}

double random(unsigned int&seed)
{
  const int MODULUS = 15749;
  const int MULTIPLIER = 69069;
  const int INCREMENT = 1;
  seed = ((MULTIPLIER * seed)+ INCREMENT)%MODULUS;

  return double (seed)/MODULUS;
}

/*
[bmcfarlane4@erdos ~]$ g++ lab04.cpp
[bmcfarlane4@erdos ~]$ ./a.out

   pi = 3.1491

[bmcfarlane4@erdos ~]$
*/    
    





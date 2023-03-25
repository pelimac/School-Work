//          Name: Brandon McFarlane
//    Assignment: hw08
//      Due date: 04/07/2022
//   Description: Declare and populate with random small letters an array of 150 characters 
//                and print the array only using one loop in the form of a matrix.
//                The output is 12 characters per line

#include <iostream>
#include <iomanip>

using namespace std;

double random(unsigned int & seed);
const int Size = 150;
unsigned int seed =time(0);

int main ()
{
    char a[13][12];
    int b , c, x = 0; 
    while(x < Size )  
{
     a[b][c] = char('a'+ 26 * random(seed));
    
      cout << a[b][c] << " ";
      c++;
      x++;
    
    if (c > 11)
    {
      c = 0;
      b++;

      cout << endl;
    }
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
[bmcfarlane4@erdos ~]$ g++ hw08.cpp
[bmcfarlane4@erdos ~]$ ./a.out

z u r w n w n n w u m j 
l g v q p p d y i s b v 
z w y t l p i y l q q t 
o n t h i f v j m v t o 
x e c h z h d n j z e t 
y d o n q x u u g c c y 
f a v w d s u q l d v l 
e d g h a k w v c x x g 
m v k x e u q g x r m h 
j o n x s x r k q w r h 
c z l b x f z u x y o f 
j q a c p k z m q p z s 
c a d m z q 
    
[bmcfarlane4@erdos ~]$
*/  
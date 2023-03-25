//          Name: Brandon McFarlane
//    Assignment: Hw11
//      Due date: 05/05/2022
//   Description: Write a program that randomly initializes elements of two interger matrixes
//                of size 5x5 with random intergers in range [0,5], and uses function matrix_multiply
//                to obtain the product of a*b
//                

#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

const int colmn_size = 5;
const int row_size = 5;

unsigned int seed = time(0);
void fill_array(int a[][colmn_size]);
void print_arrays(int a[][colmn_size]);
void matrix_multiply(int a[][colmn_size], int b[][colmn_size], int c[][colmn_size]);
double random(unsigned int& seed);

int main()
{
    int a[row_size][colmn_size];
    int b[row_size][colmn_size];
    int c[row_size][colmn_size];
    
    for( int i = 0; i < row_size; i++ )
        for( int j = 0; j < colmn_size; j++)
            c[i][j] = 0;

    cout << "matrix a:" << endl;
    fill_array(a);
    print_arrays(a);
    
    cout << "matrix b:" << endl;
    fill_array(b);
    print_arrays(b);
    
    cout << "matrix c:" << endl;
    matrix_multiply (a,b,c);

    print_arrays(c);

    return 0;
}

void fill_array(int a[][colmn_size])
{
    for (int row = 0; row < row_size; ++row) 
        for(int col = 0; col < colmn_size; ++col)
            
            a[row][col] = (0 + 6) * random(seed);
}

void print_arrays(int a[][colmn_size])
{
    for (int i = 0; i < row_size; i++) 
    {
      
        for (int j = 0; j < colmn_size; j++)
       
            cout << setw(4) << a[i][j] << "    ";
        cout << endl;
    } 
}

void matrix_multiply(int a[][colmn_size], int b[][colmn_size], int c[][colmn_size])
{
    for (int row = 0; row < row_size; row++)
        for (int colmn = 0; colmn < colmn_size; colmn++)
            for (int k = 0; k < row_size; k++)
                c[row][colmn] += a[row][k] * b[k][colmn];
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
[bmcfarlane4@erdos ~]$ g++ hw11.cpp
[bmcfarlane4@erdos ~]$ ./a.out
matrix a:
   0       2       4       2       4    
   4       0       4       1       5    
   4       5       4       2       3    
   0       4       5       2       4    
   3       4       4       5       0    
matrix b:
   3       3       2       5       2    
   0       4       4       3       5    
   1       3       1       5       2    
   4       0       0       0       2    
   1       3       3       1       0    
matrix c:
  16      32      24      30      22    
  25      39      27      45      18    
  27      53      41      58      45    
  17      43      33      41      34    
  33      37      26      47      44
[bmcfarlane4@erdos ~]$
*/  
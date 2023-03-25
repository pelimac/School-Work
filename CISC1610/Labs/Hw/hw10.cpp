//          Name: Brandon McFarlane
//    Assignment: Hw10
//      Due date: 05/02/2022
//   Description: Declare a [9 x 9] interger array 
//                Fill the array in the following way
//                1st colmm should have the values 1,2,3...9
//                2nd colmm should have the # in the print colmm multiplied by 2
//                3rd colmm should have the # in the list multiplied by 3 etc.


#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

const int colmn_size = 9;
const int row_size = 9;

int digital_root (int n);
void fill_array (int a[row_size][colmn_size]);
const void print_arrays (int a[row_size][colmn_size]);

int main()
{
    int a[row_size][colmn_size];
    
    cout << "Initial matrix:" << endl;
    fill_array(a);
    
    print_arrays(a);
    cout << endl;
    
    cout << "Matrix using digital_root:" << endl;
    for (int i = 0; i < row_size; i++)
    {
        
        for (int j = 0; j < colmn_size; j ++)
            a[i][j] = digital_root(a[i][j]);
    }
    print_arrays(a);
    
    return 0;
}

void fill_array(int a[row_size][colmn_size])
{
    for (int i = 0; i < row_size; i++) 
    {
      
      for (int j = 0; j < colmn_size; j ++)
            a[i][j] = ( i + 1 ) * ( j + 1 );
    }
}


const void print_arrays (int a[row_size][colmn_size])
{
    for (int i = 0; i < row_size; i++) 
    {
      
        for (int j = 0; j < colmn_size; j++)
       {
            cout << setw(4) << a[j][i] << "    ";
       }
            cout << endl;
    } 
}

int digital_root(int n)
{
   int sum;   
      do
   {
      sum = 0;
      while( n > 0 )
      {
         sum += n % 10;
         n /= 10;
      }
      n = sum;
   }  while( n >= 10 );
   return sum;
}

/*
Sample Output:
==============
[bmcfarlane4@erdos ~]$ g++ hw10.cpp
[bmcfarlane4@erdos ~]$ ./a.out

Initial matrix:
   1       2       3       4       5       6       7       8       9    
   2       4       6       8      10      12      14      16      18    
   3       6       9      12      15      18      21      24      27    
   4       8      12      16      20      24      28      32      36    
   5      10      15      20      25      30      35      40      45    
   6      12      18      24      30      36      42      48      54    
   7      14      21      28      35      42      49      56      63    
   8      16      24      32      40      48      56      64      72    
   9      18      27      36      45      54      63      72      81    

Matrix using digital_root:
   1       2       3       4       5       6       7       8       9    
   2       4       6       8       1       3       5       7       9    
   3       6       9       3       6       9       3       6       9    
   4       8       3       7       2       6       1       5       9    
   5       1       6       2       7       3       8       4       9    
   6       3       9       6       3       9       6       3       9    
   7       5       3       1       8       6       4       2       9    
   8       7       6       5       4       3       2       1       9    
   9       9       9       9       9       9       9       9       9    
[bmcfarlane4@erdos ~]$
*/  
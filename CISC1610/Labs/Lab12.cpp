//          Name: Brandon McFarlane
//    Assignment: Lab12
//      Due date: 05/02/2022
//   Description: Write a program that declares a 2 dimensional array in the following:    
//                There are 0's in the main diagonal. There are positive random intergers in the range [0,5) above the main diagonal
//                and there are negative random intergers in the range [-5,-10] below the main diagonal

#include <iostream>
#include <iomanip>
#include <ctime>

const int row_size = 10;
const int colmn_size = 10;

unsigned int seed = time(0);

double random(unsigned int& seed);
void fill_array (int a[][colmn_size]);
void print_arrays (const int a[][colmn_size]);

using namespace std;

int main()
{
    int a[row_size][colmn_size];
    
    fill_array(a);
    print_arrays(a);

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

void fill_array(int a[][colmn_size])
{
    for (int row = 0; row < row_size; ++row) 
        for(int col = 0; col < colmn_size; ++col)
    {
            if ( row > col )
                a[row][col] = 5 * random(seed);
            else
                if ( row < col )
                    a[row][col] = -10 + 5 * random(seed);
                else 
                    a[row][col] = 0;  
    }
}

void print_arrays (const int a[row_size][colmn_size])
{
    for (int i = 0; i < row_size; i++) 
    {
      
        for (int j = 0; j < colmn_size; j++)
       
            cout << setw(4) << a[j][i] << "    ";
            
            cout << endl;
    } 
}
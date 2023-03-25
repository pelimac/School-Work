/* Brandon McFarlane
CISC 2000
InflationRate Part 2
*/

//This program calculates the inflation rate given two Consumer Price Index values and prints it to the monitor.

#include <iostream>
using namespace std;

double calcInflationRate(float old_cpi, float new_cpi);  

int main() //C++ programs start by executing the function main
{
    // TODO #1: declare two float variables for the old consumer price index (cpi) and the new cpi
float old_cpi, new_cpi, total_cpi = 0; 
int k = 0;
char again;

  do // Loop for getting old and new cpi's and priting the valid results
  {

    // TODO #2: Read in two float values for the cpi and store them in the variables<br>
    cout << "Enter old and new consumer price inndices: ";
    cin >> old_cpi >> new_cpi;

    // TODO #4: 2. Put the logic in TODO #2-4 into a loop that asks the user to enter 'y' (or 'Y') if there's more data to be entered.
    // Keep a running total of the valid inﬂation rates and the number of computed rates to calculate the average rate.

    //Calls the function InflationRate with the two cpis
    calcInflationRate(old_cpi, new_cpi);

    cout << "Inflation rate is: " << calcInflationRate(old_cpi,new_cpi) << endl;

    //Keeps a running total of the valid inflation rates
    total_cpi += calcInflationRate(old_cpi, new_cpi);

    //Keeps a counter of the number of valid computed rates
     if (calcInflationRate(old_cpi, new_cpi) != 0)
	    k++;

    //Asks the user if they would like to continue to enter more data
    cout << "Try again? (y or Y)?";
    cin >> again;

  }while((again == 'Y') || (again =='y'));
    
    //Calculates the average rate
    cout << "Average rate is " << total_cpi /(k);
    cout << endl;

    return 0;

}

// double calcInflationRate(float old_cpi, float new_cpi)
// precondition:   both prices must be greater than 0.0
// postcondition:  the inflation rate is returned or 0 for invalid inputs
double calcInflationRate(float old_cpi, float new_cpi)
{
   // TODO: Implement InflationRate to calculate the percentage increase or decrease
  if(new_cpi > 0 && old_cpi > 0.0)
  {
     double i = (new_cpi - old_cpi) / old_cpi * 100;

     return i ;
  }  
  
  return 0;
}


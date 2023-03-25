/* Brandon McFarlane
CISC 2000
InflationRate Part 3
*/

//This program calculates the inflation rate given two Consumer Price Index values and prints it to the monitor.

#include <iostream>
using namespace std;

const int maxRates = 20;
double calcInflationRate(float old_cpi, float new_cpi);  
double medianCalc (double maxRates[],int valid_cpi);
void sortArray(double maxRates[], int valid_cpi);
void getCPIvalues(float& old_cpi, float& new_cpi);
void swapValues(double& a, double& b);

int main() //C++ programs start by executing the function main.
{
// TODO #1: declare two float variables for the old consumer price index (cpi) and the new cpi.
float old_cpi = -1, new_cpi = -1; 
double inflationRate, averageRate, inflationRates[maxRates],sum = 0;
int valid_cpi = 0;
char again;

do
{
  //Add a function to get the CPI values from the user and validate that they are greater than 0.

  getCPIvalues(old_cpi, new_cpi); 
  
  inflationRate = calcInflationRate(old_cpi, new_cpi);
  cout << "Inflation rate is: " << inflationRate << endl;
  
  inflationRates[valid_cpi] = inflationRate;

  cout << "Try again? (y or n)\n";
  cin >> again;
  sum = sum + inflationRate;
if (inflationRate != 0)
  valid_cpi++;

  if (valid_cpi == maxRates)
    {
     again = 'n';
    }

}while(((again == 'Y') || (again =='y'))&& (valid_cpi < 21));
averageRate = sum / valid_cpi;
    cout << "Average rate is: " << averageRate << endl;    
  cout << "Median rate is: " << medianCalc (inflationRates, valid_cpi) <<  endl;
  
return 0;
}

double calcInflationRate(float old_cpi, float new_cpi) //Calculates inflationRate by comparing new and old cpi values.
{
   // TODO: Implement InflationRate to calculate the percentage increase or decrease
  if(new_cpi > 0 && old_cpi > 0.0)
  {
     double i = (new_cpi - old_cpi) / old_cpi * 100;

     return i ;
  }  
  
  return 0;
}

void getCPIvalues(float& old_cpi, float& new_cpi)//takes two float reference parameters for the old_cpi and new_cpi and validates inputs.
  
{
    do
    {
        if ((old_cpi != -1) && (new_cpi !=  -1)) 
            cout << "Error: CPI values must be greater than 0."; // and try to get data again.
        cout << "Enter old and new cpi: ";
          cin >> old_cpi >> new_cpi; 

    }while((old_cpi == 0) || (new_cpi == 0));

}

void sortArray (double maxRates[], int valid_cpi) //sorts the values in an array of doubles into ascending order.
{
int smallestNum;
    for (int i = 0; i < valid_cpi- 1; i++)
    {
        smallestNum = i;
        for (int j = i + 1; j < valid_cpi; j++)
        {
            if (maxRates[j] < maxRates[smallestNum])
            {
                smallestNum = j;
            }
        }
        swapValues(maxRates[smallestNum], maxRates[i]);
    }
}
double medianCalc (double maxRates[],int valid_cpi) //calculates the median inflation rate using sort function.
{
    sortArray(maxRates, valid_cpi);
    if (valid_cpi % 2 != 0)
    return (double)maxRates[valid_cpi / 2];

    return (double)(maxRates[(valid_cpi - 1) / 2] + maxRates[valid_cpi / 2]) / 2.0;
}

void swapValues(double& a, double& b) //swaps the values in an array of doubles.
{
    double temp = a;
    a = b;
    b = temp;

}
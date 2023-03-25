#include <iostream>
using namespace std;


double calcInflationRate(float old_cpi, float new_cpi);  


int main() 
{
double old_cpi, new_cpi; 
char again;

  do 
  {
      cout << "Enter the price of the item when you bought it: ";
      cin >> old_cpi;

      cout << "Enter the price of the item today: ";
      cin >> new_cpi;

      cout << "The inflation rate is: " << calcInflationRate(old_cpi,new_cpi) << endl;

      cout << "Would you like to try another item (y/n)?";
      cin >> again;

  }while((again == 'Y') || (again =='y'));

  return 0;

}

double calcInflationRate(float old_cpi, float new_cpi)
{
   // TODO: Implement InflationRate to calculate the percentage increase or decrease
  if(new_cpi > 0 & old_cpi > 0)
  {
     double i = (new_cpi - old_cpi) / old_cpi * 100;
      
      return i;
  }
  
  return 0;
}
/* mostexpensive.cpp
Brandon McFarlane
CISC2200 */

#include <iostream> 
#include <string>
#include <iomanip>
#include <cmath>   
using namespace std;

const int MAX_N = 10;  // define a constant to store the maximum number of items

// Define a structure to store each item's name and price
struct Item 
{
  string name;
  double price;
};

void BubbleSort(Item items[], int n) 
{
   Item temp; // temporary variable to store an item during swap
   for (int i = 0; i < n - 1; i++) 
   {
      for (int j = 0; j < n - i - 1; j++) 
      {
         // Compare the current item's price with the next item's price
         if (items[j].price < items[j + 1].price) 
         {
            // Swap the items if the current item's price is greater than the next item's price
            temp = items[j];
            items[j] = items[j + 1];
            items[j + 1] = temp;
         }
      }
   }
}

int main() 
{
    double money;  // variable to store the available money
    int n;         // variable to store the number of item types
    
    // Read the available money and the number of item types from the input
    cin >> money >> n;

    if (n > MAX_N) 
    {
    cout << "Error: Maximum number of item types is " << MAX_N << endl;
    return 1;  // return non-zero value to indicate unsuccessful termination of the program
    }
    
    Item items[MAX_N];  // array to store the items
    
    // Read the name and price of each item from the input
    for (int i = 0; i < n; i++) 
    {
        cin >> items[i].name >> items[i].price;
    }
    
    // Sort the items based on their price

    BubbleSort(items, n);
    
    int count = 0;  // variable to keep track of the number of items purchased
    
    // Loop through the items and purchase the items that can be bought with the available money
    for (int i = 0; i < n; i++) 
    {
        if (money >= items[i].price) 
        {
            money -= items[i].price;  // subtract the price of the item from the available money
            cout << items[i].name << " " << items[i].price << endl;  // print the item name and price
            count++;
        }
    }
    
    // Print the remaining money
    
    cout << fixed << setprecision(2) << endl; 
    cout << "Remaining: " << money << endl;


    
    return 0;  // return 0 to indicate successful termination of the program
}


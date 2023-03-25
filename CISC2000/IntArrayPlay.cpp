/* Brandon McFarlane
CISC 2000
IntArrayPlay
*/

#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

const int CAPACITY = 20;
void displayArray(int a[], int numberElements);
void fillArray(int a[], int numberElements);
int searchElement(int a[], int numberOfElements, int element);
int insertElement(int a[], int &numberElements, int position, int target);
int findInsertPosition(int a[],int numberElements, int value);
void removeElement(int a[], int &numberElements, int position);
bool isArraySorted(int a[], int &numberElements);



int main()
{
    //ToDo: Declare a function fillArray that fills an int array with values entered
    // by the user. Stop reading when the user inputs -1 or you reach CAPACITY.
  
  int NumArray[CAPACITY];
  int NumArrayElems = 0;

  fillArray(NumArray, NumArrayElems);
  
  displayArray(NumArray, NumArrayElems);

  // 2. ToDo: Read in a value and position from the user. Call your

// insertElement function

// to insert the given value into the given position of the array

// Display the contents of the array afterwards

  int position, value;

  cout << "Enter a value and a position to insert: ";

  cin >> value >> position;

  insertElement(NumArray, NumArrayElems, position, value);

  displayArray(NumArray, NumArrayElems);

// 3. ToDo: Read in a value and call your searchElement function.

  cout << "Enter a value to delete from the array: ";

  cin >> value;

  position = searchElement(NumArray, NumArrayElems, value);

// 4. if the value is found, delete it from the array using your

// deleteElement function

// if the value not found, print "Value not found!"

// Display the contents of the array afterwards

    if (position != -1)

  removeElement(NumArray, NumArrayElems, position);

      else

        cout << "Value not found!" << endl;

  displayArray(NumArray, NumArrayElems);

// 5. TODO: Read in a value and call your insertElement function to append

// a value to the end of the array

// Display the contents of the array afterwards

  cout << "Enter a value to append: ";

  cin >> value;

  insertElement(NumArray, NumArrayElems, NumArrayElems, value);

  displayArray(NumArray, NumArrayElems);

  
}

void displayArray(int a[], int numberElements) //displays the array on a single line separated by blanks.
{
  for(int i = 0; i < numberElements; i++)
  {
    cout << setw(4) << a[numberElements] << "  ";
  }
}


void fillArray(int a[], int numberElements) //fills an int array with values entered by the user.
{
  cout<<"Enter a list of up to 20 integers or -1 to end the list"<<endl;

  int value;

  int i=0;

  cin>>value;

  while(value!=-1 && i<CAPACITY)
{
  a[i] = value;

  cin>>value;

  i++;

}

  numberElements = i;

}

void removeElement(int a[], int &numberElements, int position) // removes the element of the given index from the given array.
{

  for(int i=position; i<numberElements-1; i++)
{

  a[i] = a[i+1];

}
  
  numberElements--;

}



int insertElement(int a[], int &numberElements, int position, int target) //removes the element of the given index from the given array.
{
  if (a[CAPACITY - 1] != 0 && numberElements > a[CAPACITY - 1]) 
{
		cout << "Error: array is full" << endl;
}

  for(int i=numberElements-1; i>=position;i--)
{

  a[i+1] = a[i];

}

  a[position] = target;

  numberElements++;
}


int searchElement(int a[], int numberOfElements, int element) //searches for the element in the given array.
{

  for(int i =0;i<numberOfElements; i++)
  {

   if(a[i]==element)
   {

    return i;

   }

  }

return -1;

}


bool isArraySorted(int a[], int CAPACITY) //goes thru the elements checking to see if they are in order.
{
  {
	bool boolSorted = true;

	for (int i = 1; i < CAPACITY; i++) 
  {
		if (a[i] != 0 && a[i] < a[i - 1]) 
    {
			boolSorted = false;
		}
	}
	return boolSorted;
}
}


int findIndexInsertPos(int a[], int CAPACITY, int insertValue) //looks thru an ordered array to find the position of the value to insert.
{
	for (int i = 0; i < CAPACITY; i++) 
  {
		if (a[i] > insertValue || a[i] == 0) 
    {
			return i;
		}
	}
}
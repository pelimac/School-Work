/* Brandon McFarlane
CISC 2200
ArrayBag
*/
//highArray.cpp
//demonstrates array class with high-level interface

#include <iostream>

#include <vector>

using namespace std;

////////////////////////////////////////////////////////////////

class HighArray {

  private:
    vector < double > v; //vector v

  int nElems; //number of data items
  public:
    //--------------------------------------------------------------
    HighArray(): nElems(0) //default constructor
  {}
  //--------------------------------------------------------------
  HighArray(int max): nElems(0) //1-arg constructor
  {
    v.resize(max);
  } //size the vector
  //--------------------------------------------------------------
  bool find(double searchKey) //find specified value
  {
    int j;
    for (j = 0; j < nElems; j++) //for each element,
      if (v[j] == searchKey) //found item?
        break; //exit loop before end
    if (j == nElems) //gone to end?
      return false; //yes, can't find it
    else
      return true; //no, found it
  } //end find()
  //--------------------------------------------------------------
  void insert(double value) //put element into array
  {
    v[nElems] = value; //insert it
    nElems++; //increment size
  }
  //--------------------------------------------------------------
  bool remove(double searchKey) 
  {
      if(find(searchKey)) { //if item to be removed is found,
          for (int i = 0; i < nElems; i++)
          {
              if(v[i] == searchKey) { //shift all the elements above down
                  for(int j = i + 1; j < nElems; j++)
                      v[j-1] = v[j];
              }
          }
          nElems--; //decrement size
          return true;
      }
      else
          return false; // item to be removed not found
    }
    //--------------------------------------------------------------
  int getMax() // gets the maximum
  {
      int max = 0;
      if (nElems == 0) //empty array
        return -1; //return -1

      else {
        for (int i = 1; i < nElems; i++) { 
          if (v[i] > v[max]) 
            max = i; 
        } 
        return v[max]; 
      }
    } 
//--------------------------------------------------------------
  int removeMax() // removes the maximum
  {

    int max = 0; // This variable holds the index of currently maximum element

    if (nElems == 0) // Empty array 
      return -1; 

    else { 
      for (int i = 1; i < nElems; i++) { // Iterate through array and find the index of maximum element
        if (v[i] > v[max]) 
          max = i; 
      } 
      int maxElement = v[max]; // Store the maximum element 
      for (int i = max; i < nElems - 1; i++) { // Loop through array starting at the index of maximum element
        v[i] = v[i+1]; // Change values of max element from last to begining
      } 
      nElems--; // Decrement
      return maxElement; 
    } 
  }

  int getNElems()
  {
    return nElems;
  }
  //--------------------------------------------------------------
  void display() //displays array contents
  {
    for (int j = 0; j < nElems; j++) //for each element,
      cout << v[j] << " "; //display it
    cout << endl;
  }
  //--------------------------------------------------------------
  
}; //end class HighArray
////////////////////////////////////////////////////////////////
int main() {
  int maxSize = 100; //array size
  HighArray arr(maxSize); //vector
  arr.insert(77); //insert 10 items
  arr.insert(99);
  arr.insert(44);
  arr.insert(55);
  arr.insert(22);
  arr.insert(88);
  arr.insert(11);
  arr.insert(0);
  arr.insert(66);
  arr.insert(33);
  arr.display(); //display items

  //create a new array to store the values in reverse order



  int searchKey = 35; //search for item
  if (arr.find(searchKey))
    cout << "Found " << searchKey << endl;
  else
    cout << "Can't find " << searchKey << endl;
  cout << "Deleting 0, 55, and 25" << endl;
  arr.remove(0); //delete 3 items

  arr.remove(55);

  arr.remove(25);
  arr.display(); //display items again
  cout << "getMax() returned" << endl;
  cout << arr.getMax() << endl; //get the max value
  cout <<"After calling removeMax()" << endl;
  arr.removeMax(); //remove the max value
  arr.display(); //display items again
  
  HighArray reverseArray(maxSize);
  int c = arr.getNElems();
  for (int i = 0; i < c; i++) //loop through array and store value in reverse order in the new array
  {
    int value = arr.getMax();
    reverseArray.insert(value);
    arr.removeMax();
  }
  cout <<"Sorting using removeMax()" <<endl;
  reverseArray.display(); //display items
  

  return 0;
} //end main()
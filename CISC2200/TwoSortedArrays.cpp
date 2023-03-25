/*Brandon McFarlane
  CISC 2200
  TwoSortedArrays.cpp
 */

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAX_NUM = 99;

// Function to fill an array with random numbers
void fillArray(int arr[], int size) 
{
    for (int i = 0; i < size; i++) 
    {
        arr[i] = rand() % MAX_NUM;
    }
}

// Function to sort an array using selection sort
void sortArray(int arr[], int size) 
{
    int minIndex, temp;
    for (int i = 0; i < size - 1; i++) 
    {
        // initialize minimum index to current index
        minIndex = i;
        for (int j = i + 1; j < size; j++) 
        {
            // find index of minimum element
            if (arr[j] < arr[minIndex]) 
            {
                minIndex = j;
            }
        }
        // swap current element with minimum element
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

// Function to merge two arrays in-place
void mergeArrays(int A[], int a, int B[], int b)
{
    int i = 0, j = 0; // initialize two pointers, i for array A and j for array B
    while (i < a && j < b) 
    {
        // compare elements from both arrays and insert smaller element into array A
        if (A[i] <= B[j]) 
        {
            i++; // move pointer i to next element in array A
        } else 
        {
            int temp = A[i]; // store the current element in array A into a temp variable
            A[i] = B[j]; // replace the current element in array A with the smaller element from array B
            int k = 0;
            // loop through array B to find the correct position for temp
            while (k < j && B[k] <= temp) 
            {
                k++;
            }
            // Shift elements in array B to make room for temp
            for (int l = j; l > k; l--) 
            {
                B[l] = B[l-1];
            }
            B[k] = temp; // insert temp into the correct position in array B
            j++; // move pointer j to next element in array B
        }
    }

}


// Function to merge two arrays into a new array
void mergeArraysToNewArray(int A[], int a, int B[], int b, int C[]) 
{
    int i = 0, j = 0, k = 0;
    while (i < a && j < b) 
    {
        // compare elements from both arrays and insert smaller element into array C
        if (A[i] <= B[j]) 
        {
            C[k++] = A[i++];
        } else 
        {
            C[k++] = B[j++];
        }
    }
    // insert remaining elements from array A into array C
    while (i < a) 
    {
        C[k++] = A[i++];
    }
    // insert remaining elements from array B into array C
    while (j < b) 
    {
        C[k++] = B[j++];
    }
}

// Function to display an array
void displayArray(int arr[], int size) 
{
    for (int i = 0; i < size; i++) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() 
{
    int a, b;
    srand(time(0));
    cout << "Enter a, b: ";
    cin >> a >> b;
    int A[a], B[b], C[a + b];
    fillArray(A, a);
    fillArray(B, b);
    sortArray(A, a);
    sortArray(B, b);
    cout << "Input:" << endl;
    displayArray(A, a);
    displayArray(B, b);
    mergeArrays(A, a, B, b);
    cout << "Output:" << endl;
    displayArray(A, a);
    displayArray(B, b);
    mergeArraysToNewArray(A, a, B, b, C);
    cout << "Merged:" << endl;
    displayArray(C, a + b);
    return 0;
}

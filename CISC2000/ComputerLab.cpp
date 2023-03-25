/* Brandon McFarlane
CISC 2000
ComputerLab.cpp
*/

#include <iostream>

using namespace std;

// Type definition
typedef int* IntPtr;

// Constants
const int NUMLABS = 4;

// Function prototypes

/*
 Creates the dynamic arrays for the labs.
 @param labs: the array of labs,
 @param labsizes: contains the size (or number of computers) of each lab
  This dictates the size of the dynamic array.
 @precondition: labsize[0] is the # of computers in lab1,
                labsize[1] is the # of computers in lab2, ...
 @postcondition: labs[0] points to lab1's array (of size given by labsize[0])
      labs[1] points to lab2's array (of size given by labsize[1])
        ...
*/
void createArrays(IntPtr labs[], int labsizes[]);

/* 
freeArrays:
Releases memory we allocated with "new".
*/
void freeArrays(IntPtr labs[]);


/*
showLabs:
Displays the status of all labs (who is logged into which computer).
*/
void showLabs(IntPtr labs[], int labsizes[]);


// ======================
// login:
// Simulates a user login by asking for the login info from
// the console.
// ======================
void login(IntPtr labs[], int labsizes[]);


// ======================
// logout:
// Searches through the arrays for the input user ID and if found
// logs that user out.
// ======================
void logout(IntPtr labs[], int labsizes[]);


// ======================
// search:
// Searches through the arrays for the input user ID and if found
// outputs the station number.
// ======================
void search(IntPtr labs[], int labsizes[]);


// ======================
//     main function
// ======================
int main()
{
	IntPtr labs[NUMLABS]; 	// store the pointers to the dynamic array for each lab
	int labsizes[NUMLABS];	// Number of computers in each lab
	int choice = -1;
	
	cout <<"Welcome to the LabMonitorProgram!\n";

	// Prompt the user to enter labsizes 
	cout <<"Please enter the number of computer stations in each lab:\n"; 
	for (int i=0; i< NUMLABS; i++)
	{
		do
		{
			cout <<"How many computers in Lab "<< i+1<<"?";
			cin >> labsizes[i]; 
		} while (labsizes[i]<0); 
	}

	// Create ragged array structure
	createArrays(labs, labsizes);
	
	// Main Menu
	while (choice != 0)
	{
		cout << endl;
		cout << "MAIN MENU" << endl;
		cout << "0) Quit" << endl;
		cout << "1) Simulate login" << endl;
		cout << "2) Simulate logout" << endl;
		cout << "3) Search" << endl;
		cin >> choice;
		if (choice == 1)
		{
			login(labs, labsizes);
			showLabs(labs, labsizes);
		}
		else if (choice == 2)
		{
			logout(labs, labsizes);
			showLabs(labs, labsizes);
		}
		else if (choice == 3)
		{
			search(labs, labsizes);
		}
	}

	freeArrays(labs);		// Free memory before exiting
	cout << "Bye!\n";
	return 0; 
}


/* createArray funtion:
	create the 2d array with both lab numbers and statestion numbers;
	create the array with proper size in column matched with labsize;
	for example: labsizes[0]=7, we create the labs[0][7];
	pre: array labs with first dimention(lab_num) deternmined and second dimention( station_num) undetermined;
	post: 2d array with both dimentions determined and elements initialized to -1;
 */
void createArrays(IntPtr labs[], int labsizes[])
{
	int lab_num = 0, station_num=0;
	for (lab_num = 0; lab_num<NUMLABS; lab_num++)
	{
		labs[lab_num] = new int[labsizes[lab_num]];

		for (station_num=0; station_num<labsizes[lab_num]; station_num++)
		{
			labs[lab_num][station_num] = -1;
		}
	}

}

/* freeArrays:
	free the array memory with delet operator;
	delete with the reversed order as the new one;
	pre: 2d array with allocated memory;
	post: memory of the array is free;
 */
void freeArrays(IntPtr labs[])
{
  for (int i=0; i<NUMLABS; i++)
  {
	  delete[] labs[i]; // deleting the 2rd dimention
  }
  //delete[] labs; //deleting the 1st dimention 
}

/*  showLabs:
    Displays the status of all labs (who is logged into which computer).
	Precondition: labs[] is a multidimension array of labs with computers
				  labsizes[i] contains the size of the array in labs[i]
 */
void showLabs(IntPtr labs[], int labsizes[])
{

	int i;
	int j;

	cout << "LAB STATUS" << endl;
	cout << "Lab #     Computer Stations" << endl;
	for (i=0; i < NUMLABS; i++)
	{
		cout << i+1 << "         ";
		for (j=0; j < labsizes[i]; j++)
		{
			cout << (j+1) << ": ";
			if (labs[i][j] == -1)
			{
				cout << "empty ";
			}
			else
			{
				cout << labs[i][j] << " ";
			}
		}
		cout << endl;
	}
	cout << endl;
	return;
}

/* login:
   Simulates a user login by asking for the login info from the console. 
   Reads the user-id, the lab and the computer then assigns the id to labs[lab-1][computer-1]
   Precondition: labs is a multidimension array of labs with computers
                 labsizes[i] is the size of the array in labs[i]
   Postcondition: labs[lab-1][computer-1] = user-id
 */
void login(IntPtr labs[], int labsizes[])
{
	int id, lab, num = -1;

	// read user id 
	do
	{
  		cout << "Enter the 5 digit ID number of the user logging in:" << endl;
		cin >> id;
	} while ((id < 10000) || (id > 99999));

	// read the lab number 
	do 
	{
		cout << "Enter the lab number the user is logging in from (1-" <<
			NUMLABS << "):" << endl;
		cin >> lab;
	} while ((lab <= 0) || (lab > NUMLABS));

	//read computer number 
	do
	{
		cout << "Enter computer station number the user is logging in to " <<
			"(1-" << labsizes[lab-1] << "):" << endl;
		cin >> num;
	} while ((num <= 0) || (num > labsizes[lab-1]));

	// Check to see if this station is free
	if (labs[lab-1][num-1]!=-1)
	{
		cout << "ERROR, user " << labs[lab-1][num-1] <<
			" is already logged into that station." << endl;
		return;
	}
	// Assign this station to the user
	labs[lab-1][num-1] = id;
	return;
}


/* logout:	
	pre: given array labs and labsized, and the targetid that need to be deleted;
	search for the targetid:
	if found, set the element to -1 (empty);
	if not found, output userid not found;
 */
void logout(IntPtr labs[], int labsizes[])
{
	int targetid, i, j, last= labsizes[3]-1;;
	// read user id 
	do
	{
  		cout << "Enter the 5 digit ID number of the user logging in:" << endl;
		cin >> targetid;
	} while (( targetid < 10000) || (targetid > 9999));

    for (i=0; i<NUMLABS; i++)
    {
	    for (j=0; j<labsizes[i]; j++)
	    {
		    if (labs[i][j] == targetid)
		    {
				labs[i][j] = -1; //set this computer station to empty
				cout << "Logout user " << targetid << " in Lab " << i+1 << " at computer " << j+1 << endl;

				//break out of both for-loop
				return;
			    /* j =labsizes[i];
			    i = NUMLABS; */
		    }
		    if (i == 3 && j == last) // if targetid is not found 
		    {
			    cout << "User not logged in." << endl; 
		    } 
	    }
	}
}

/* search function:	
	given the target ID, search the location of the target ID;
	if there exists target id output the location;
	if not, output users not loggin;
	no changees made to the lab array;
 */
void search(IntPtr labs[], int labsizes[])
{
  int targetID, i, j, last= labsizes[3]-1;
  cout << "Enter the 5 digit ID number of the user logging in:"<< endl;
  cin  >> targetID;

  for (i=0; i<NUMLABS; i++)
  {
	  for (j=0; j<labsizes[i]; j++)
	  {
		  if (labs[i][j] == targetID)
		  {
			  cout << "User " << targetID << " logged in Lab " << i+1 << " at computer " << j+1 << endl;
			  return;
			  /* j =labsizes[i];
			  i = NUMLABS; */
		  }
		  if (i == 3 && j == last)
		  {
			  cout << "User not logged in." << endl; 
		  } 
	  }
  }
 
}
//Name:Brandon McFarlane
//Assignment:Lab1
//Date:1/31/2022
//Description: Write a program that inputs 3 interger values and the outputs the average of the numbers entered

#include <iostream>
#include <iomanip>

using namespace std;
    
int score_1, score_2, score_3;
double average;

int main()
{
    cout << "1:";
    cin >> score_1;
    cout << "2:";
    cin >> score_2;
    cout << "3:";
    cin >> score_3;
    average = (score_1 + score_2 + score_3)/3;
    
    cout << fixed << showpoint << setprecision(3);
    cout << "average = " << average << endl;

    return 0;
}
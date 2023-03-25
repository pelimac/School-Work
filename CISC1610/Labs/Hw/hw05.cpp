//        Name: Brandon McFarlane
//  Assignment: hw5
//    Due Date: 03/21/2022
// Description: Write a program that given the ellispe: (x*x)/a*a + (y*y)/b*b -1
//              Find the sides of the rectangle inscribed in the ellipse which has the maximum area.
//              Output 2x and 2y as well as the area of the largest rectangle.
//        File: hw5.cpp

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    double a, b, x1, x2, y1, y2, increment = 0.001, area1, area2;

    cout << fixed << showpoint << setprecision(3);

    cout <<"a: ";
    cin >> a;
    cout <<"b: ";
    cin >> b;

    x1 = 0;
    x2 = 0.001;
    y1 = b * sqrt(a * a - x1 *x1) /a;
    y2 = b * sqrt(a * a - x2 *x2) /a;

    area1 = 4*(x1 * y1);
    area2 = 4*(x2 * y2);

    while (abs(area1-area2) > 0.001)
    {
        if (area1 > area2)
      {
         x2 += 0.002;
         y2 = b* sqrt(a*a - x2*x2)/a;
         area2 = (4*(x2+x2)) * (4*(y2+y2));
      } 
      else if (area2 > area1)
      {
         x1 += 0.002;
         y1 = b * sqrt(a*a - x1*x1)/a;
         area1 = (4*(x1+x1)) * (4*(y1+y1));
      }
      
      cout << area1 << endl;
      cout << area2 << endl;
   }
   cout << endl << endl;
   cout << "Area 2 is : "<< area2 << endl;
   cout << "Area 1 is : " << area1 << endl;
   
   return 0;
}
/*
Sample Output:
=============
/u/erdos/students/bmcfarlane4
[bmcfarlane4@erdos ~]$ hw5

a: 0.2
b: 0.34

Area 2 is : 2.175
Area 1 is : 2.176

[bmcfarlane4@erdos ~]$
*/
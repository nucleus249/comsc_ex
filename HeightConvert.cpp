// Program Assignment: 1
// Program Name: HeightConvert.cpp
// Author Name: Nicholas Vaughan
// Date: 2/8/2016
// Course: COMSC 1450-A/

          
#include <iostream>

using namespace std;

int main()
{
   int feet;
   int inches;
   double cm;

   //Ask for input and store in variables feet and inches.
   cout << "Enter feet component of height:\n";
   cin >> feet;

   cout << "Enter inches component of height:\n";
   cin >> inches;

   //Calculate centimeters using input.
   cm = (feet * 12 + inches) * 2.54;

   //Display result.
   cout << "That height is equal to " << cm << " centimeters.\n\n";

   return 0;

}


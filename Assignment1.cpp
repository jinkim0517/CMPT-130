/*
Program to find the area of a circle, and convert distances to other units when given values.
Author: Jin Kim
Date: September 2021
*/

#include <iostream>
using namespace std;

const double PI = 3.1415926535;
const double M2FT_RATIO = 3.2808399;
const double FURLONG_RATIO = 0.004971;
const double LIGHT_RATIO = (3.33564e-9);
const int INCH2FT_RATIO = 12;

int main() {
  
//Circle area title
  cout << "\nCIRCLE AREA" << endl << "---------------------" << endl;
  
// Prompt user for radius of circle
  double radius = 0;
  
  cout << "Enter the radius of the circle: ";
  cin >> radius;
  cout << "You entered " << radius << " as the radius." << endl;
  
// Calculating and printing the area of the circle
  cout << "The area of a circle with a radius of: " << radius << " is " << radius * radius * PI << "." << endl << endl;

// Distance conversion title
  cout << "DISTANCE CONVERSION" << endl << "---------------------" << endl;
  
// Prompt user for distance to be converted
  double distance_m = 0;
  
  cout << "Enter the distance in metres: ";
  cin >> distance_m;
  cout << distance_m << " metres will be converted into feet + inches, furlongs, and time for light to travel." << endl << endl;
  
// Convert metres to feet and inches
  int distance_ft = distance_m * M2FT_RATIO;
  
  double distance_inch = (distance_m * M2FT_RATIO - distance_ft) * INCH2FT_RATIO;
  
// Print the distance in feet and inches
  cout << distance_m << " metres is: " << distance_ft << "' " << distance_inch << "\"," << endl;
  
// Calculate metres to furlongs and print
  cout << distance_m << " metres is: " << distance_m * FURLONG_RATIO << " furlongs," << endl;
  
// Calculate time it takes for distance to be traveled by light
  cout << "and it will take " << distance_m * LIGHT_RATIO << " seconds for light to travel " << distance_m << " metres in a vacuum." << endl;

  return 0;
}
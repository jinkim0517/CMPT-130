/*
Printing table of square roots, squares, and cubes
Author: Jin Kim
Date: September 2021
*/

#include <iostream>
#include <cmath>
#include <ios>
#include <iomanip>
using namespace std;

// Spacing constants
const int DEFAULT_SPACING = 8;
const int LEFT_SPACING = 3;

int main()
{
// Getting user input
    int end_point = 0;
    cout << fixed;
    // Repeating unitl correct input
    while (end_point <= 0 || end_point >= 214)
    {   
    cout << "Enter end of sequence between 1 and 213: ";
    cin >> end_point;
    cout << endl;
    }
    
        cout << setw(LEFT_SPACING) << "x" << setw(DEFAULT_SPACING) << "sqrt(x)" << setw(DEFAULT_SPACING) << "x^2" << setw(DEFAULT_SPACING) << "x^3"  << endl;
// Print square root, square and cube of numbers 1 to 10
        for (int x = 1; x <= end_point; ++x)
        {
        cout << setw(LEFT_SPACING) << x << setw(DEFAULT_SPACING);
        cout.precision(3);
        cout << setw(DEFAULT_SPACING) << sqrt(x) << setw(DEFAULT_SPACING);
        cout.precision(0);
        cout << setw(DEFAULT_SPACING) << pow(x, 2) << setw(DEFAULT_SPACING);
        cout << setw(DEFAULT_SPACING) << pow(x, 3) << setw(DEFAULT_SPACING);
        cout << endl;
        }
    return 0;
    }
/*
Program to find the quotient and remainder of two integers
Author: Jin Kim
Date: September 2021
*/

#include <iostream>
using namespace std;

int main()
{
	// Prompt user for the dividend
	int dividend = 0;

	cout << "Enter a number: ";
	cin >> dividend;
	cout << "You entered " << dividend << "." << endl;

	// Prompt user for the divisor
	int divisor = 0;

	cout << "Enter a divisor:";
	cin >> divisor;
	cout << "You entered " << divisor << " as a divisor." << endl;

	// Print result
	cout << "The quotient of: " << dividend << "/" << divisor << " is " << dividend / divisor << ", and the remainder is " << dividend % divisor << "." << endl;
	return 0;
}
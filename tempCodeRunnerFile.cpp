// lab7 - Global Variables
// Brian Fraser, (slightly) modified by John Edgar
// October 2020 (and 2021)
 
// Program using global variables.
// TASK: Convert all global variables into local variables.
// You may change the parameters to functions as needed.
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
 
// Global Constants (these are fine!).
const double MAX_HEIGHT = 3.0;
const double MIN_HEIGHT = 1.0;
 
// GLOBAL VARIABLES TO REMOVE
char choice = ' ';
bool keepReading = 1;
string customerName;
double customerHeight = 0;
 
// Function Prototypes
void readHeight();
void printCustomerInfo();
bool askToDoAnother();
 
// Asks for a customer's information, and display it to the screen.
int main() {
	while (keepReading) {
		// Read in the customer info:
		// ... Read the height
		readHeight();
		// ... Read Name
		cout << "Enter customer name: ";
		getline(cin, customerName);
		// Display a summary:
		printCustomerInfo();
		// Do another?
		keepReading = askToDoAnother();
	}
	return 0;
}
 
// Function Definitions - MAY NEED TO BE CHANGED
 
// Reads in the user's height
void readHeight() {
	cout << "Enter customer height (metres): ";
	cin >> customerHeight;
	while (customerHeight > MAX_HEIGHT || customerHeight < MIN_HEIGHT) {
		cout << fixed << setprecision(1);
		cout << "ERROR: Height must be between " << MIN_HEIGHT
			<< " and " << MAX_HEIGHT << " metres." << endl;
		cout << "Enter customer height (metres): ";
		cin >> customerHeight;
	}
	// Empty input stream (removes endline)
	cin.ignore(10000, '\n');
}
 
// Prints the customer's information to the screen.
void printCustomerInfo() {
	cout << fixed << setprecision(1);
	cout << "\n";
	cout << "Customer summary: " << endl;
	cout << "\tHeight: " << customerHeight << " metres" << endl;
	cout << "\tName: " << customerName << endl;
	cout << endl;
}
 
// Asks the user if they want to enter more data.
bool askToDoAnother() {
	// Read in the user's selection
	cout << "Enter another customer? (Y/N) ";
	cin >> choice;
	return (choice == 'Y' || choice == 'y');
}

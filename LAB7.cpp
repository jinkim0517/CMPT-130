//Jin Kim, LAB 7
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
 
// Global Constants (these are fine!).
const double MAX_HEIGHT = 3.0;
const double MIN_HEIGHT = 1.0;
 
// Function Prototypes
double readHeight(double customerHeight);
void printCustomerInfo(string customerName, double customerHeight);
bool askToDoAnother();
 
// Asks for a customer's information, and display it to the screen.
int main() {
    bool keepReading = 1;
    double customerHeight = 0;
    char choice = ' ';
    string customerName;
	while (keepReading == 1) {
		// Read in the customer info:
		// ... Read the height
        customerHeight = readHeight(customerHeight);
		// ... Read Name
		cout << "Enter customer name: ";
		getline(cin, customerName);
		// Display a summary:
		printCustomerInfo(customerName, customerHeight);
		// Do another?
		keepReading = askToDoAnother();
	}
	return 0;
}
 
// Function Definitions - MAY NEED TO BE CHANGED
 
// Reads in the user's height
double readHeight(double customerHeight) {
	cout << "Enter customer height (metres): ";
	cin >> customerHeight;
	while (customerHeight > MAX_HEIGHT || customerHeight < MIN_HEIGHT) {
		cout << fixed << setprecision(1);
		cout << "ERROR: Height must be between " << MIN_HEIGHT
			<< " and " << MAX_HEIGHT << " metres." << endl;

            if (cin.fail()){
                cin.clear();
                cin.ignore(10000, '\n');
            }
		cout << "Enter customer height (metres): ";
		cin >> customerHeight;
	}
	// Empty input stream (removes endline)
	cin.ignore(10000, '\n');
    return customerHeight;
}
 
// Prints the customer's information to the screen.
void printCustomerInfo(string customerName, double customerHeight) {
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
    char choice = ' ';
	cout << "Enter another customer? (Y/N) ";
	cin >> choice;
	return (choice == 'Y' || choice == 'y');
}
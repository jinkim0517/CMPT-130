/*
Lab 6 Printing names and number of characters
Author: Jin Kim
Date: October 2021
*/

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// Function Prototypes
string getName();
int countAlpha(string s);

int main()
{
    string name;

    // Call function and echo name
    name = getName();
    cout << name;
    cout << endl;

    // Print number of characters
    cout << "Your name has " << countAlpha(name) << " letters in it.";
    cout << endl;
    return 0;
}

string getName(){
    string first;
    string last;

    // Ask for first and last name
    cout << "Enter your first name: ";
    cin >> first;

    cout << "Enter your last name: ";
    cin >> last;

    // Concatenate
    return first + " " + last;
}

int countAlpha(string s) {
    int count = 0;
    for (char c : s) {
        if (isalpha(c)) {
            count++;
        }
    }
    return count;
}
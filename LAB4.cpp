/*
Investigating scope and loop control variables
Author: Jin Kim
Date: October 2021
*/

#include <iostream>
#include <ios>
using namespace std;

int main(){
    for (int x = 1; x <= 10; x++) {
	cout << x << endl;
    }

    cout << "---------------------" << endl;

    for(int x = 10; x > 0; x--){
        cout << x << endl;
    }

    cout << "---------------------" << endl;
    
    for (int x = 1; x <= 10; x += 2) {
	cout << x << endl;
    }

    cout << "---------------------" << endl;

    for (double x = 1; x < 2; x += 0.02){
        cout << x << endl;
    }

    cout << "---------------------" << endl;

    for (double x = 1; x < 2; x += 0.02){
        cout << fixed;
        cout.precision(8);
        cout << x << endl;
    }

    cout << "---------------------" << endl;

    for (float x = 1; x < 2; x += 0.02){
        cout << fixed;
        cout.precision(8);
        cout << x << endl;
    }
}

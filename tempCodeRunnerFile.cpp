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
 
int largestPower(int number);

int main(){
	cout << largestPower(17);
}

int largestPower(int number){
	int start = 1;
	int power = 0;

	while (number / start != 0){
		start *= 20;
		power++;
	}
	return power;
}
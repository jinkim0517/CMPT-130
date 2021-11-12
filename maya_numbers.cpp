#include <iostream>
#include <iomanip>
#include <ios>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function Prototypes
int largestPower(int number);
void printSymbols(int number);
void printMayanNumber(int number);
void mayanNumeralGame();
char printChoices(int inputValue, int correctAns, int incorrectAns1, int incorrectAns2);

// Constants
const char MAYAN_ONE = 'o';
const char* MAYAN_FIVE = "\u2580";
const int NUMBER_OF_CHOICES = 3;

int main(){
	cout << "The Mayan representation of 5212 is: " << endl;
	printMayanNumber(5212);

	mayanNumeralGame();
	return 0;
}

// Initiates the multiple choice game
void mayanNumeralGame(){
	int inputValue = 0;
	srand(time(0));

	// Asks for initial input from user
	cout << "Enter a number greater than 10, or enter a value less than 10 to exit. "
	<< "The game wll choose a number less than or equal to what you enter, and you will have to match the decimal "
	<< "value with its Mayan equivalent!" << endl;
	cout << "Your number: ";
	cin >> inputValue;

	// Error handling
	while(cin.fail()){
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "error" << endl;
		cout << "Enter a number greater than 10, or enter a value less than 10 to exit: ";
		cin >> inputValue;
	}
	// When the user wants to continue
	while(inputValue >= 10){
		// Sets upper and lower bounds
		int low = inputValue / 2;
		int high = inputValue * 1.5;
		int correctAns = rand() % inputValue + 4;
		int incorrectAns1 = rand() % (high - low + 1) + low;
		int incorrectAns2 = rand() % (high - low + 1) + low;
			
		// Prints the choices that the user can choose from
		char ans = printChoices(inputValue, correctAns, incorrectAns1, incorrectAns2);

		char userAns = ' ';
		cout << "Enter your choice: ";
		cin >> userAns;
		cout << endl;

		// Checks if the user answer is correct
		if(userAns == ans){
			cout << "You are correct! Great job!!!" << endl;
		}
		else{
			// Prints the correct mayan representation for the number
			cout << "Oops! Wrong answer :(" << endl
			<< "The correct Mayan representation of " << correctAns << " is:" << endl;
			printMayanNumber(correctAns);
		}

		// Asks if the user wants to continue
		cout << "Enter a number greater than 10, or enter a value less than 10 to exit: ";
		cin >> inputValue;

		// Error handling
		if(cin.fail()){
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "error" << endl;
			cout << "Enter a number greater than 10, or enter a value less than 10 to exit: ";
			cin >> inputValue;
		}
	}
	cout << "Goodbye!";
}

// Prints choices
char printChoices(int inputValue, int correctAns, int incorrectAns1, int incorrectAns2){
	// Rolls first number
	int firstRoll = rand() % NUMBER_OF_CHOICES;
	char ans = ' ';

	cout << "Which of these represents " << correctAns << "?" << endl;

	cout << "a." << endl;

	if(firstRoll == 0){
		printMayanNumber(correctAns);
		// Sets the answer to 'a' if correctAns is printed
		ans = 'a';
	}
	else if(firstRoll == 1){
		printMayanNumber(incorrectAns1);
	}
	else{
		printMayanNumber(incorrectAns2);
	}

	cout << endl << "b." << endl;

	// Rolls second number
	int secondRoll = rand() % NUMBER_OF_CHOICES;

	// Makes sure that the same choice is not printed twice
	while (secondRoll == firstRoll){
		secondRoll = rand() % NUMBER_OF_CHOICES;
	}
	
	if(secondRoll == 0){
		printMayanNumber(correctAns);
		// Sets ans to be if correctAns is printed
		ans = 'b';
	}
	else if(secondRoll == 1){
		printMayanNumber(incorrectAns1);
	}
	else{
		printMayanNumber(incorrectAns2);
	}

	cout << endl << "c." << endl;

	// Rolls third number
	int thirdRoll = rand() % NUMBER_OF_CHOICES;

	// Makes sure that the same choice is not printed two or three times
	while (thirdRoll == firstRoll || thirdRoll == secondRoll){
		thirdRoll = rand() % NUMBER_OF_CHOICES;
	}
	
	if(thirdRoll == 0){
		printMayanNumber(correctAns);
		// Sets ans to 'c' if correctAns is printed
		ans = 'c';
	}
	else if(thirdRoll == 1){
		printMayanNumber(incorrectAns1);
	}
	else {
		printMayanNumber(incorrectAns2);
	}
	return ans;
}

// Prints the Mayan representation of a number
void printMayanNumber(int number){
	// Accounts for 20^n not being able to produce zero
	if(number == 0){
		cout << "00" << endl;
	}
	else{
		// Finds the largest power of twenty
		int power = largestPower(number);
		while(power >= 0){
			// Finds the literal value of largestPower
			int baseTwentyValue = pow(20, power);

			// Finds the first base-twenty class and prints all the symbols
			int firstClassValue = number / baseTwentyValue;
			printSymbols(firstClassValue);

			// Adds dividing line if needed
			if(power != 0){
				cout << "-----" << endl;
			}
			
			// Changes the number to the next base-twenty class
			number -= firstClassValue * baseTwentyValue;
			power--;
		}
	}
}

// Finds the closest power of twenty
int largestPower(int number){
	int start = 1;
	int power = 0;

	while (number / start > 0){
		start *= 20;
		power++;
	}
	return power - 1;
}

// Prints all the symbols of a given integer
void printSymbols(int number){
	string symbols = "";

	// Prints shell
	if(number == 0){
		symbols = "00";
		symbols += '\n';
	}

	int numberOfFives = number / 5;
	int remainder = number % 5;

	// Prints dots
	for(int numOfDots = 0; numOfDots < remainder; numOfDots++){
		symbols += 'o';
	}
	
	// Adds new line if there is nothing left to be printed
	if (remainder != 0){
		symbols += '\n';
	}

	// Combines five of the MAYAN_FIVE character to make a line
	for(int i = 0; i < numberOfFives; i++){
		for(int linechar = 0; linechar < 5; linechar++){
			symbols += MAYAN_FIVE;
		}
		symbols += '\n';
	}
	cout << symbols;
}
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

const char MAYAN_ONE = 'o';
const char* MAYAN_FIVE = "\u2580";

int main(){
	mayanNumeralGame();
	//printMayanNumber(43549);
}

void mayanNumeralGame(){
	int inputValue = 0;
	srand(time(0));
	int rangeDifference = (inputValue * 1.5 - inputValue * 0.5);

	int correctAns = rand() % inputValue + 4;
	int incorrectAns1 = rand() % rangeDifference + inputValue * 0.5;
	int incorrectAns2 = rand() % rangeDifference + inputValue * 0.5;

	while(inputValue > 10){
		cout << "Enter a number greater than 10, or enter a value less than 10 to exit: ";
		cin >> inputValue;

	if(cin.fail()){
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "error";
	}
	char correct = printChoices(inputValue, correctAns, incorrectAns1, incorrectAns2);

	char choice = ' ';
	cin >> choice;
	}
}

char printChoices(int inputValue, int correctAns, int incorrectAns1, int incorrectAns2){
	int numberOfChoices = 3;
	int firstRoll = rand() % numberOfChoices;
	char ans = ' ';

	cout << "Which of these represents " << correctAns << "?" << endl;

	cout << "a." << endl;

	if(firstRoll == 0){
		printMayanNumber(correctAns);
		ans = 'a';
	}
	else if(firstRoll == 1){
		printMayanNumber(incorrectAns1);
	}
	else{
		printMayanNumber(incorrectAns2);
	}
	cout << endl;

	cout << "b." << endl;

	int secondRoll = rand() % numberOfChoices;

	while (secondRoll == firstRoll){
		secondRoll = rand() % numberOfChoices;
	}
	
	if(secondRoll == 0 && firstRoll != 0){
		printMayanNumber(correctAns);
		ans = 'b';
	}
	else if(secondRoll == 1 && firstRoll != 1){
		printMayanNumber(incorrectAns1);
	}
	else{
		printMayanNumber(incorrectAns2);
	}

	cout << "c." << endl;
	int thirdRoll = rand() % numberOfChoices;

	while (thirdRoll == firstRoll || thirdRoll == secondRoll){
		thirdRoll = rand() % numberOfChoices;
	}
	
	if(thirdRoll == 0){
		printMayanNumber(correctAns);
		ans = 'c';
	}
	else if(thirdRoll == 1){
		printMayanNumber(incorrectAns1);
	}
	else {
		printMayanNumber(incorrectAns2);
	}
	cout << firstRoll << "//" << secondRoll << "//" << thirdRoll;

	return ans;
}

void printMayanNumber(int number){
	int power = largestPower(number);
	while(power >= 0){
		int baseTwentyValue = pow(20, power);
		int firstClassValue = number / baseTwentyValue;
		printSymbols(firstClassValue);
		if(power != 0){
			cout << "------" << endl;
		}
		number -= firstClassValue * baseTwentyValue;
		power--;
	}
}

int largestPower(int number){
	int start = 1;
	int power = 0;

	while (number / start != 0){
		start *= 20;
		power++;
	}
	return power - 1;
}

void printSymbols(int number){
	int count = 0;
	string symbols = "";
	while(count < number){
		count++;
	}

	if(count == 0){
		symbols = "00";
		symbols += '\n';
	}

	int numberOfFives = count / 5;
	int remainder = count % 5;

	for(int numOfDots = 0; numOfDots < remainder; numOfDots++){
		symbols += 'o';
	}
	
	if (remainder != 0){
		symbols += '\n';
	}

	for(int i = 0; i < numberOfFives; i++){
		for(int linechar = 0; linechar < 5; linechar++){
			symbols += MAYAN_FIVE;
		}
		symbols += '\n';
	}
	cout << symbols;
}
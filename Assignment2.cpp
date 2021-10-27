/*
Listing factors, prime, interesting, perfect squares, and the sum of digits of an integer
Author: Jin Kim
Date: October 2021
*/

#include <iostream>
#include <iomanip>
using namespace std;

// Function prototypes
void find_factor(int num);
int digit_sum(int num);
void perfect_check(double num);
int digit_product(int num);
void interest_check(int num);

// Constant values
const int DEFAULT_SPACING = 4;

int main(){
    // Prompt user for first numer
    int firstnum = 0;
    int secondnum = 0;
    
    cout << "Enter a value between 1 and 999: ";
    cin >> firstnum;

    // Handling incorrect values
    while (firstnum < 1 || firstnum > 999){
        cout << "The value must be greater than 0 and less than 1000. Please try again: ";
        cin >> firstnum;
    }

    // Storing "true" value of first numer in true_firstnum,
    // since firstnum value is changed by find_factor
    int true_firstnum = firstnum;

    // Prompt user for second numer
    cout << "Enter a second value between 1 and 999: ";
    cin >> secondnum;

    // Handling incorrect values
    while (secondnum < 1 || secondnum > 999){
        cout << "The value must be greater than 0 and less than 1000. Please try again: ";
        cin >> secondnum;
    }

    cout << endl;

    // Call all functions
    while (firstnum <= secondnum){
        find_factor(firstnum);
        perfect_check(firstnum);
        cout << endl;
        ++firstnum;
    }

    cout << endl;

    // Print sum of digits in first numer
    cout << "Sum of the digits in " << true_firstnum;
    cout << " = " << digit_sum(true_firstnum);
  
    // Check if numer is interesting
    interest_check(true_firstnum);

    cout << endl;

    // Print sum of digits in second numer
    cout << "Sum of the digits in " << secondnum;
    cout << " = " << digit_sum(secondnum);
  
    // Check if numer is interesting
    interest_check(secondnum);

    cout << endl;
}

// FUNCTIONS

// Finds all factors and prints, 
// while also counting numer of factors and checking if prime
void find_factor(int num){
    cout << setw(DEFAULT_SPACING) << num;

    int factor_count = 0; 

    for (int i = 1; i <= num; i++){ 
        if (num % i == 0){
          cout << setw(DEFAULT_SPACING);
          cout << i;
         ++factor_count;
        }
    }

    cout << setw(DEFAULT_SPACING);
    cout << "(" << factor_count << ")"; 

    if (factor_count == 2){
        cout << "  --prime--  ";
    }
}

// Finds the sum of the digits in a numer
// Called in interest_check (int num)
int digit_sum(int num){
    int sum = 0;
    while (num > 0){
        sum += (num % 10);
        num = num / 10;
    }
    return sum;
}

// Checks if a numer is a perfect square
void perfect_check(double num){
    double i = 1;
    while (num > i){
        if ((num / i) == i){
            cout << "  --perfect square--  ";
        }
      i++;
    }
}

// Finding product of the digits in a number
// Called in interest_check(int num)
int digit_product(int num){
    int product = 1;
    while (num > 0){
        product *= (num % 10);
        num = num / 10;
    }
    return product;
}

// Checks if a numer is interesting
void interest_check(int num){
    if ((digit_product(num) + digit_sum(num)) == num){
        cout << "  --interesting--  ";
    }
}
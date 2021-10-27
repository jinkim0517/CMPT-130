/*
LAB 5
Author: Jin Kim
Date: October 2021
*/


#include <iostream>
using namespace std;

double compoundInterest(double loan, double rate, int term);
void displayLoan(double loan, double rate, int term);

int main()
{
    double loan = 0;
    double rate = 0;
    int term = 0;

    // User Input
    cout << "Enter the amount of the loan: ";
    cin >> loan;

    cout << "Enter the interest rate as a value between 0 and 1: ";
    cin >> rate;

    cout << "Enter the term of the loan in years: ";
    cin >> term;
    cout << endl;

    //Display Results
    displayLoan(loan, rate, term);
}

// Calculate Interest
double compoundInterest(double loan, double rate, int term){
    double total = loan;
    for (int i = 1; i <= term; i++){
        total += total * rate;
    }
    return total - loan;
}

// Display Results
void displayLoan(double loan, double rate, int term){
    cout << fixed;
    cout.precision(2);
    cout << "Loan Principal: " << loan << endl;
    cout << "Loan Rate: " << rate << endl;
    cout << "Loan Term: " << term << " years" << endl;

    cout << "Compound Interest: " << compoundInterest(loan, rate, term) << endl;
}
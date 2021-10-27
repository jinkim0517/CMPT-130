/*
Converting integer numbers into strings
Author: Jin Kim
Date: October 2021
*/

#include <iostream>
#include <string>
using namespace std;

// Function to find the value of a digit in a certain position
// Ex. thousands digit is the 4th number from the left
int digitValue(int number, int location){
    int digitValue = 0;

    for(int i = 1; i <= location; i++){
        digitValue = number % 10;
        number = number / 10;
    }
    return digitValue;
}

// Function to convert ones digits (location = 1) to strings
string onesToString(int number){
    int ones = digitValue(number, 1);
    int tens = digitValue(number, 2);
    int hundreds = digitValue(number, 3);
    string result = "";

    if (tens != 1){

        // Only prints zero when number is less than 1 (0)
        // Hundreds != prevents "zero" from printing when called
        // by thousandsToString
        if (number < 1){
            result = "zero";
        }

        // Returns strings from 1-9
        else if (ones == 1){
            result = "one";
        }

        else if (ones == 2){
            result = "two";
        }

        else if (ones == 3){
            result = "three";
        }

        else if (ones == 4){
            result = "four";
        }

        else if (ones == 5){
            result = "five";
        }

        else if (ones == 6){
            result = "six";
        }

        else if (ones == 7){
            result = "seven";
        }

        else if (ones == 8){
            result = "eight";
        }

        else if (ones == 9){
            result = "nine";
        }
    }
return result;
}

// Function to convert teen numbers (location = 2, tens == 1)
// Returns string only if number is within 10-19
string teensToString(int number){
    int ones = digitValue(number, 1);
    int tens = digitValue(number, 2);
    string result = "";

    // Tens == 1 parameter assures that value is
    // a teen number
    if (tens == 1 && ones == 0 ){
        result = "ten";
    }    

    else if (tens == 1 && ones == 1){
        result = "eleven";
    }

    else if (tens == 1 && ones == 2){
    result = "twelve";
    }

    else if (tens == 1 && ones == 3){
    result = "thirteen";
    }

    else if (tens == 1 && ones == 4){
        result = "fourteen";
    }

    else if (tens == 1 && ones == 5){
        result = "fifteen";
    }

    else if (tens == 1 && ones == 6){
        result = "sixteen";
    }

    else if (tens == 1 && ones == 7){
        result = "seventeen";
    }

    else if (tens == 1 && ones == 8){
        result = "eighteen";
    }

    else if (tens == 1 && ones == 9){
        result = "nineteen";
    }
    return result;
}

// Function to convert tens digits (location = 2) to string
// EXCLUDING TEEN NUMBERS
string tensToString(int number){
    int tens = digitValue(number, 2); 
    int ones = digitValue(number, 1);
    string result = "";

    // Returns strings for numbers 20-90 (increments of 10)
    if (tens == 2){
        result = "twenty";
    }

    else if (tens == 3){
        result = "thirty";
    }

    else if (tens == 4){
        result = "forty";
    }

    else if (tens == 5){
        result = "fifty";
    }

    else if (tens == 6){
        result = "sixty";
    }

    else if (tens == 7){
        result = "seventy";
    }

    else if (tens == 8){
        result = "eighty";
    }

    else if (tens == 9){
        result = "ninety";
    }

    // Adds "-" if ones value is not zero and
    // if number is greater than ten
    if (ones != 0 && tens > 1){
        result += "-";
    }    
    return result;
}

// Function to convert hundreds digits (location = 3) to string
string hundredsToString(int number){
    string result = "";
    int hundreds = digitValue(number, 3); 
    int tens = digitValue(number, 2);
    int ones = digitValue(number, 1);

    if (hundreds != 0){
        // Calls onesToString to retrieve string values for 
        // first half of concatenation
        string hundredsValue = onesToString(hundreds);

        // Adds " hundred " to ones string
        result = hundredsValue + " hundred";

        if (tens != 0 || ones != 0){
            result += " ";
        }
    }

    // Adds "and " only when last two digits are not zero
    if ((ones != 0 || tens != 0) && number >= 100){
        result += "and ";
    }
    return result;
}

// Function to convert thousands digits (location = 4) to string
string thousandsToString(int number){
    string result = "";
    int thousands = digitValue(number, 4);
    int hundreds = digitValue(number, 3);
    int tens = digitValue (number, 2);
    int ones = digitValue (number, 1);

    // Code only executes when needed
    if (number > 999){
        if (number < 10000 || number >= 20000){
            // Calls onesToString to determine the first half of
            // the string concatenation
            string thousandsValue = onesToString(thousands);

            // Determines whether or not a comma is necessary to be
            // returned based on the thousands and hundreds digits
            if (hundreds != 0){
                result = thousandsValue + " thousand, ";
            }
            else{
                result = thousandsValue + " thousand";
                if (tens != 0 || ones != 0){
                    result += " ";
                }
            }
        }
    }
    return result;
}

// Function to convert teenthousand digits
// (location = 4, within 10-19 thousand)
string teenThousandsToString(int number){
    string result = "";
    int tenThousands = digitValue(number, 5);
    int thousands = digitValue(number, 4);
    int hundreds = digitValue(number, 3);
    int tens = digitValue(number, 2);
    int ones = digitValue(number, 1);
    
    // Code only executes when needed
    if (number >= 10000 && number < 20000){ 
        int tenThousands = digitValue(number, 5);
        int thousands = digitValue(number, 4);

        if (tenThousands == 1 && thousands == 0 ){
            result = "ten thousand";
        }    

        else if (tenThousands == 1 && thousands == 1){
            result = "eleven thousand";
        }

        else if (tenThousands == 1 && thousands == 2){
            result = "twelve thousand";
        }

        else if (tenThousands == 1 && thousands == 3){
            result = "thirteen thousand";
        }

        else if (tenThousands == 1 && thousands == 4){
            result = "fourteen thousand";
        }

        else if (tenThousands == 1 && thousands == 5){
            result = "fifteen thousand";
        }

        else if (tenThousands == 1 && thousands == 6){
            result = "sixteen thousand";
        }

        else if (tenThousands == 1 && thousands == 7){
            result = "seventeen thousand";
        }

        else if (tenThousands == 1 && thousands == 8){
            result = "eighteen thousand";
        }

        else if (tenThousands == 1 && thousands == 9){
            result = "nineteen thousand";
        }

        // Adds ", " to result only if second digit is not 0
        // Otherwise, adds a space for formatting
        if (hundreds != 0){
            result += ", ";
        }
        else{
            if (tens != 0 || ones != 0){
            result += " ";
            }
        }
    }
    return result;
}

// Function to convert tenThousands digits (location = 5) to string
string tenThousandsToString (int number){
    int tenThousands = digitValue(number, 5); 
    int thousands = digitValue(number, 4);
    string result = "";

    // Prevents unnecesaary execution for smaller values
    if (number >= 20000){
        if (tenThousands == 2){
            result = "twenty";
        }

        else if (tenThousands == 3){
            result = "thirty";
        }

        else if (tenThousands == 4){
            result = "forty";
        }

        else if (tenThousands == 5){
            result = "fifty";
        }

        else if (tenThousands == 6){
            result = "sixty";
        }

        else if (tenThousands == 7){
            result = "seventy";
        }

        else if (tenThousands == 8){
            result = "eighty";
        }

        else if (tenThousands == 9){
            result = "ninety";
        }

        // Adds "-" if THOUSANDS and TENTHOUSANDS are not zero
        if (tenThousands >= 1 && thousands >= 1){
        result += "-";
        }
    }
    return result;
}

// Function to combine strings for each digit location of number
string intToString(int number){
    // Checks if value is within range
    while (number < 0 || number > 99999){ 
        return "error";
    }

    // Adds all strings together and returns the sum
    string totalString = tenThousandsToString(number) + teenThousandsToString(number) + thousandsToString(number);
    totalString += hundredsToString(number) + tensToString(number) + teensToString(number) + onesToString(number);
    return totalString;
}

// Prints string values of all numbers between start and end
// with an interval value
void printIntStrings(int start, int end, int interval){
    // When start is less than end
    if(start <= end){
        while (start <= end){
            cout << intToString(start) << endl;
            // Increases by interval
            start += interval;
        }
    }
    else{
    // When end is less than start
        while (start >= end){
            cout << intToString(start) << endl;
            // Decreases by interval
            start -= interval;
        }
    }
}

int main()
{
    //printIntStrings(0, 4, 3);
    cout << intToString(12340);
    return 0;
}
#include <iostream>
#include <string>
using namespace std;

string getName();

int main()
{
    string name;
/*  name = "bob";
    cout << name << endl;
    name = "kate";
    cout << name << endl;
*/

    name = getName();
    cout << name;
    cout << endl;

    cout << "Your name has " << name.size() << " letters in it.";
    cout << endl;
    return 0;
}

string getName(){
    string first;
    string last;

    cout << "Enter your first name: ";
    cin >> first;

    cout << "Enter your last name: ";
    cin >> last;

    return first + " " + last;
}
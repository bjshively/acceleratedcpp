#include <iostream>
#include <string>

using namespace std;

int main() {
    cout << "Enter your first name: ";
    string name; // declare name
    cin >> name; // store value in name

    // Build message
    const string greeting = "Hello, " + name + "!";
    
    // Build 2nd and 4th lines

    // Using the string constructor to define spaces
    const string spaces(greeting.size(), ' ');
    const string second = "* " + spaces + " *";

    // Build 1st and 5th lines
    const string first(second.size(), '*');
    cout << endl;
    cout << first << endl;
    cout << second << endl;
    cout << "* " << greeting << " *" << endl;
    cout << second << endl;
    cout << first << endl;

    return 0;
}
#include <iostream>
#include <string>

using namespace std;

int main() {
    cout << "Enter your first name: ";
    string name; // declare name
    cin >> name; // store value in name

    cout << "Hello, " << name << "!"     << endl;

    return 0;
}
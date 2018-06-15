#include <iostream>
#include <string>

using namespace std;

int main()
{
    // ex2.7
    for(int i = 10; i > -6; i--) {
        cout << i << endl;
    }

    cout << endl;

    // ex2.8
    int product = 1;
    for (int i = 1; i < 10; i++) {
        product *= i;
    }
    cout << product << endl;

    // ex2.9
    cout << "Enter first number: ";
    int firstNumber;
    cin >> firstNumber;

    cout << "Enter second number: ";
    int secondNumber;
    cin >> secondNumber;

    if (firstNumber > secondNumber) {
        cout << firstNumber;
    } else {
        cout << secondNumber;
    }

    cout << " is larger." << endl;

    return 0;
}
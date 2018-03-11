#include <iostream>
#include <string>

using namespace std;

int main()
{
    cout << "Name: ";

    string name;
    cin >> name;
    const string greeting = "Hello, " + name + "!";

    // Number of blank rows padding the greeting
    const int pad = 5;

    // Total number of rows to write
    const int rows = pad * 2 + 3; // padding for top and bottom, plus first, last, and message row

    // Width of each line
    const string::size_type cols = greeting.size() + pad * 2 + 2;

    // spacer
    cout << endl;
    
    int r = 0;

    // invariant: we have written r rows so far
    while (r != rows) {
        string::size_type c = 0;

        // Invariant: We have written c characters
        while (c != cols) {
            // write some chars
            // increment c as needed

            // Write border characters if on an outer edge
            if (r == 0 || r == rows - 1 || c == 0 || c == cols - 1) {
                cout << "*";
                ++c;
            } else {
                //Write something else (padding or greeting) if not on an outer edge
                if (r == pad + 1 && c == pad + 1) {
                    cout << greeting;
                    c += greeting.size();
                } else {
                    cout << " ";
                    c += 1;
                }
            }
        }
        cout << endl;
        ++r;
    }

    return 0;
}
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
    const int pad = 1;

    // Total number of rows to write
    const int rows = pad * 2 + 3; // padding for top and bottom, plus first, last, and message row

    // Width of each line
    const string::size_type cols = greeting.size() + pad * 2 + 2;

    cout << endl;

    // invariant: we have written r rows so far
    for (int r = 0; r != rows; ++r) {
        string::size_type c = 0;
     
        while (c != cols) {

            // write greeting?
            if (r == pad + 1 && c == pad + 1) {
                cout << greeting;
                c += greeting.size();
            } else {
                // otherwise, write space or *?
                if (r == 0 || r == rows - 1 || c == 0 || c == cols - 1) { 
                    cout << "*";
                } else {
                    cout << " ";
                }
                ++c;
            }
        }

        // move down to next row        
        cout << endl;
    }
    return 0;
}
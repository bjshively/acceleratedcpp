#include <iostream>
#include <string>

using namespace std;

int main()
{
    // Square
    int sideLength = 5;
    const string side(sideLength, '*');
        for(int i = 0; i < sideLength; i++) {
        if(i == 0 || i == sideLength - 1) {
            cout << side << endl;
        } else {
            cout << '*' << string(sideLength - 2, ' ') << '*' << endl;
        }
    }

    return 0;
}
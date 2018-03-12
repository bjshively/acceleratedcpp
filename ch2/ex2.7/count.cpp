#include <iostream>
#include <string>

using namespace std;

int main()
{
    for(int i = 10; i > -6; i--) {
        cout << i << endl;
    }

    cout << endl;

    int product = 1;
    for (int i = 1; i < 10; i++) {
        product *= i;
    }
    cout << product << endl;
    return 0;
}
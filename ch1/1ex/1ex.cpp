#include <iostream>
#include <string>

using namespace std;

int main() {
    //1.1
    // const string hello = "Hello";
    // const string message = hello + ", world" + "!";

    //1.2
    // const string exclam = "!";
    // const string message = "Hello" + ", world"; // Invalid. Can't concatentae two string literals

    //1.3
    // This works because the strings are scoped to their respective blocks
    // Removing the curly brackets causes a name collission/compilation error
    // { const string s = "a string";
    // cout << s << endl;}

    // {
    //     const string s = "another string";
    //     cout << s << endl;
    //     return 0;
    // }

    //1.4
    // { const string s = "a string";
    //     cout << s << endl;
    //     {const string s = "another string";
    //     cout << s << endl; };}
    // return 0;

    //1.5
    // This is invalid because x is destroyed at the end of the block so we can't use it
    // { string s = "a string";
    //     { string x = s + ", really";
    //         cout << s << endl;}
    //         cout << x << endl;
    //     }
    // return 0;
    // }

    // Fixed version
    // x isn't destroyed until after it is used
    // { string s = "a string";
    //     { string x = s + ", really";
    //         cout << s << endl;
    //         cout << x << endl;}
    // return 0;
    // }

    //1.6
    // What does this do? If you two two names e.g. "Brad Shively"
    // It uses word 1 for first cin, and word 2 for second cin
    cout << "What is your name? ";
    string name;
    cin >> name;
    cout << "Hello, " << name << endl << "And what is yours? ";
    cin >> name;
    cout << "Hello, " << name << "; nice to meet you too!" << endl;
    return 0;

    //return 0;
}
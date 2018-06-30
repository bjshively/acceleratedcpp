#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {

  string longestWord;
  string shortestWord;

  cout << "Enter a list of words: ";
  string s;

  while(cin >> s) {
    if (shortestWord.size() == 0 || s.size() <= shortestWord.size()) {
      shortestWord = s;
    }
  	if (longestWord.size() == 0 || s.size() > longestWord.size()) {
      longestWord = s;
    }
  }

  cout << "The longest word is " << longestWord << " at " << longestWord.size()
       << endl;
  cout << "The shorest word is " << shortestWord << " at " << shortestWord.size()
       << endl;

  return 0;
}
#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::setprecision;
using std::streamsize;
using std::string;
using std::vector;

int main() {

  typedef vector<string>::size_type vec_sz;
  vector<string> words;
  vector<int> counts;

  cout << "Enter a list of words: ";
  string s;

  while(cin >> s) {
  	// Startout assuming word isn't in the list (not found)
  	bool found = false;

  	// Search list for word, increment count and mark if it is found
  	for (vec_sz i = 0; i < words.size(); ++i) {
  		if (s == words[i]) {
  			++counts[i];
  			found = true;
  		}
  	}

  	// If the word isn't found, add it to the list and set count to 1
  	if (!found) {
  		words.push_back(s);
  		counts.push_back(1);
  	}
  }

  for (vec_sz i = 0; i < words.size(); ++i) {
  	cout << words[i] << " appears " << counts[i] << " times." << endl;
  }

  return 0;
}
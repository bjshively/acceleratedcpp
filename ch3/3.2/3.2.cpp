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
  cout << "Enter your first name: ";
  string name;
  cin >> name;
  cout << "Hello, " << name << "!" << endl;

  cout << "Enter your midterm and final exam grades: ";
  double midterm, final;
  cin >> midterm >> final;

  cout << "Enter all of your homework grades,"
          " followed by end-of-file: ";

  // ctrl+d for EOF in *nix

  double x;
  vector<double> homework;

  // Add each homework entered to the end of the homework vector
  while (cin >> x) {
    homework.push_back(x);
  }

  // save the size of the homework vector to use when finding median
  // note on typedef: basically creating an alias (vec_sz)
  // for a type (vector<double>::size_type)
  typedef vector<double>::size_type vec_sz;
  vec_sz size = homework.size();

  // Abort if user doesn't enter homework grades
  if (size == 0) {
  	cout << endl << "You must enter your grades. "
  					"Please try again." << endl;
  	return 1;
  }

  // Sort vector so we can determine median
  sort(homework.begin(), homework.end());
  
  // Calculate median
  vec_sz mid = size/2;
  double median;
  median = size % 2 == 0 ? (homework[mid] + homework[mid-1]) / 2
  						 : homework[mid];

  cout << "The median homework grade is " << median << endl;

  streamsize prec = cout.precision();
  cout << "Your final grade is " << setprecision(3)
  	   << 0.2 * midterm + 0.4 * final + 0.4 * median 
  	   << setprecision(prec) << endl;

  return 0;
}

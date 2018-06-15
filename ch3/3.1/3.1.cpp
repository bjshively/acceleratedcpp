#include <iomanip>
#include <ios>
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::setprecision;
using std::string;
using std::streamsize;

int main()
{
	cout << "Enter your first name: ";
	string name;
	cin >> name;
	cout << "Hello, " << name << "!" << endl;

	cout << "Enter your midterm and final exam grades: ";
	double midterm, final;
	cin >> midterm >> final;

	cout << "Enter all of your homework grades, "
		" followed by end-of-file: ";

	// ctrl+d for EOF in *nix

	// number and sum of grades read so far
	int count = 0;
	double sum = 0;

	// variable to read grades into
	double x;

	// invariant:
	// we have read count grades so far, and
	// sum is the sum of the first count grades
	while (cin >> x) {
		++count;
		sum += x;
	}

	// write the result
	streamsize prec = cout.precision();

	cout << "Your final grade is " << setprecision(3)
		 << 0.2 * midterm + 0.4 * final + 0.4 * sum / count
		 << setprecision(prec) << endl;

	return 0;
}
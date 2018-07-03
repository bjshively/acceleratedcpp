#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

// Determine median of a vector
double median(vector<double> vec) {
  typedef vector<double>::size_type vec_sz;

  vec_sz size = vec.size();
  if (size == 0) {
    throw domain_error("median of an empty vector");
  }

  sort(vec.begin(), vec.end());

  vec_sz mid = size / 2;

  return size % 2 == 0 ? (vec[mid] + vec[mid - 1]) / 2 : vec[mid];
}

// Calculate overall grade
double grade(double midterm, double final, double homework) {
  return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

// Calculate homework grade
double grade(double midterm, double final, const vector<double>& hw) {
  if (hw.size() == 0) {
    throw domain_error("student has done no homework");
  }
  return grade(midterm, final, median(hw));
}

// Read in homework data
istream& read_hw(istream& in, vector<double>& hw) {
  if (in) {
    // Clear any past contents of hw since we don't know what's there
    hw.clear();

    double x;
    while (in >> x) {
      hw.push_back(x);
    }

    // Reset error state of in for future use
    in.clear();
  }

  return in;
}

int main() {
  cout << "Enter first name: ";
  string name;
  cin >> name;
  cout << "Hello, " << name << "!" << endl;

  cout << "Enter your midterm and final grades: ";
  double midterm, final;
  cin >> midterm >> final;

  cout << "Enter your homework grades, followed by EOF: ";

  vector<double> homework;

  read_hw(cin, homework);

  try {
    double final_grade = grade(midterm, final, homework);
    streamsize prec = cout.precision();

    cout << "Your final grade is " << setprecision(3) << final_grade
         << setprecision(prec) << endl;
  } catch (domain_error) {
    cout << endl
         << "You must enter your grades. "
            "Please try again."
         << endl;
    return 1;
  }

  return 0;
}
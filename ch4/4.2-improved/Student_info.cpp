#include "Student_info.h"

using std::istream;
using std::vector;

bool compare(const Student_info& x, const Student_info& y)
{
	return x.name < y.name;
}

// Populate Student_info with data
istream& read(istream& is, Student_info& s) {
  // read student's name, midterm, and final
  is >> s.name >> s.midterm >> s.final;

  read_hw(is, s.homework);  // read and store homework grades
  return is;
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
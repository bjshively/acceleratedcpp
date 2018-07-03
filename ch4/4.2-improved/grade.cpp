#include <stdexcept>
#include <string>
#include <vector>

#include "grade.h"
#include "median.h"
#include "Student_info.h"

using std::vector;

// Calculate overall grade
double grade(double midterm, double final, double homework) {
  return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

// Calculate grade from midterm, final, and homework scores
double grade(double midterm, double final, vector<double> homework) {
  if (homework.size() == 0) {
  	throw std::domain_error("student has no homework scores");
  }
  return grade(midterm, final, median(homework));
}

// Perform grade calculation for a particular student
double grade(const Student_info& s) {
  return grade(s.midterm, s.final, s.homework);
}
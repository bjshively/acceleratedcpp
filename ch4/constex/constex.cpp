#include <vector>

using namespace std;

int main() {
  vector<double> hw;

  // const here makes this a read-only reference to homework
  const vector<double>& chw = hw;

  // this works, because it preserves the read-only
  const vector<double>& hw3 = chw;

  // this doesn't work because it's a non-readonly reference
  // to a readonly reference
  // vector<double>& hw4 = chw;

  return 0;
}

#include <fstream>
#include <stdlib.h>
#include <climits>

int main() {
  std::ifstream inf("input.txt");
  std::ofstream ouf("output.txt");
  int n;
  inf >> n;

  int* p = new int[n];
  int* t = new int[n];
  for (int i = 0; i < n; i++) {
    inf >> p[i];
  }
  for (int i = 0; i < n; i++) {
    inf >> t[i];
  }

  long result = 0;
  int minDiff = LONG_MAX;
  int count = 0;
  for (int i = 0; i < n; i++) {
    if (p[i] > t[i]) {
      result += p[i];
      count++;
    } else {
      result += t[i];
      count--;
    }
    int diff = abs(p[i] - t[i]);
    minDiff = (diff < minDiff) ? diff : minDiff;
  }
  result = (abs(count) == n) ? result - minDiff : result;

  ouf << result << std::endl;
  delete []p;
  delete []t;
  return 0;
}

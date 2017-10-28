#include <fstream>

int main() {
  std::ifstream inf("input.txt");
  std::ofstream ouf("output.txt");
  long long int a, b;
  inf >> a >> b;
  long long int result = a + (b * b);
  ouf << result << std::endl;
  return 0;
}

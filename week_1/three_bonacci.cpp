#include <fstream>

/*long long int threebonacci(int a, int b, int c, unsigned int n) {
  if (n == 0) {
    return a;
  } else if (n == 1) {
    return b;
  } else if (n == 2) {
    return c;
  } else {
    return threebonacci(a, b, c, n-1) + threebonacci(a, b, c, n-2) - threebonacci(a, b, c, n-3);
  }
}*/

long long int threebonacci(int a, int b, int c, unsigned int n) {
  if (n == 0) {
    return a;
  } else if (n == 1) {
    return b;
  } else if (n == 2) {
    return c;
  } else {
    long long int x = c, y = b, z = a;
    for (unsigned int i = 3; i <= n; i++) {
      long long int temp = x + y - z;
      z = y;
      y = x;
      x = temp;
    }
    return x;
  }
}

int main() {
  std::ifstream inf("input.txt");
  std::ofstream ouf("output.txt");

  int a, b, c;
  unsigned int n;

  inf >> a >> b >> c >> n;
  ouf << threebonacci(a, b, c, n) << std::endl;
  return 0;
}

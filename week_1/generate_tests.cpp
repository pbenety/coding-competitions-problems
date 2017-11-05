#include <fstream>
#include <cmath>

long int read_input() {
  std::ifstream input("input.txt");
  long int k = 0;
  input >> k;
  return k;
}

void generate_output(int maximal_tests) {
  std::ofstream ouf("output.txt");
  ouf << maximal_tests << std::endl;
}

int calculate_number_divisors(long int number) {
  int divisors = 1;
  while (number % 2 == 0) {
    divisors++;
    number /= 2;
  }
  for (int prime = 3; prime <= sqrt(number); prime += 2) {
    int divisors_of_next_prime = 1;
    while (number % prime == 0) {
      divisors_of_next_prime++;
      number /= prime;
    }
    divisors *= divisors_of_next_prime;
  }
  if (number > 2) {
    divisors *= 2;
  }
  return divisors;
}

int calculate_maximal_tests(long int k) {
  long int first_maximal = 0;
  int max_divisors = 0;
  long int initial_value = 2;
  if (k > 2) {
    initial_value = initial_value / 2;
    initial_value = (initial_value % 2 == 0) ? initial_value : initial_value + 1;
  }
  long int i = initial_value;
  while (i <= k) {
    int divisors = calculate_number_divisors(i);
    if (divisors > max_divisors) {
      first_maximal = i;
      max_divisors = divisors;
    }
    if (i >= 60 && i % 60 == 0) {
      i += 60;
    } else {
      i += 2;
    }
  }
  return k - first_maximal + 1;
}

int main() {
  long int k = read_input();
  generate_output(calculate_maximal_tests(k));
  return 0;
}

#include <fstream>
#include <vector>
#include <algorithm>

const int MAXIMUM_TIME = 18000;

std::vector<long int> read_problems_time(std::ifstream& input, int n) {
  std::vector<long int> problems_time(n);

  for (int i = 0; i < n; i++) {
    input >> problems_time[i];
  }

  std::sort (problems_time.begin(), problems_time.end());
  return problems_time;
}

void generate_output(int maximum_problems) {
  std::ofstream output("output.txt");
  output << maximum_problems << std::endl;
}

int calculate_maximum_problems(std::vector<long int> problems_time) {
  int maximum_problems = 0, remaining_time = MAXIMUM_TIME;

  for (int i = 0; i < problems_time.size(); i++) {
    remaining_time -= problems_time[i];
    if (remaining_time >= 0) {
      maximum_problems++;
    } else {
      break;
    }
  }

  return maximum_problems;
}

int main() {
  std::ifstream input("input.txt");
  int n = 0;
  input >> n;
  std::vector<long int> problems_time = read_problems_time(input, n);
  generate_output(calculate_maximum_problems(problems_time));
  return 0;
}

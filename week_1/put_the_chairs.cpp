#include <fstream>
#include <vector>
#include <iomanip>

const int NUMBER_OF_SIDES = 3;

std::vector<int> read_input() {
  std::ifstream inf("input.txt");
  std::vector<int> input(NUMBER_OF_SIDES);

  for (int i = 0; i < NUMBER_OF_SIDES; i++) {
    inf >> input[i];
  }
  return input;
}

void generate_output(double average_distance) {
  std::ofstream ouf("output.txt");
  ouf << std::setprecision(10) << average_distance << std::endl;
}

double calculate_average_distance(std::vector<int> sides) {
  double average_distance = 0.0;
  for (auto const& side: sides) {
    average_distance += side;
  }
  return average_distance / NUMBER_OF_SIDES / 2;
}

int main() {
  std::vector<int> sides = read_input();
  generate_output(calculate_average_distance(sides));
  return 0;
}

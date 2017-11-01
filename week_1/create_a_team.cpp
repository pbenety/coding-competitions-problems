#include <fstream>
#include <cmath>
#include <vector>
#include <iomanip>

const int MATRIX_SIZE = 3;

std::vector<std::vector<int>> read_input() {
  std::ifstream inf("input.txt");
  std::vector<std::vector<int>> efficiencies(MATRIX_SIZE);

  for (int row = 0; row < MATRIX_SIZE; row++) {
    efficiencies[row].resize(MATRIX_SIZE);
    for (int col = 0; col < MATRIX_SIZE; col++) {
      inf >> efficiencies[row][col];
    }
  }
  return efficiencies;
}

void generate_output(double maximum_efficiency) {
  std::ofstream ouf("output.txt");
  ouf << std::setprecision(10) << maximum_efficiency << std::endl;
}

double calculate_efficiency(int efficiency_by_role[3]) {
  return sqrt(pow(efficiency_by_role[0], 2.0) + pow(efficiency_by_role[1], 2.0) + pow(efficiency_by_role[2], 2.0));
}

double calculate_maximum_efficiency(std::vector<std::vector<int>> efficiencies) {
  double max_efficiency = 0.0;
  for(int i = 0; i < MATRIX_SIZE; i++) {
    for (int j = 0; j < MATRIX_SIZE - 1; j++) {
      int efficiency_by_role[3] = { efficiencies[i][j], efficiencies[(i + 1) % 3][(2 * j + 1) % 3], efficiencies[(i + 2) % 3][(3 * j + 2) % 3] };
      double efficiency = calculate_efficiency(efficiency_by_role);
      if (efficiency > max_efficiency) {
        max_efficiency = efficiency;
      }
    }
  }
  return max_efficiency;
}

int main() {
  std::vector<std::vector<int>> efficiencies = read_input();
  generate_output(calculate_maximum_efficiency(efficiencies));
  return 0;
}

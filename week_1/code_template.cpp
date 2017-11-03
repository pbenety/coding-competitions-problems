#include <fstream>
#include <string>
#include <map>
#include <climits>
#include <algorithm>

const std::string TEMPLATE_START = "%TEMPLATE-START%";
const std::string TEMPLATE_END = "%TEMPLATE-END%";

std::map<char, std::pair<int, int> > read_keyboard(std::ifstream& input) {
  std::map<char, std::pair<int, int> > keyboard;

  int width = 0, height = 0;
  input >> width >> height;

  for (int h = height; h > 0; h--) {
    for (int w = 1; w <= width; w++) {
      char c;
      std::pair<int, int> position(w, h);
      input >> c;
      keyboard.insert(std::pair<char, std::pair<int, int> >(c, position));
    }
  }

  return keyboard;
}

int distance_between_chars(char a, char b, std::map<char, std::pair<int, int> > keyboard) {
  std::pair<int, int> a_position = keyboard.find(a)->second;
  std::pair<int, int> b_position = keyboard.find(b)->second;
  return std::max(std::abs(a_position.first - b_position.first), std::abs(a_position.second - b_position.second));
}

int calculate_template_distance(std::ifstream& input, std::map<char, std::pair<int, int> > keyboard) {
  int template_distance = 0;
  std::string line;
  input >> line;
  char last_char = *line.begin();
  do {
    for (std::string::iterator it=line.begin(); it != line.end(); it++) {
      int distance = distance_between_chars(last_char, *it, keyboard);
      template_distance += distance;
      last_char = *it;
    }
    input >> line;
  } while (line != TEMPLATE_END);
  return template_distance;
}

void generate_output(std::string language, int distance) {
  std::ofstream output("output.txt");
  output << language << std::endl << distance;
  output.close();
}

int main() {
  std::ifstream input("input.txt");

  std::map<char, std::pair<int, int> > keyboard = read_keyboard(input);
  std::string better_language;
  int min_distance = INT_MAX;

  while (!input.eof()) {
    std::string language;
    input >> language;
    std::string line;
    input >> line;
    if (line == TEMPLATE_START) {
      int template_distance = calculate_template_distance(input, keyboard);
      if (template_distance < min_distance) {
        min_distance = template_distance;
        better_language = language;
      }
    }
  }
  generate_output(better_language, min_distance);
  input.close();
  return 0;
}

#include <cctype>
#include <fstream>
#include <iostream>
#include <string>

int main() {
  std::ifstream file("input.txt");
  std::string line;
  int sum = 0;

  while (std::getline(file, line)) {
    int front_num = -1;
    for (char c : line) {
      if (isdigit(c)) {
        front_num = c - '0';
        break;
      }
    }

    int back_num = -1;
    for (int i = line.size(); i >= 0; --i) {
      if (isdigit(line[i])) {
        back_num = line[i] - '0';
        break;
      }
    }

    if (front_num != -1 && back_num != -1) {
      sum += front_num * 10 + back_num;
    }
  }

  std::cout << sum << std::endl;
  return 0;
}

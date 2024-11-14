#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <regex>
#include <string>

int main() {
  std::ifstream file("input.txt");
  std::string line;

  int blueThreshold = 14;
  int greenThreshold = 13;
  int redThreshold = 12;

  int IDSum = 0;

  while (std::getline(file, line)) {

    std::regex gameIDpattern(R"(Game (\d+))");
    std::regex pattern(R"((\d+)\s*(blue|red|green))");

    int currID = 0;
    int maxBlue = 0, maxGreen = 0, maxRed = 0;

    std::smatch gameIDmatch;

    if (std::regex_search(line, gameIDmatch, gameIDpattern)) {
      currID = std::stoi(gameIDmatch[1].str());
    }

    auto begin = std::sregex_iterator(line.begin(), line.end(), pattern);
    auto end = std::sregex_iterator();

    for (auto it = begin; it != end; ++it) {
      int num = std::stoi((*it)[1].str());
      std::string color = (*it)[2].str();

      if (color == "blue") {
        maxBlue = std::max(maxBlue, num);
      } else if (color == "green") {
        maxGreen = std::max(maxGreen, num);
      } else if (color == "red") {
        maxRed = std::max(maxRed, num);
      }
    }

    if (maxBlue <= blueThreshold && maxGreen <= greenThreshold &&
        maxRed <= redThreshold) {
      IDSum += currID;
    }
  }

  std::cout << IDSum << std::endl;
  return 0;
}

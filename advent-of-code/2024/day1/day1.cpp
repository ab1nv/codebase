#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

void sort_columns(const std::string &input_file, std::vector<int> &left_values,
                  std::vector<int> &right_values) {
  std::ifstream file(input_file);
  if (!file.is_open()) {
    std::cerr << "Could not open the file " << input_file << std::endl;
    return;
  }

  std::string line;
  while (std::getline(file, line)) {
    std::istringstream iss(line);
    int left, right;
    if (iss >> left >> right) {
      left_values.push_back(left);
      right_values.push_back(right);
    }
  }
  file.close();

  std::sort(left_values.begin(), left_values.end());
  std::sort(right_values.begin(), right_values.end());
}

int calculate_difference(const std::vector<int> &left_values,
                         const std::vector<int> &right_values) {
  int diff = 0;
  for (size_t i = 0; i < std::min(left_values.size(), right_values.size());
       ++i) {
    diff += std::abs(left_values[i] - right_values[i]);
  }
  return diff;
}

int calculate_similarity(const std::vector<int> &left_values,
                         const std::vector<int> &right_values) {
  std::unordered_map<int, int> right_freq;
  for (int num : right_values) {
    right_freq[num]++;
  }

  int sim = 0;
  for (int num : left_values) {
    sim += num * right_freq[num];
  }
  return sim;
}

int main() {
  const std::string input_file = "input.txt";
  std::vector<int> left_values, right_values;
  sort_columns(input_file, left_values, right_values);

  int total_difference = calculate_difference(left_values, right_values);
  std::cout << "Total Difference: " << total_difference << std::endl;

  int total_similarity = calculate_similarity(left_values, right_values);
  std::cout << "Total Similarity: " << total_similarity << std::endl;

  return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main() {

  int count = 0;
  int stones;
  string color;

  cin >> stones;
  cin >> color;

  for (int i = 0; i < color.size(); i++) {
    if (i != color.size()) {
      if (color[i] == color[i + 1]) {
        count += 1;
      } else {
        continue;
      }
    }
  }

  cout << count << endl;
}

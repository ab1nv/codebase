#include <bits/stdc++.h>
using namespace std;

int main() {

  string s;
  cin >> s;
  int lower = 0;
  int upper = 0;

  for (char c : s) {
    if (islower(c)) {
      lower += 1;
    } else {
      upper += 1;
    }
  }

  if (upper > lower) {
    transform(s.begin(), s.end(), s.begin(), ::toupper);
  } else {
    transform(s.begin(), s.end(), s.begin(), ::tolower);
  }

  cout << s << endl;
}

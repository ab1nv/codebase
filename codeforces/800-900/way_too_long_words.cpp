#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    string word;
    cin >> word;
    if (word.length() > 10) {
      cout << word[0] << word.length() - 2 << word.back() << "\n";
    } else {
      cout << word << "\n";
    }
  }
}

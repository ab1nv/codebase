#include <bits/stdc++.h>
using namespace std;

#define str string

int main() {

  int n, t;
  cin >> n >> t;

  str s;
  cin >> s;

  while (t--) {
    for (int i = 0; i < n; i++) {
      if (i == (n - 1))
        continue;
      if (s[i + 1] == 'G' && s[i] == 'B') {
        swap(s[i], s[i + 1]);
        i += 1;
      }
    }
  }

  cout << s << endl;
}

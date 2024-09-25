#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  while (n--) {
    int t;
    cin >> t;

    vector<int> ind(t);
    for (int j = t - 1; j >= 0; j--) {
      string row;
      cin >> row;

      for (int k = 0; k < row.length(); k++) {
        if (row[k] == '#') {
          ind[j] = k + 1;
          break;
        }
      }
    }
    for (int i = 0; i < t; i++) {
      cout << ind[i] << " ";
    }
    cout << endl;
  }
}

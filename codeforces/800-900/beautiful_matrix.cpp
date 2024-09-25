#include <bits/stdc++.h>
using namespace std;

int main() {

  int matrix[5][5];
  int x, y;
  int ops = 0;

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      cin >> matrix[i][j];
      if (matrix[i][j] == 1) {
        x = i;
        y = j;
      }
    }
  }

  ops = abs(2 - x) + abs(2 - y);
  cout << ops << endl;
}

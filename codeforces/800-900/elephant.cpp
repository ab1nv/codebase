#include <bits/stdc++.h>
using namespace std;

int main() {
  int dist;
  cin >> dist;

  int steps = 0;
  steps = dist / 5;
  if (dist % 5 != 0) {
    steps += 1;
  }
  cout << steps << endl;
}

#include <bits/stdc++.h>
using namespace std;

#define str string

int main() {

  int n;
  cin >> n;
  int c = 0;
  bool s = true;

  while (n--) {

    int r;
    cin >> r;

    if (r == 1) {
      s = false;
      break;
    }
  }

  if (s == true)
    cout << "EASY" << endl;
  if (s == false)
    cout << "HARD" << endl;
}

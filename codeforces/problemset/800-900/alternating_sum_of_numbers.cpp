#include <bits/stdc++.h>
using namespace std;

#define str string
#define ll long long
#define all(x) (x).begin(), (x).end()

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;
    int sum = 0;

    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;

      sum += (pow(-1, i) * a);
    }
    cout << sum << endl;
  }
}

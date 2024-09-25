#include <bits/stdc++.h>
using namespace std;

#define str string
#define ll long long
#define all(x) (x).begin(), (x).end()

int main() {
  int t;
  cin >> t;

  while (t--) {
    int a, b, step;
    cin >> a >> b >> step;

    ll x = (a + step - 1) / step;
    ll y = (b + step - 1) / step;

    ll c = 0;

    if (x > y)
      c = (2 * x) - 1;
    if (x <= y)
      c = (2 * y);

    cout << c << endl;
  }
}

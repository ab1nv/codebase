#include <bits/stdc++.h>
using namespace std;

#define str string
#define ll long long
#define all(x)                                                                 \
  (x).begin(),                                                                 \
      (x).end() // sort(all(vec)) instead of sort(vec.begin(), vec.end())

int main() {
  str br = "123";
  int a, b;
  cin >> a >> b;

  br.erase(remove(all(br), (char)(a + '0')), br.end());
  br.erase(remove(all(br), (char)(b + '0')), br.end());

  cout << br << endl;
}

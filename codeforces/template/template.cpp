#include <bits/stdc++.h>
using namespace std;

// data types
using ll = long long;
using ull = unsigned long long;
using ld = long double;

// constants
const ll MOD = 1e9 + 7;
const ll INF = 1e18;

// macros
#define FAST_IO                                                                \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(nullptr);
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

// debugging
#ifdef DEBUG
#define dbg(x) cerr << #x << " = " << (x) << endl;
#else
#define dbg(x)
#endif

// utility functions
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
ll mod_add(ll a, ll b, ll m = MOD) { return (a % m + b % m + m) % m; }
ll mod_mul(ll a, ll b, ll m = MOD) { return (a % m * b % m) % m; }
ll mod_pow(ll base, ll exp, ll m = MOD) {
  ll res = 1;
  while (exp > 0) {
    if (exp % 2 == 1)
      res = (res * base) % m;
    base = (base * base) % m;
    exp /= 2;
  }
  return res;
}

void solve() {}

int main() {
  FAST_IO;
  int t = 1;
  // cin >> t;
  while (t--)
    solve();
  return 0;
}

#include <bits/stdc++.h>

using namespace std;

const long long m = 1e9 + 7;
const long long M = m - 1;

long long mul(long long a, long long b, long long mod) {
  long long aux = a % mod * b % mod;
  return (aux) % mod;
}

long long fast_pow(long long base, long long exp, long long mod) {
  long long ans = 1;
  while (exp) {
    if (exp & 1)
      ans = mul(ans, base, mod);
    exp = exp >> 1;
    base = mul(base, base, mod);
  }
  return ans;
}

int main() {
  long long num_tests;
  cin >> num_tests;

  while (num_tests--) {
    long long base, exp01, exp02;
    cin >> base >> exp01 >> exp02;

    // A^(B^C) (mod m) == A^(B^C mod (phi(m) — 1)) (mod m) == A^(B^C mod (m —
    // 2)) (mod m).
    long long ans = fast_pow(base, fast_pow(exp01, exp02, M), m);

    cout << ans << endl;
  }

  return 0;
}

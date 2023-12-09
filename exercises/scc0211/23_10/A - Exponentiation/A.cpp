#include <bits/stdc++.h>

using namespace std;

const long long M = 1e9 + 7;

long long mul(long long a, long long b) {
  long long aux = a % M * b % M;
  return (aux) % M;
}

long long fast_pow(long long base, long long exp) {
  long long ans = 1;
  while (exp) {
    if (exp & 1)
      ans = mul(ans, base);
    exp = exp >> 1;
    base = mul(base, base);
  }
  return ans;
}

int main() {
  long long num_tests;
  cin >> num_tests;

  while (num_tests--) {
    long long base, exp;
    cin >> base >> exp;

    long long ans = fast_pow(base, exp);

    cout << ans << endl;
  }

  return 0;
}

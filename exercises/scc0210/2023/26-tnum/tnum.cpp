#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll MOD = 1e9 + 7;

ll fast_pow(ll base, ll exponent) {
  base = base % MOD;
  ll res = 1;
  while (exponent) {
    if (exponent & 1)
      // res = res * base
      res = ((res % MOD) * (base % MOD)) % MOD;
    // base = base * base;
    base = ((base % MOD) * (base % MOD)) % MOD;
    exponent = exponent >> 1;
  }
  return res % MOD;
}

ll calc_prod2(ll cnt2, ll exponent) {
  return (cnt2 * (exponent + 1)) % (MOD - 1);
}

ll calc_prod1(ll base, ll exponent, ll prod, ll cnt2) {
  ll value1 = fast_pow(prod, exponent + 1);
  ll value2 = fast_pow(fast_pow(base, (exponent * (exponent + 1) / 2)), cnt2);
  return (value1 * value2) % MOD;
}

ll calc_sum(ll sum, ll base, ll exponent) {
  ll value1 = (sum * (fast_pow(base, exponent + 1) - 1)) % MOD;
  ll value2 = fast_pow(base - 1, MOD - 2);
  return (value1 * value2) % MOD;
}

int main() {
  int num;
  cin >> num;

  ll cont = 1;
  ll sum = 1;
  ll prod = 1;
  ll cnt2 = 1;

  while (num--) {
    ll base, exponent;
    cin >> base >> exponent;

    // N = a^p ∗ b^q ∗ c^r …
    cont = (cont * (exponent + 1)) % MOD;

    // Formula na pasta
    sum = calc_sum(sum, base, exponent);

    // Impossível compreender
    prod = calc_prod1(base, exponent, prod, cnt2);
    cnt2 = calc_prod2(cnt2, exponent);
  }

  cout << cont << " " << sum << " " << prod << endl;

  return 0;
}
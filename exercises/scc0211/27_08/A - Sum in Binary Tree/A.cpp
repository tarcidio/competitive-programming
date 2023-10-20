#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    long long num;
    cin >> num;
    long long sum = 0;
    while (num >= 1) {
      sum += num;
      num = num / 2;
    }
    printf("%lld\n", sum);
  }

  return 0;
}

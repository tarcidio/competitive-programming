#include <bits/stdc++.h>

using namespace std;

const int MAX = 2e6 + 3;
int kmp[MAX];

int main() {
  string p, t;
  cin >> t >> p;
  string s = p + '#' + t;

  // KMP
  int count = 0;
  kmp[0] = 0;
  for (int i = 1; i < s.size(); i++) {
    int j = kmp[i - 1];
    while (j > 0 && s[i] != s[j])
      j = kmp[j - 1];
    kmp[i] = s[i] == s[j] ? j + 1 : 0;
    if (kmp[i] == p.size())
      count++;
  }

  cout << count << endl;

  return 0;
}

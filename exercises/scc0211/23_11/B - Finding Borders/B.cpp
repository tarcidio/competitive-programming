#include <bits/stdc++.h>

using namespace std;

const int MAX = 2e6 + 3;
int kmp[MAX];

int main() {
  string s;
  cin >> s;

  // KMP
  vector<int> ans;
  kmp[0] = 0;
  for (int i = 1; i < s.size(); i++) {
    int j = kmp[i - 1];
    while (j > 0 && s[i] != s[j])
      j = kmp[j - 1];
    kmp[i] = s[i] == s[j] ? j + 1 : 0;
  }

  // Captura kmp relativos a ultima letra
  int j = kmp[s.size() - 1];
  // Se a ultima letra tem este valor de kmp, entao
  // podemos dar um pulo para o seu kmp - 1 e tudo que
  // tiver antes sera igual
  while (j != 0) {
    ans.push_back(j);
    j = kmp[j - 1];
  }

  sort(ans.begin(), ans.end());

  for (auto it : ans)
    cout << it << ' ';

  return 0;
}

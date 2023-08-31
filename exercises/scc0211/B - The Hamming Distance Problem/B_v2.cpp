#include <bits/stdc++.h>

using namespace std;

int H;
vector<string> ans;
void solve(int N, int num1, string historic) {
  if (num1 == H) {
    if (N != 0) {
      while (N--) {
        historic += '0';
      }
    }
    ans.push_back(historic);
    return;
  }

  string this_historic = historic;
  for (int i = 1; i <= N; i++) {
    this_historic = historic + '1';
    solve(N - i, num1 + 1, this_historic);
    historic += '0';
  }
}

int main() {
  int num_test;
  cin >> num_test;

  while (num_test--) {
    int N;
    cin >> N >> H;
    solve(N, 0, "");
    for (auto it = ans.end(); it != ans.begin(); it--)
      cout << *it << endl;
    ans.clear();
  }
}

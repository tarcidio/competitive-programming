#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;
int solve(int num) {
  vector<int> memo(num + 1, 0);

  for (int i = 1; i <= num; i++) {
    memo[i] = INF;
    string temp = to_string(i);
    for (char digit : temp)
      memo[i] = min(memo[i], memo[i - (digit - '0')] + 1);
  }

  return memo[num];
}

int main() {
  int num;
  cin >> num;
  cout << solve(num);
}

#include <bits/stdc++.h>

using namespace std;

const int MAX = 301;
int days[MAX];
int memo[MAX];

int main() {
  int num_days;
  cin >> num_days;

  int x, y, z; // cost 1 day, cost 2 day and cost 3 day
  cin >> x >> y >> z;

  for (int i = 0; i < num_days; i++) {
    cin >> days[i];
  }

  memo[0] = min(x, min(y, z));
  for (int i = 1; i < num_days; i++) {
    // Calculate cost 1 day
    int cost1 = memo[i - 1] + x;

    // Calculate cost 7 day
    int k = i - 1;
    while (k >= 0 && days[i] - days[k] <= 7)
      k--;
    int cost7 = k < 0 ? y : memo[k] + y;

    // Calculate cost 30 day
    k = i - 1;
    while (k >= 0 && days[i] - days[k] <= 30)
      k--;
    int cost30 = k < 0 ? z : memo[k] + z;
    memo[i] = min(cost1, min(cost7, cost30));
  }

  cout << memo[num_days - 1] << endl;

  return 0;
}
/*
5
5 7 10
1 2 3 10 20
*/
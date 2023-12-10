/*
  Calculate the number of paths from upper-left square to
  the lower-right square. You can only move right or down;
*/

#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;
typedef vector< vector<int> > vvi;
typedef vector< vector<char> > vvc;
int n;

int solve(vvi memo, vvc mapTrap) {
  memo[0][1] = 1;
  for(int i = 1; i <= n; i ++)
    for(int j = 1; j <= n; j ++){
      memo[i][j] = mapTrap[i][j] == '*'? 0 : memo[i - 1][j] + memo[i][j - 1];
      memo[i][j] %= MOD;
    }
      
  return memo[n][n];
}

int main() {
  cin >> n;
  vvi memo(n + 1, vector<int> (n + 1, 0));
  vvc mapTrap(n + 1, vector<char> (n + 1, '*'));
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      cin >> mapTrap[i][j];

  cout << solve(memo, mapTrap);

  return 0;
}
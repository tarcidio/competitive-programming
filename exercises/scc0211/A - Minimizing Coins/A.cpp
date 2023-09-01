#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;
int solve(vector<int> coins, int num_coin, int value){
    vector<int> memo(value + 1, 0);
    
    for(int i = 1; i <= value; i++){
        memo[i] = INF;
        for(auto coin : coins)
            if(i - coin >= 0)
                memo[i] = min(memo[i], memo[i - coin] + 1);
    }
    
    if (memo[value] == INF)
        return -1;
    else
        return memo[value];
}

int main() {
  int num_coin, value;
  cin >> num_coin >> value;
  vector<int> coins;
  for(int i = 0; i < num_coin; i++){
      int coin; cin >> coin;
      coins.push_back(coin);
  }
  cout << solve(coins, num_coin, value) << endl;
}

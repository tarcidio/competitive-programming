#include <bits/stdc++.h>

using namespace std;

int main() {
  int T;
  cin >> T;

  while(T--){
    int value, num_coins;
    cin >> value >> num_coins;
    
    //Reading
    vector<int> coins;
    for(int i = 0 ; i < num_coins; i++){
      int coin;
      cin >> coin;
      coins.push_back(coin);
    }

    //In competitive programming, it's better static declaration
    vector<int> memo(value + 1, 0x3f3f3f3f);
    memo[0] = 0;
    for(int i = 1; i <= value; i++){
      for(auto it : coins)
        if(i >= it)
          memo[i] = min(memo[i], 1 + memo[i - it]);
    }
    
    cout << memo[value] << endl;
  }
  
  return 0;
}

/*
1
100
10
1 2 3 5 6 7 9 12 4 15
*/
#include <bits/stdc++.h>

using namespace std;

vector<tuple<int,int,int>> orders;

//o1 < o2
bool cmp(tuple<int,int,int> o1, tuple<int,int,int>o2){
    return get<0>(o1) + get<1>(o1) < get<0>(o2) + get<1>(o2);
}

int solve(int num_orders){
    vector<int> memo (num_orders, 0);
    
    memo[0] = get<2>(orders[0]);
    
    for(int i = 1; i < num_orders; i++){
         memo[i] = get<2>(orders[i]);
         for(int j = 0; j < i; j++){
            if( get<0>(orders[i]) >= get<0>(orders[j]) + get<1>(orders[j]))
              memo[i] = max(memo[i], memo[j] + get<2>(orders[i]));
         }
         
         //Maximum between decide to chose this order or not
         memo[i] = max(memo[i], memo[i-1]);
    }
    
    return memo[num_orders - 1];
}

int main() {
  int t;
  cin >> t;
  
  while(t--){
    int num_orders;
    cin >> num_orders;
    
    for(int i =0; i < num_orders; i++){
        int start, duration, price;
        cin >> start >> duration >> price;
        orders.push_back(make_tuple(start,duration,price));
    }
    
    sort(orders.begin(),orders.end(),cmp);
    
    cout << solve(num_orders) << endl;
    
    orders.clear();
  }
  
}

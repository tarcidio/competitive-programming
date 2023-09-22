#include <bits/stdc++.h>

using namespace std;

int main() {
  long long t;
  cin >> t;
  //(2,3)
  while(t--){
    long long row, col;
    cin >> row >> col;
    //Discovery the biggest value
    long long max_coord = max(row, col);
    //Then, we can find the bigger number in the matrix
    long long max_value = max_coord*max_coord;
    long long min_value = max_value - 2*max_coord + 2;
    //But we need know whether the bigger number is in down-left or upper-right
    long long even = max_coord%2 == 0;
    //Find the answerg
    long long ans;
    if (even){//Down-left
      if(max_coord == row){
        ans = max_value - (col - 1);
      }else if (max_coord == col){
        ans = min_value + (row - 1);
      }
    }else{//Upper-right
      if(max_coord == row){
        ans = min_value + (col - 1);
      }else if (max_coord == col){
        ans = max_value - (row - 1);
      }
    }

    cout << ans << endl;
  }
  
}

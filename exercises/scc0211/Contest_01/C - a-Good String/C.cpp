#include <bits/stdc++.h>

using namespace std;

int solve(string s, int size, char target){
  if(size == 1){
    if(target == s[0])
      return 0;
    else
      return 1;
  }
  
  int first_half = 0;
  int second_half = 0;
  int half_size = size/2;

  for(int i = 0; i < half_size; i++){
    if(s[i] == target)
      first_half++;
    if(s[i + half_size] == target)
      second_half++;
  }

  /*cout << "String: " << s << endl;
  cout << "First half em " << first_half << endl;
  cout << "Second half em " << second_half << endl;*/
  int cost_first_half = solve(s.substr(0,half_size), half_size, target + 1);
  int cost_second_half = solve(s.substr(half_size,size), half_size, target + 1);

  return min(
      (half_size - first_half) + cost_second_half,
      (half_size - second_half) + cost_first_half
  );
  /*string half_s;
  if(first_half > second_half){
    half_s = s.substr(half_size,size);//s[size/2:]
  }else{
    half_s = s.substr(0,half_size);//s[size/2:]
  }
  
  int max_num_target = max(first_half, second_half);
  return (half_size - max_num_target) + solve(half_s, half_size, target + 1);*/
}

int main() {
  int t;
  cin >> t;

  while(t--){
    int size;
    cin >> size;
    string s;
    cin >> s;

    cout << solve(s, size, 'a') << endl;
  }
  
}

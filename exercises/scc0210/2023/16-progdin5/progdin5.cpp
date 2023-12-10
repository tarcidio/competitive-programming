#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vii;

int main() {
  string s1, s2;
  cin >> s1 >> s2;
  //Desconsider the first caracterer of both strings
  s1 = ' ' + s1; 
  s2 = ' ' + s2; 
  //Run codes problem
  int s1_size = (int) s1.size();
  int s2_size = (int) s2.size();

  //Inicialize memo
  //rows: s1
  //columns: s2
  vii memo(s1.size() + 1, vi(s2.size() + 1, 0));
  
  //Inicialize the memo[i][0]
  for(int i = 0; i <= s1_size; i++)
    memo[i][0] = i;
  //Inicialize the memo[0][j]
  for(int j = 0; j <= s2_size; j++)
    memo[0][j] = j;

  //Look at the tree in directory. There are overlappins!
  //So, just "consider each possible and other possibles
  //will use this possible already calculated"
  for(int i = 1; i <= s1_size; i++)
    for(int j = 1; j <= s2_size; j++){
      if(s1[i] == s2[j])
        memo[i][j] = memo[i-1][j-1];
      else{
        int remove_s2 = memo[i][j - 1] + 1;//Insert
        int remove_s1 = memo[i-1][j] + 1;//Remove
        int remove_both = memo[i-1][j-1] + 1;//Replace
        memo[i][j] = min(remove_s2, remove_s1);
        memo[i][j] = min(memo[i][j], remove_both);
      }
    }

  cout << memo[s1.size()][s2.size()];
  return 0;
}
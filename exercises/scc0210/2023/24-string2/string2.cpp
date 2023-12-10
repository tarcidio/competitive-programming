#include <bits/stdc++.h>

using namespace std;

int main() {
  string input;
  cin >> input;
  int size_string = input.size();

  vector<int> lcs (size_string);
  vector<int> distinct (size_string, 0);
  vector<string> suffixes;

  //Detect suffixes
  for(int i = 0; i < size_string; i ++){
    string substring = input.substr(i, size_string - i);
    suffixes.push_back(substring);
  }

  //Sort suffixes
  sort(suffixes.begin(), suffixes.end());

  //Calculate lcs: number of characters matching previous suffix
  //Calculate size_suffixes
  lcs[0] = 0;
  //size_suffixes[0] = suffixes[0].size();
  for(int i = 1; i < size_string; i++){
    string suf1 = suffixes[i];
    string suf2 = suffixes[i-1];
    int j = 0;
    while(suf1[j] == suf2[j])
      j++;
    lcs[i] = j;
  }

  //Calculate number of substrings distinct
  for(int i = 0; i < size_string; i ++){
    for(int j = lcs[i]; suffixes[i][j] != '\0';j++)
      distinct[j]++;
  }

  //Print the answer
  for(int it : distinct)
    cout << it << " ";
  
  return 0;
}
#include <bits/stdc++.h>

using namespace std;
vector<int> kmp;

int kmp_function(string string_kmp, int size_pattern){

  int size_kmp = string_kmp.size();
  kmp = vector<int> (size_kmp, 0);
  
  kmp[0] = 0;
  int count = 0;
  
  for(int i = 1; i < size_kmp; i++){
    int j = kmp[i-1];
    
    /* If can't use '#'
    while (j >= size_pattern)
      j = kmp[j-1];
    */
    while(j && string_kmp[j] != string_kmp[i])
        j = kmp[j-1];
    kmp[i] = string_kmp[j] == string_kmp[i] ? j + 1 : 0;
    //i >= 2*size_pattern -1 because, in case that the pattern is "aa", the real string
    //start after size_pattern and the real match just happens after 2*size_pattern -11 
    if(kmp[i] >= size_pattern) //If can't use '#': && i >= 2*size_pattern - 1) 
      count++;
  }
  
  return count;
}

int main() {
  string input;
  string pattern;
  cin >> input >> pattern;
  
  string string_kmp = pattern + "#" + input;
  int size_pattern = pattern.size();
  
  cout << kmp_function(string_kmp, size_pattern) << endl;
  
  return 0;
}
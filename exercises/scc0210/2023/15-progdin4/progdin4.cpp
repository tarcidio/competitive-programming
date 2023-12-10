#include <bits/stdc++.h>

using namespace std;

const int MAX_PAGES = 1e4 + 1;
const int MAX_PRICES = 1e5 + 1;
int prices[MAX_PRICES];
int pages[MAX_PAGES];
int num_books, total_price;

int maximum_pages(vector< vector<int> > memo){
  for(int i = 1; i <= num_books; i++){
    for(int j = 1; j <= total_price; j++){
      if(prices[i] <= j){
        memo[i][j] = max(memo[i - 1][j], pages[i] + memo[i  -1][j - prices[i]]);
      }else
        memo[i][j] = memo[i - 1][j];
    }
  }
  
  return memo[num_books][total_price];
}

int main() {
  
  cin >> num_books >> total_price;
  vector< vector<int> > memo (num_books + 1, vector<int> (total_price + 1, 0));
  
  for(int i = 1; i <= num_books; i++)
    cin >> prices[i];
  for(int i = 1; i <= num_books; i++)
    cin >> pages[i];

  cout << maximum_pages(memo);
  return 0;
}
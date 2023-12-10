#include <bits/stdc++.h>

using namespace std;

void printGreater(string num, int K) {
  // Queue
  priority_queue<char> pq_digit;
  // Processing information
  int i = 0; // Index of current digit of the number
  for (char c : num) {
    pq_digit.push(c);
    i++;
  }

  i = 0; // Index of current digit of the number
  while (K-- && !pq_digit.empty()) {
    //Read queue
    char greater = pq_digit.top();
    pq_digit.pop();
    char aux = num[i];
    num[i] = greater;
    //Find index
    int indexGreater;
    for(int j = i; j < (int) num.size(); j++){
      if(num[j] == greater)
        indexGreater = j;
    }
    //Update
    num[indexGreater] = aux;
    i++;
  }

  cout << num << endl;
}

int main() {
  // Reading
  string num;
  int K;
  while (cin >> num >> K)
    printGreater(num, K);

  return 0;
}

// 0123456789 5
// 9876543210
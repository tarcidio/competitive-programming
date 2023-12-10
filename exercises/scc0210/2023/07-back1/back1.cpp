#include <bits/stdc++.h>

using namespace std;

void printSpace(string input, int index, string subword) {
  index++;
  if (index >= (int)input.size())
    cout << subword << endl;
  else {
    printSpace(input, index, subword + input[index]);
    printSpace(input, index, subword + ' ' + input[index]);
  }
}

int main() {
  string input;
  string subword;

  while (getline(cin, input)) {
    subword = "";
    subword += input[0];
    printSpace(input, 0, subword);
    cout << endl;
  }

  return 0;
}
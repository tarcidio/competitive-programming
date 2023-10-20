#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int len, xor_geral = 0;
    cin >> len;

    for(int i = 0; i < len; i++){
        int input;
        cin >> input;
        xor_geral ^= input;
    }

    // if(len%2){//odd
    //     if(xor_geral == 0)
    //         cout << 0 << endl;
    //     else
    //         cout << xor_geral << endl;
    // }else{//even
    //     if(xor_geral == 0)
    //         cout << 0 << endl;
    //     else
    //         cout << -1 << endl;
    // }

    if (xor_geral == 0)
        cout << 0 << endl;
    else if (len & 1)//odd
        cout << xor_geral << endl;
    else
        cout << -1 << endl;
  }

  return 0;
}

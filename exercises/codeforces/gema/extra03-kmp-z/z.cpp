#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e3 + 1;
int z[MAX];

void z_function(string s){
    z[0] = 0;
    int l = 0, r = 0;
    for(int i = 1; i < s.size(); ++i){
        if(i > r)
            l = r = i;
        z[i] = min(z[i - l], r - i);

        while(s[i + z[i]] == s[z[i]] && i + z[i] < s.size()){
            z[i]++;
            l = i;
            r = i + z[i];
        }
    }
}

int main (){
    string input = "abacababa";

    z_function(input);
    cout << "Z vector: ";
    for(int i = 0; i < input.size(); i++)
        cout << z[i] << " ";

    return 0;
}

/*
abaabacababa
*/
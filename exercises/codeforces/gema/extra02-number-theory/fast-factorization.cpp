#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e3 + 1;
int sieve[MAX];

//Using sieve
vector<int> fast_factorization(int num){
       
    for(int i = 2; i <= num; i++){
        if(sieve[i] == 0)
            sieve[i] = i;
        for(int j = i*i; j <= num; j+= i)
            sieve[j] = i;
    }

    vector<int> ans;
    while(num != 1){
        ans.push_back(sieve[num]);
        num /= sieve[num];
    }

    return ans;
}

int main (){
    int input;
    cin >> input;

    cout << "The factors of " << input << " is: ";
    for(auto d : fast_factorization(input)){
        cout << d << " ";
    }

    return 0;
}
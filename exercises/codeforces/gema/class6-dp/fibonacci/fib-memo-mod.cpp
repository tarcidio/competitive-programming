#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e3 + 10;
const int MOD = 1e9 + 10;
int memo[MAX];

int fib(int n){
    if(n <= 1)
        return n;
    else if(memo[n] != 0)
        return memo[n];
    else
        return memo[n] = (fib(n - 1) + fib(n - 2))%MOD;
}

/*
Mod property
1. (a + b)%c = (a%c + b%c)%c
2. (a * b)%c = (a%c * b%c)%c (OBS: Take care with memory)
3. (a - b)%c = (a%c - b%c)%c
    3.1 a - b)%c = (a%c - b%c + c)%c (OBS: To negative results)
*/

int main(){

    int n;
    cin >> n;
    cout << fib(n);

    return 0;
}
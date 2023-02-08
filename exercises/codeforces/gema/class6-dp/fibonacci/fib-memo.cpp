#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e3 + 10;
int memo[MAX];

int fib(int n){
    if(n <= 1)
        return n;
    else if(memo[n] != 0)
        return memo[n];
    else
        return memo[n] = fib(n - 1) + fib(n - 2);
}

int main(){

    int n;
    cin >> n;
    cout << fib(n);

    return 0;
}
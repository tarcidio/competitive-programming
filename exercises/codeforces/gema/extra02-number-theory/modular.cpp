#include <bits/stdc++.h>

using namespace std;

const int M = 11;

int add(int a, int b){
    return (a%M + b%M)%M;
}

int sub(int a, int b){
    return (a%M - b%M + M)%M;
}

int mul(int a, int b){
    long long aux = a%M * b%M;
    return (aux)%M;
}

/*int fast_pow(int base, int exp){
    if(exp == 0)
        return 1;
    int ans = fast_pow(base, exp/2);
    ans = mul(ans, ans);
    if(exp%2)
        ans = mul(ans, base);
    return ans;
}*/

int fast_pow(int base, int exp){
    int ans = 1;
    while(exp){
        if(exp & 1)
            ans = mul(ans, base);
        exp = exp >> 1;
        base = mul(base, base);
    }
    return ans;
}

int inv(int a){
    return fast_pow(a, M - 2);
}

int main (){
    int input;
    cin >> input;

    cout << inv(input);
    return 0;
}
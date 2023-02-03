#include <bits/stdc++.h>

using namespace std;

//Max number of coins type
const int NMAX = 1e2 + 10;
//Max number of value
const int VMAX = 1e2 + 10;
//Define infinite
const long long INF = 1e17;
//Coin array: stores the value of coin
int coin[NMAX];
//Number of coins type
int num_coin;
//Memoization
long long memo[NMAX][VMAX];

long long solve(int coin_index, long long  value){

    //Basic case
    if(value == 0){//We always have the number of coins to zero value
        return 0;
    }else if(coin_index == num_coin){//If that, than the algorithm gone in the inexist coin
        return INF;
    }else if(memo[coin_index][value] != -1){//If just is calculate
        return memo[coin_index][value];
    }

    //In other case, let's assume that there aren't number of coins that satisfy
    long long res = INF;

    //If we use a coin
    if(coin[coin_index] <= value)
        res = min(res, 1 + solve(coin_index, value - coin[coin_index]));
    
    //If we don't use a coin
    res = min(res, solve(coin_index + 1, value));

    memo[coin_index][value] = res;//Calculate, than store

    return res;
}

int main(){
    int value;
    cin >> num_coin >> value;
    for(int i = 0; i < num_coin; i++)
        cin >> coin[i];

    memset(memo, -1 ,sizeof(memo));

    cout << solve(0, value);
    return 0;
}

/*
6 16
1 5 10 25 50 100
*/
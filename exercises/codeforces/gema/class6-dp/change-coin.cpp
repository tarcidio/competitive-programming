#include <bits/stdc++.h>

using namespace std;

const int NMAX = 1e2 + 10;
const long long INF = 1e17;
int coin[NMAX];
int num_coin;

long long solve(int coin_index, long long  value){

    //Basic case
    if(value == 0){//We always have the number of coins to zero value
        return 0;
    }else if(coin_index == num_coin){//If that, than the algorithm gone in the inexist coin
        return INF;
    }

    //In other case, let's assume that there aren't number of coins that satisfy
    long long res = INF;

    //If we use a coin
    if(coin[coin_index] <= value)
        res = min(res, 1 + solve(coin_index, value - coin[coin_index]));
    
    //If we don't use a coin
    res = min(res, solve(coin_index + 1, value));

    return res;
}

int main(){
    int value;
    cin >> num_coin >> value;
    for(int i = 0; i < num_coin; i++)
        cin >> coin[i];

    cout << solve(0, value);
    return 0;
}

//6 16
//1 5 10 25 50 100
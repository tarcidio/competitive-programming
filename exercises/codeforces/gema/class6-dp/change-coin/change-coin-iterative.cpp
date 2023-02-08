#include <bits/stdc++.h>

using namespace std;

//Max number of coins type
const int NMAX = 1e2 + 10;//more than that is beyond capacity of matrices
//Max number of value
const int VMAX = 1e2 + 10;//more than that is beyond capacity of matrices
//Define infinite
const long long INF = 1e17;
//Coin array: stores the value of coin
int coin[NMAX];
//Number of coins type
int num_coin;
//Memoization
long long memo[NMAX][VMAX];

void solve_iterative(){

    //Basic cases
    for(int i = 0; i < NMAX; i++)//We always have the number of coins to zero value
        memo[i][0] = 0;
    for(int val = 1; val < VMAX; val++)//If that, than the algorithm gone in the inexist coin
        memo[num_coin][val] = INF;

    for(int i = num_coin - 1; i >= 0; i--){
        for(int val = 0; val < VMAX; val++){
            //In other case, let's assume that there aren't number of coins that satisfy
            long long res = INF;

            if(coin[i] <= val)//If we use a coin
                res = min(res, 1 + memo[i][val - coin[i]]);
            //If we don't use a coin
            res = min(res, memo[i+1][val]);

            //Stores the value
            memo[i][val] = res; 
        }
    }

}

int main(){
    int value;
    cin >> num_coin >> value;
    for(int i = 0; i < num_coin; i++)
        cin >> coin[i];

    solve_iterative();

    cout << memo[0][value];

    return 0;
}

/*
4 16
1 5 10 25
*/
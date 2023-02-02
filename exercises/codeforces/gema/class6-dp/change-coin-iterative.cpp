#include <bits/stdc++.h>

using namespace std;

const int NMAX = 1e2 + 10;
const int VMAX = 1e2 + 10;
const long long INF = 1e17;
int coin[NMAX];
int num_coin;

long long memo[NMAX][VMAX];

long long solve(int coin_index, long long value){

    //Basic cases
    for(int i = 0; i < num_coin; i++)//We always have the number of coins to zero value
        memo[i][0] = 0;
    for(int val = 1; val <= value; val++)//If that, than the algorithm gone in the inexist coin
        memo[num_coin][val] = INF;

    

    for(int i = num_coin - 1; i >= 0; i--){
        for(int val = 0; val <= value; val++){
            //In other case, let's assume that there aren't number of coins that satisfy
            long long res = INF;

            if(coin[i] <= val)//If we use a coin
                res = min(res, memo[i][value - coin[i]]);
            //If we don't use a coin
            res = min(res, memo[i+1][value]);

            //Stores the value
            memo[i][value] = res; 
        }
    }

    //Qual valor vai ser retornado? Fazer o nao iterativa mas com memo também
    return memo[0][value];
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
//Problem: How many numbers are there such that the digit number 1 is even?
//Complexity: O(states * transitions) = O( (100**2*2) * (10)) = O(4000)
//OBS: number always 100 digits
//Or, O(40n) = O(n)

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e3 + 10;
const int MOD = 1e9 + 10;
int memo[MAXN][2][2];
string num;

int solve(int index_num, bool eq, int par){
    //Base cases
    if(index_num == num.size())//If is the end
        return par^1;
    else if(memo[index_num][eq][par] != -1)//Memoization
       return memo[index_num][eq][par];
    
    //Decide: scroll through all digits?
    int lim = 9;
    if(eq)//If eq true, so no. We will scroll through as many as possible
        //Tecnique: when the variable is integer, he transform the caracterer as integer using the ascii table 
        lim = num[index_num] - '0';
    
    int res = 0;
    //Through digits
    for(int digit = 0; digit <= lim; digit++){
        //If digit = 1, so change parity of amount of digit
        int new_par = par;
        if(digit == 1)
            new_par = par^1;
        
        //If digit != lim, so we can consider all digits
        bool new_eq = eq;
        if(digit != lim)
            new_eq = false;
        
        res = (res + solve(index_num + 1, new_eq, new_par))%MOD;
    }

    return memo[index_num][eq][par] = res;
}

int main(){

    cin >> num;
    memset(memo, -1, sizeof(memo));
    cout << solve(0, true, 0);

    return 0;
}
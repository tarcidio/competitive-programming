//NAME: Yuhao and a Parenthesis
//

#include <bits/stdc++.h>

using namespace std;

stack<char> st;

int main (){
    int n;
    cin >> n;

    string input;
    for(int i = 0; i < n; i++){
        string tmp;
        cin >> tmp;
        input += tmp;
    }

    int balance = 0, combo = 0, iteration = 0;
    for(char it: input){
        if('('){
            balance++;
        }else{
            if(balance > 0){
                balance--;
                combo++;
                iteration++;
            }
        }
        
        if(combo > 0){
            iteration++;
        }

        if( (combo == 1 && iteration > 1) || combo > 1){

        }
    }

    return 0;
}
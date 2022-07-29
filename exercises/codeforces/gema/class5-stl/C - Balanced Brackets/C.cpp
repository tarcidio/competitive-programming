//NAME: Balanced Brackets
//O(N)
#include <bits/stdc++.h>

using namespace std;

/*int main(){
    string input;
    cin >> input;

    int open = 0, close = 0;
    bool sol = true;

    for(auto it = input.begin(); it != input.end(); it++){
        if(*it == '(')
            open++;
        else if(*it == ')')
            close++;
        
        if(close > open){
            sol = false;
            break;
        }
    }

    close == open && sol ? cout << "YES" : cout << "NO";

    return 0;
}*/

int main(){
    string input;
    cin >> input;

    int balance = 0;//open - close
    bool sol = true;

    for(char it : input){
        if(it == '(')
            balance++;
        else if(it == ')')
            balance--;
        
        if(balance < 0){
            sol = false;
            break;
        }
    }

    balance == 0 && sol ? cout << "YES" : cout << "NO";

    return 0;
}
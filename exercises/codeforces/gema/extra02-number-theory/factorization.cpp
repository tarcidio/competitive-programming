#include <bits/stdc++.h>

using namespace std;

vector<int> factorization(int num){
    vector<int> ans;
    for(int i = 2; i*i <= num; i++){
        while(num%i == 0){
            ans.push_back(i);
            num /= i;
        }
    }
    //Just in case that last component is a largest prime (ex: 7)
    if(num > 1)
        ans.push_back(num);
    return ans;
}

int main (){
    int input;
    cin >> input;

    cout << "The factors of " << input << " is: ";
    for(auto d : factorization(input)){
        cout << d << " ";
    }

    return 0;
}
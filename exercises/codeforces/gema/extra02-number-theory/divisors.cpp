#include <bits/stdc++.h>

using namespace std;

vector<int> divisors(int num){
    vector<int> ans;
    for(int i = 1; i*i <= num; i++){
        if(num%i == 0){
            ans.push_back(i);
            if(i*i != num)
                ans.push_back(num/i);
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}

int main (){
    int input;
    cin >> input;

    cout << "The divisors of " << input << " is: ";
    for(auto d : divisors(input)){
        cout << d << " ";
    }

    return 0;
}
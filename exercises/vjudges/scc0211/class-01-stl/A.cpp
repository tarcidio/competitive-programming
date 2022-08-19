#include <bits/stdc++.h>

using namespace std;

map <vector<int>, int> store;

ui

int main(){
    int n;
    cin >> n;
    int popularity = 0;

    while(n){
        vector<int> input;
        for(int i = 0; i < 5; i++){
            int elem_input;
            cin >> elem_input;
            input.push_back(elem_input);
        }
        sort(input.begin(), input.end());
        int apparition = store[input]++;
        if(apparition > popularity)
            popularity = apparition;
        input.clear();
        cin >> n;
    }
    
    int ans = 0;
    for(auto it : store){
        if(it->second == popularity)
            ans++;
    }

    cout << ans << endl;

    return 0;
}

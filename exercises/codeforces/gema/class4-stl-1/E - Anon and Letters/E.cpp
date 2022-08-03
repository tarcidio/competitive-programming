//NAME: Anon and Letters
//O(N)

#include <bits/stdc++.h>

using namespace std;

int main (){
    string input;
    getline(cin, input);

    set <char> dist_letters;

    for(char it : input){
        if(it >= 'a' && it <= 'z')
            dist_letters.insert(it);
    }

    cout << dist_letters.size();

    return 0;
}
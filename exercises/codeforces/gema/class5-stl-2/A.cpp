//NAME: Votes in the Poll
//O(N)

#include <bits/stdc++.h>

using namespace std;

int main (){
    int n;
    map<string, string> votes;//tie(name, day) = p;
    string name, day;

    cin >> n;
    for(int i = 0; i < n; i++){//O(N)
        cin >> name >> day;
        if(!votes.count(name))//O(logn)
            votes[name] = day;
    }

    //count the votes
    int qua = 0, sex = 0;
    for(auto it = votes.begin(); it != votes.end(); it++){//O(N)
        if(it->second == "quarta")
            qua++;
        else if(it->second == "sexta")
            sex++;
    }

    if(qua == sex)
        cout << "empate" << endl;
    else if(qua > sex)
        cout << "quarta" << endl;
    else if(qua < sex)
        cout << "sexta" << endl;

    return 0;
}
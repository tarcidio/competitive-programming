#include <bits/stdc++.h>

using namespace std;

int main(){
    int num_cases;
    cin >> num_cases;
    
    for(int i = 0; i < num_cases; i++){
        int num_snowflakes;
        cin >> num_snowflakes;
        set<int> snowflakes;
        for(int j = 0; j < num_snowflakes; j++){
            int id_snowflake;
            cin >> id_snowflake;
            snowflakes.insert(id_snowflake);
        }
        cout << snowflakes.size() << endl;
    }
    return 0;
}

/*
1
12
7
4
0
9
4
8
8
2
4
5
5
1
*/

//7 4 0 9 8 2 5 1

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

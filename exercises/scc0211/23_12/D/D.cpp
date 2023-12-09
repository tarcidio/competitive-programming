#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int num_heaps, size_heap;
        cin >> num_heaps;
        int ans = 0;
        for(int i = 0; i < num_heaps; i++){
            cin >> size_heap;
            if (size_heap & 1) ans = 1;
        }
        //ans ? cout << "first" << endl : cout << "second" << endl;
        cout << (ans ? "first" : "second") << endl;
    }

    return 0;
}

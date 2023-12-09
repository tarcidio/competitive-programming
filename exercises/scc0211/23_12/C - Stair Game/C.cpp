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
            if (i&1) ans ^= size_heap;
        }
        ans ? cout << "first" << endl : cout << "second" << endl;
    }

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int num_heaps, size_heap;
        cin >> num_heaps;
        int nim_sum = 0;
        for(int i = 0; i < num_heaps; i++){
            cin >> size_heap;
            nim_sum ^= size_heap % 4;
        }
        nim_sum ? cout << "first" << endl : cout << "second" << endl;
    }

    return 0;
}

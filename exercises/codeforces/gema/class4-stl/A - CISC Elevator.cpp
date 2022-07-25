#include <bits/stdc++.h>

using namespace std;

int main(){

    int n, h;
    cin >> n >> h;

    int rel[100001];
    for(int i = 0; i < n; i++)
        cin >> rel[i];

    int tandares = 0;
    for(int i = 1; i < n; i++){
        tandares += rel[i] - rel[i-1];
    }

    cout << tandares * 4 << endl;

    return 0;
}

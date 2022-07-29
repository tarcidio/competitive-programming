//NAME: A - CISC Elevator
//O(N)

#include <bits/stdc++.h>

using namespace std;

int main(){

    int n, h;//number of floors traveled and number of floors in the building
    cin >> n >> h;

    int rep[100001];//floors report
    for(int i = 0; i < n; i++)
        cin >> rep[i];

    int tfloors = 0;//total floors
    for(int i = 1; i < n; i++)
        tfloors += abs(rep[i] - rep[i-1]);

    cout << tfloors * 4 << endl;

    return 0;
}

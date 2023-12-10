#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        long long int p1[2], p2[2], p3[2], v1[2], v2[2], cross;
        cin >> p1[0] >> p1[1] >> p2[0] >> p2[1] >> p3[0] >> p3[1];
        v1[0] = p2[0] - p1[0];
        v1[0] = p2[1] - p1[1];
        v2[0] = p3[0] - p1[0];
        v2[0] = p3[1] - p1[1];
        cross = (p2[0] - p1[0])*(p3[1] - p1[1]) - (p2[1] - p1[1])*(p3[0] - p1[0]);
        if(cross > 0)
            cout << "LEFT" << endl;
        else if(cross < 0)
            cout << "RIGHT" << endl;
        else
            cout << "TOUCH" << endl;
    }

    return 0;
}

//NAME: Brutality
//O(n)

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAX_N = 2e5 + 10;
int n, k;
int a[MAX_N];
string s;
priority_queue<int> pq;//The priority queue that store the hit damage values of a same letter sequence

//In the end of same letter sequence, calculate the sum of first k elements of pq
void calculate_sum_in_pq(long long *dmg){
    //Calculate
    for(int j = 0; j < k && !pq.empty(); j++){
        *dmg += pq.top();
        pq.pop();
    }
    //Clear the pq
    while(!pq.empty()){
        pq.pop();
    }
}

int main(){
    //Reading
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    cin >> s;

    //Damage
    long long dmg = 0;
    //ll dmg = 0;

    char cur = s[0];
    //Walk the string
    for(int i = 0; i < n; i++){
        //If equal, than the sequence isn't over
        if(s[i] == cur){
            pq.push(a[i]);
        } else {
            //Sequence is over
            calculate_sum_in_pq(&dmg);
            //Prepare to next iteration
            cur = s[i];
            pq.push(a[i]);
        }
    }

    //This line is dedicate to last letter
    calculate_sum_in_pq(&dmg);

    cout << dmg;

    return 0;
}
//NAME: Array Division
//O(n^2)

#include <bits/stdc++.h>

using namespace std;

//The long long is importe here because the sum
typedef long long ll;
const int MAX_N = 1e6 + 10;
int n;
ll a[MAX_N];
ll accumulated[MAX_N];

//Binary search in accumulated array
bool bin_search(int esq, int dir, ll num){
    while(esq <= dir){
        int mid = (esq + dir)/2;
        if(accumulated[mid] == num){
            return true;
        }else if(accumulated[mid] > num){
            dir = mid -1;
        }else if(accumulated[mid] < num){
            esq = mid + 1;
        }
    }
    return false;
}

int main(){
    //Reading
    cin >> n;
    cin >> a[0];
    accumulated[0] = a[0];
    for (int i = 1; i < n; i ++){
        cin >> a[i];
        accumulated[i] = accumulated[i - 1] + a[i];
    }

    //Sum: sum of all elements
    ll sum = accumulated[n - 1];
    if(sum%2 != 0){
        cout << "NO";
        return 0;
    }

    sum = sum/2;
    //Algorithm
    for(int i = 0; i < n; i++){
        if(bin_search(i, n - 1, a[i] + sum) | bin_search(0, i - 1, sum - a[i])){
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";
    return 0;
}

//the answer is NO bu outbut was no
//Explication:
//1. bin_search(i, n - 1, a[i] + sum):
/**
 * To each i-th value of given array, we analize if any value of accumulated that have index more or equal than i
 * is the sum of this i-th value and the value that each array in division must have. If it exists, when changing it, 
 * we will make the accumulated value of the previous number equal to the sum that a division of the array must have.
 */
//2. bin_search(0, i, sum - a[i]):
/**
 * If it exists, when dragging the number to the left, the sum will equal the value we want.
 */
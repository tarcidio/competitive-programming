//LCS: Longest Common Subsequence
//Problem: given two sequences, find the length of the longest subsequence present in both of them

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 1e2 + 10;
string s1, s2;
int memo[MAXN][MAXN];


int lcs(int index_s1, int index_s2){
    if(index_s1 == s1.size() || index_s2 == s2.size())
        return 0;
    else if(memo[index_s1][index_s2] != -1)
        return memo[index_s1][index_s2];
    
    int res = 0;

    if(s1[index_s1] == s2[index_s2]){//If equal, consider that ++ in the size
        res = 1 + lcs(index_s1 + 1, index_s2 + 1);
    }

    res = max(res, lcs(index_s1 + 1, index_s2));//Verify if start one caracter right in the s1 result in a lcs
    res = max(res, lcs(index_s1, index_s2 + 1));//The same, but with s2

    memo[index_s1][index_s2] = res;

    return res;
}

int main(){

    cin >> s1 >> s2;
    memset(memo, -1, sizeof(memo));
    cout << lcs(0, 0);

    return 0;
}
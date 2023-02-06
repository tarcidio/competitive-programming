//LCS: Longest Common Subsequence
//Problem: given two sequences, find the length of the longest subsequence present in both of them

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 1e2 + 10;//more than that is beyond capacity of matrices
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

int iterative(){

    for(int index_s1 = s1.size(); index_s1 >= 0; index_s1--){
        for(int index_s2 = s2.size(); index_s2 >= 0; index_s2--){
            int res = 0;
            if(index_s1 == s1.size() || index_s2 == s2.size())
                memo[index_s1][index_s2] = 0;
            else if( s1[index_s1] == s2[index_s2] )//Remember that index_s1 == 0 is treated in last if
                res = memo[index_s1 + 1][index_s2 + 1] + 1;
            
            res = max(memo[index_s1][index_s2 + 1], res);
            res = max(memo[index_s1 + 1][index_s2], res);
            memo[index_s1][index_s2] = res;
        }
    }

    return memo[0][0];
}

int main(){

    cin >> s1 >> s2;
    cout << iterative();

    return 0;
}

/*This is nice example of the reason that "max": considerate the case of -1 letter in the s1 and not only 
current letter
ABCDGH
AEDFHR
3
*/

/*
AGGTAB
GXTXAYB
4
*/
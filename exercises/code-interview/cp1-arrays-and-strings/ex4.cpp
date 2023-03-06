/*
Given a string, write a function to check if it is a permutation of a palin-
drome. A palindrome is a word or phrase that is the same forwards and backwards. A permutation
is a rearrangement of letters. The palindrome does not need to be limited to just dictionary words.
*/

//Question:
//1. Consider the maiuscule and minuscule? (Case sensitive)
//2. ASCII ou Unicode string?
//3. Whitespace is significant?

#include <bits/stdc++.h>

using namespace std;

const int MAX = 26;

//O(N)
bool isPermutationPalindrome(string str){
    int letter[MAX] = {0};
    for(char c : str){
        if(c != ' ')
            letter[c - 'a']++;
    }

    int odd = 0;
    for(int i : letter){
        if(i%2 != 0){
            if(odd > 0 || str.size()%2 == 0) 
                return false;
            else if(odd == 0)
                odd++;
        }
    }

    return true;
}

int main (){

    string str;
    getline(cin, str);

    if(isPermutationPalindrome(str))
        cout << "True";
    else
        cout << "False";

    return 0;
}
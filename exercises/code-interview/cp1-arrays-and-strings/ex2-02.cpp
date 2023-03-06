//Check Permutation: Given two strings, write a method to decide if one is a permutation of the other

//Question:
//1. Consider the maiuscule and minuscule? (Case sensitive)
//2. ASCII ou Unicode string?
//3. Whitespace is significant?

#include <bits/stdc++.h>

using namespace std;

//I consider that input is string that your caracteres through a-z and the whitespace is significant
//O(n*lg(n))
bool isPermutation(string str1, string str2){
    if(str1.size() != str2.size())
        return false;

    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());
    
    for(int i = 0; i < str1.size(); i++){
        if(str1[i] != str2[i])
            return false;
    }
    
    return true;
}

int main (){
    string str1, str2;
    cin >> str1 >> str2;

    if(isPermutation(str1, str2))
        cout << "The strings are permutation of each other";
    else
        cout << "The strings aren't permutation of each other";

    return 0;
}
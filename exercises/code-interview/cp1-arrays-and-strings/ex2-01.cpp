//Check Permutation: Given two strings, write a method to decide if one is a permutation of the other

//Question:
//1. Consider the maiuscule and minuscule? (Case sensitive)
//2. ASCII ou Unicode string?
//3. Whitespace is significant?

#include <bits/stdc++.h>

using namespace std;

const int TAM = 26;

//I consider that input is string that your caracteres through a-z and the whitespace is significant
//O(n)
bool isPermutation(string str1, string str2){
    if(str1.size() != str2.size())
        return false;
    
    int letter[TAM] = {0};

    for(char c : str1)
        letter[c - 'a']++;
    for(char c : str2)
        letter[c - 'a']--;
    for(int i : letter)
        if(i != 0)
            return false;
    
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
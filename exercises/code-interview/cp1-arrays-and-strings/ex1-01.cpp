//Is Unique: Implement an algorithm to determine if a string has all unique characters.
//What if you cannot use additional data structures?

//Questions:
//1. The string is ASCII string ou Unicode string?
//2. What characters are allowed? All? Can i just use a-z (lower case)? (26)

#include <bits/stdc++.h>

using namespace std;

const int TAM = 26;

//O(1): the maximum length is 26 (constant)
bool isUnique(string str){
    if(str.size() > TAM)
        return false;

    int letter[TAM] = {0};
    for(int i = 0; i < str.size(); i++){
        int index = tolower(str[i]) - 'a';
        if(letter[index] > 0){
            cout << "This string don't have unique caracteres" << endl;
            return false;
        }else
            letter[index]++;
    }

    return true;
}

int main(){
    string str;
    cin >> str;
    
    if(isUnique(str))
        cout << "This string have unique caracteres" << endl;
    else
        cout << "This string don't have unique caracteres" << endl;

    return 0;
}
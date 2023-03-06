/*
There are three types of edits that can be performed on strings: insert a character,
remove a character, or replace a character. Given two strings, write a function to check if they are
one edit (or zero edits) away.
*/

#include <bits/stdc++.h>

using namespace std;

const int MAX = 26;

void count_letter(string s1, string s2, int letter[]){
    for(char c : s1)
        letter[ c - 'a']++;
    for(char c : s2)
        letter[ c - 'a']--;
}

//It's wrong because the answer don't consider the place
bool isEditedAway(string s1, string s2){
    int dif = s1.size() - s2.size();
    dif = abs(dif);

    if(s1 == s2)
        return true;
    else if(dif == 0){
        int letter[MAX] = {0};
        count_letter(s1, s2, letter);
        for(int i : letter)
            if(i != 0)
                false;
    }else if(dif == 1){
        int letter[MAX] = {0};
        count_letter(s1, s2, letter);
        int unique = 0;
        for(int i : letter)
            if(i != 0)
                unique++;
        if(unique != 1)
            return false;
    }else{
        return false;
    }

    return true;
}

int main (){

    string s1, s2;
    cin >> s1 >> s2;

    s1.resize(s1.size() - 1);

    if(isEditedAway(s1,s2))
        cout << "The string was edited";
    else
        cout << "The string wasn't edited";
    return 0;
}

/*
teste, test
*/
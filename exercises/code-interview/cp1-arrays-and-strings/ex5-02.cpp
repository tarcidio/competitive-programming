/*
There are three types of edits that can be performed on strings: insert a character,
remove a character, or replace a character. Given two strings, write a function to check if they are
one edit (or zero edits) away.
*/

//Reṕlace: change only one letter (bale -> pale)
//Insert: insert only one letter in any place (bale -> baled)
//Remomve: remove only one letter in any place (bale -> bal)

#include <bits/stdc++.h>

using namespace std;

//This way is more sintetic: don't duplicate code
bool isEditedAway(string s1, string s2){
    int dif = s1.size() - s2.size();
    if(abs(dif) > 1)
        return false;
    
    //Interesting
    string bigger  = dif >= 0  ? s1 : s2;
    string smaller = dif >= 0  ? s2 : s1;
    
    /*
    string bigger =  s1.size() < s2.size() ? s2 : s1;
    string smaller = s1.size() < s2.size() ? s1 : s2;
    */

    bool foundDifference = false;
    int indexBig = 0, indexSmall = 0;
    while(indexBig < bigger.size() && indexSmall < smaller.size()){
        if(bigger[indexBig] != smaller[indexSmall]){
            if(foundDifference)
                return false;
            else{
                foundDifference = true;
                indexBig++;
            }

            if(dif == 0)
                indexSmall++;
        }else{
            indexBig++;
            indexSmall++;
        }
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
teste, ttees
*/
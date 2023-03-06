/*
    Write a method to replace all spaces in a string with '%20'. You may assume that the string
    has sufficient space at the end to hold the additional characters, and that you are given the "true"
    length of the string. (Note: If implementing in Java, please use a character array so that you can
    perform this operation in place.)
*/

#include <bits/stdc++.h>

using namespace std;

string fillWhitespace(string str, int trueLength){
    int count = 0;
    for(auto c : str)
        if(c == ' ')
            count++;
    
    int index = trueLength + 2*count;
    //C++ stuff
    for(int i = 0; i < 2*count; i++)
        str+= ' ';
        
    for(int i = trueLength - 1; i >= 0; i--){
        if(str[i] == ' '){
            str[index - 1] = '0';
            str[index - 2] = '2';
            str[index - 3] = '%';
            index = index - 3;            
        }else{
            str[index - 1] = str[i];
            index--;
        }
    }

    return str;
}

int main (){

    string str;
    //For reading with whitespace, is necessary getline
    getline(cin, str);

    cout << fillWhitespace(str, str.size());

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e3 + 1;
//on

//s = p + t, where p is the pattern and t the text
//s_i = s[i] + s[i+1] + ... + s[s.size] (ex: s = s_0)
//z[i]: commum prefix length between s and s_i
//z[i]: by coincidence, this value is the same as the character index that current index
    //must test to know if belong a matching or not
int z[MAX];

void z_function(string s){
    z[0] = 0;
    //[l,r): last range of matching
    int l = 0, r = 0;

    //We'll go through the s
    for(int i = 1; i < s.size(); ++i){
        if(i > r)//If the current index is more than end of range, so we don't know if we are part of a matching
            l = r = i;//Inicialize range
        /*
        1) i - l: corresponding position of i in the pattern (localizated at the begin)
        2) z[i - l]: commum prefix length between the pattern and the substring of pattern. 
            This value will only be efect when we are in a matching. So, that means that 
            i-th letter of matching must have at less the value of z[] of the respective
            letter of pattern (z[i] = z[i - l])
        2) r - i: it will always be zero if we aren't in matching. Consequently, z[i] = 0
            Also it restrict that z[i - l] be more than range of matching that we are 
            (ex: situations in end of string)
        */
        z[i] = min(z[i - l], r - i);

        while(s[i + z[i]] == s[z[i]] && i + z[i] < s.size()){//Verify if we enter in a matching
            z[i]++;
            l = i;
            r = i + z[i];
        }
    }
}

int main (){
    string input = "abcdabcdabaaabcda";

    z_function(input);
    cout << "Z vector: ";
    for(int i = 0; i < input.size(); i++)
        cout << z[i] << " ";

    return 0;
}

//abaabacababa

//Example that "r - i" is important
//abcdabcdabaaabcda
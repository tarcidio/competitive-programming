#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e3 + 1;

//s = p + t, where p is the pattern and t the text
//s_i = s[i] + s[i - 1] + ... + s[0] (ex: s = s_{s.size()})
//kmp[i]: commum sufix length between s and s_i
int kmp[MAX];

//O(N)
void kmp_function(string s){
    kmp[0] = 0;
    for(int i = 1; i < s.size(); ++i){
        int j = kmp[i - 1];
        //The jumps
        while(j != 0 && s[i] != s[j])
            j = kmp[j - 1];
        kmp[i] = s[i] == s[j] ? j + 1 : 0;
    }
}

int main (){
    string input = "abacababa";

    kmp_function(input);
    cout << "KMP vector: ";
    for(int i = 0; i < input.size(); i++)
        cout << kmp[i] << " ";

    return 0;
}

//abacababa
//abaabacababa
//abcdabcdabaaabcda

//Explaning the algorithm through a history
/*
Let's use the follow string: A B A C A B A B A

B_1 to A_0: Give me your kmp?
A_0 to B_1: Of course! My kmp is 0.
B1 to A_0: Ah! Kmp 0 indicates that you aren't matching. I will see the start of string
    and verify if I am compatible with the first letter. If yes, I will start a new matching.

B1 to 0 position: Hello! You again? I would like to know if you are like me.
0 position (A_0) to B1: I'm not like you ;(
B1 to 0 position: Oh no! So, I'm part of matching at all. I'll put 0 in my kmp for that the next index
    know that it isn't sequence of a matching. It'll be at most the beginning of a matching (in this case
    it'll be like a first caracter of string)

A_2 to B_1: Give me your kmp?
B_1 to A_2: Of course! My kmp is 0.
A_2 to B_1: Ah! Kmp 0 indicates that you aren't matching. I will see the start of string
    and verify if I am compatible with the first letter. If yes, I will start a new matching.

A_2 to 0 position: Hello! I would like to know if you are like me.
0 position to A_2: Hi! I like you.
A_2 to 0 position: Great! So, I am compatible with the first caracterer of matching. I'll put 1 my kmp,
    because this value is the length of string that I match (just only one letter) and when the next index come
    , it'll be directed  to next caracterer of matcing that I participate. If it is like, it'll stores 2 in your kmp.

...

B_7 to A_6: Give me your kmp?
A_6 to B_7: Of course! My kmp is 15.
B_7 to A_6: Oh! So you are part of a matching. I could be part of the matching that you are.
    I'll verify if I like the next caracterer of matching that you are. The index of him is your kmp.
    Thank you!

B_7 to position 15: I am like you?
Position 15 to B_7: You aren't ;(
B_7 to position 15: Oh no! So I'm not part of matching that's going on.
Position 15 to B_7: That's right. But, how you were directed here, it means that my predecessor is the same as yours.
    If the my predecessor isn't is not beginning of a matching (kmp != 0), that is, if it is part of matching,
    then there will be another antecessor like ours. In this case, you coud be the caracterer that complete the
    matching of this antecessor.
B_7 to position 15: But what guarantees that the matching that this new predecessor follow is the same as mine?

>PICTURE<
*/
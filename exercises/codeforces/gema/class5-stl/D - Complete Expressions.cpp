//NAME: Complete Expressions
//O(N)
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 * 2;
stack<char> st;
bool sol = true;

bool test(char open, char close){
    if(st.empty() || st.top () != open){
        sol = false;
        return false;
    }else{
        st.pop();
        return true;
    }
}

int main(){
    int n;
    string input;
    cin >> n >> input;

    for(char it : input){
        if(it == ')')
            if(!test('(' ,')')) break;
        else if(it == ']')
            if(!test('[', ']')) break;
        else if(it == '}')
            if(!test('{', '}')) break;
        else
            st.push(it);
        cout << it << " + " << sol << " + ";
        if(st.empty()) cout << "oi";
    }

    st.empty() && sol ? cout << "COMPLETINHA" : cout << "DEU RUIM";

    return 0;
}

/*int main(){
    int n;
    string input;
    cin >> n >> input;

    int b_panthesis = 0;//open - close
    int b_bracktes = 0;//open - close
    int b_keys = 0;//open - close
    bool sol = true;

    if(n%2 == 0){
        for(char it : input){
            if(it == '(')
                b_panthesis++;
            else if(it == ')')
                b_panthesis--;
            else if(it == '[')
                b_bracktes++;
            else if(it == ']')
                b_bracktes--;
            else if(it == '{')
                b_keys++;
            else if(it == '}')
                b_keys--;
            
            if(b_panthesis < 0 || b_bracktes < 0 || 
            b_keys < 0){
                sol = false;
                break;
            }
        }
    }else
        sol = false;

    b_panthesis == b_bracktes == b_keys == 0 && sol ? cout << "COMPLETINHA" : cout << "DEU RUIM";

    return 0;
}
*/
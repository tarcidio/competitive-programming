//NAME: Yuhao and a Parenthesis
//

#include <bits/stdc++.h>

using namespace std;

stack<char> st;
string input;

//returns numbers of combo possibles
//how pass iterator with parameter
template<typename Iterator>
int algorithm(Iterator it){ 
    int cont = 0;
    cout << *it << endl;
    while(it != input.end()){
        if(*it == '('){
            cout << "oi1" << endl;
            st.push('(');
        }else{
            if(st.top() == '('){
                cout << "Oi2" << endl;
                st.pop();
                cont++;
            }else{
                return cont;
            }
        }
        it++;
    }
    return cont;
}

int main (){
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        string tmp;
        cin >> tmp;
        input += tmp;
    }

    int ans = 0;
    for(auto it = input.begin(); it != input.end(); it++){
        if('('){
            if(algorithm(it) == 1)
                ans++;
        }
    }

    cout << ans << endl;

    return 0;
}
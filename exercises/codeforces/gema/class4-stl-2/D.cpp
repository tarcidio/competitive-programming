//NAME: Yuhao and a Parenthesis
//O(N)

//OBS: In this exercise, consider that the first of the sequence of pairs can come after the second in the entry
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5e5 + 7;
string input[MAXN];//input[i] contain the input i of sequence parenthesis
int num_left[MAXN];//num_left[i] is number of '(' open and not close of input i
int num_right[MAXN];//num_rigth[i] is number of ')' without '(' respective of input i
int unb_left[MAXN];
//unb_left[j] is how many times unbalanced in j left parenthesis
//unb_left[j] = how many time appeared j = num_left[i] of the input i
int unb_right[MAXN];
//unb_right[j] is how many times unbalanced in j right parenthesis
//unb_right[j] = how many time appeared j = num_right[i] of the input i

int main(){
    //Reading n
	int n;
	cin >> n;

    //Reading and calculate unbalaced for each sequences
	for(int i = 0; i < n; i++){
		cin >> input[i];
		stack<char> st;//stack that control the combination of '(' and ')'
		for(int j = 0; j < input[i].size(); j++){//]Traverse through the input
				if(input[i][j] == '('){
					st.push('(');
					num_left[i]++;
				}else{//input[i][j] == ')'
					if(!st.empty()){//If stack not empty, so combine
						st.pop();
						num_left[i]--;
					}else//Stack empty
						num_right[i]++;
				}
		} 
	}

	int cnt = 0;//Counter used to bring the useful information to top (cannot use one structure?)
	int ans = 0;//Amount of valid sequences
	for(int i = 0; i < n; i++)
		if(num_left[i] && !num_right[i])
            //num_left >= 1 and num_right == 0 (balance > 0)
            unb_left[num_left[i]]++;
        else if (!num_left[i] && num_right[i])
            //num_left == 0 and num_right >= 1 (balance < 0)
            unb_right[num_right[i]]++;
		else if(!num_left[i] && !num_right[i])
            //num_left == 0 and num_right == 0 (balance == 0)
			ans++;

	ans /= 2;
    //to get into the answer, its necessary combine
    //one sequences correct isn't part of the answer, but two yes
    //one sequence correct combined with sequence incorrect isn't part of the answer 

    //If one input is unbalanced in two to left, it can be combined with other input unbalanced in two to right. Proportion is 1:1, so we get the minimum
	for(int i = 0; i < MAXN; i++)
		ans += min(unb_left[i], unb_right[i]);

	cout << ans << endl;			
	return 0; 
}
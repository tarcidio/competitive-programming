//NAME: Registration System
//

#include <bits/stdc++.h>

using namespace std;

set<string> names;

int searchNewNumber(string input_name){
    int num = 1;
    string temp = input_name + to_string(num);//Are there any contraindications?
    while(names.find(temp) != names.end()){
        num++;
        temp = input_name + to_string(num);
    }
    return num;
}

int main (){
    int n;
    string input_name;

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> input_name;
        if(names.find(input_name) == names.end()){
            names.insert(input_name);
            cout << "OK" << endl;
        } else {
            int newNumber = searchNewNumber(input_name);
            input_name.append(to_string(newNumber));
            names.insert(input_name);
            cout << input_name << endl;
        }
    }

    return 0;
}
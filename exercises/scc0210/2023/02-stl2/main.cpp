#include <bits/stdc++.h>

using namespace std;

priority_queue<double> minValues;
priority_queue<double, vector<double>, greater<double>> maxValues; 

double median() {
    if (minValues.size() > maxValues.size()) {
        return minValues.top();
    } else if (minValues.size() < maxValues.size()) {
        return maxValues.top();
    } else {
        return (minValues.top() + maxValues.top()) / 2.0;
    }
}

void add_value(double valor) {
    if (minValues.empty() || valor <= minValues.top()) {
        minValues.push(valor);
    } else {
        maxValues.push(valor);
    }

    if (minValues.size() > maxValues.size() + 1) {
        maxValues.push(minValues.top());
        minValues.pop();
    } else if (maxValues.size() > minValues.size() + 1) {
        minValues.push(maxValues.top());
        maxValues.pop();
    }
}

int main() {

    while(true){
        string input;
        cin >> input;
        if(input == "")
            break;
        add_value(stoi(input));
        cout << int(median()) << endl;
    }

    return 0;
}
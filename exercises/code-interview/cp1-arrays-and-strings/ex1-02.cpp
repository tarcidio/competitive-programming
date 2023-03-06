//Is Unique: Implement an algorithm to determine if a string has all unique characters.
//What if you cannot use additional data structures?
//R: Use a good sorting algorithm and compare the caracterer with the next.
//O(nlogn)

#include <bits/stdc++.h>

using namespace std;

void build(string *str, int tam, int index){
    int largest = index;
    int left = 2*index;
    int right = 2*index + 1;

    if(left < tam && (*str)[left] > (*str)[largest])
        largest = left;
    
    if(right < tam && (*str)[right] > (*str)[largest])
        largest = right;
    
    if(index != largest){
        swap((*str)[index], (*str)[largest]);
        build(str, tam, largest);
    }
}

void heapSort(string *str){

    for(int i = str->size()/2 - 1; i >= 0; i--)
        build(str, str->size(), i);
    
    for(int i = str->size() -1; i >= 0; i--){
        swap((*str)[0], (*str)[i]);
        build(str, i, 0);
    }
}


int main(){
    string str;
    cin >> str;
    
    heapSort(&str);

    bool ans = true;
    for(int i = 0; i < str.size() - 1; i ++){
        if(str[i] == str[i+1]){
            ans = false;
            break;
        }
    }

    if(ans)
        cout << "This string have unique caracteres" << endl;
    else
        cout << "This string don't have unique caracteres" << endl;

    return 0;
}
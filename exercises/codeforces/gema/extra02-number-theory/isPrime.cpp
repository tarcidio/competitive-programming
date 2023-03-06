#include <bits/stdc++.h>

using namespace std;

//Standard algorithm
bool isPrime(int num){
    if(num == 0 || num == 1)
        return false;
    for(int i = 2; i * i <= num; i++){
        if(num%i == 0)
            return false;
    }
    return true;
}

//Eratosthenes' sieve
const int MAX = 1e3 + 1;
bool sieve[MAX];

void eratosthenes(int num){
    sieve[0] = false;
    sieve[1] = false;
    for(int i = 2; i <= num; i++)
        sieve[i] = true;
    
    for(int i = 2; i <= num; i ++){
        if(sieve[i]){
            for(int j = i*i; j <= num; j+= i)
                sieve[j] = false;
        }
    }
}

int main (){
    int input;
    cin >> input;

    cout << "Standard algorithm" << endl;
    if(isPrime(input))
        cout << "This number is prime.\n" << endl;
    else
        cout << "This number isn't prime.\n" << endl;

    eratosthenes(input);
    cout << "Eratosthenes sieve" << endl;
    if(sieve[input])
        cout << "This number is prime.\n" << endl;
    else
        cout << "This number isn't prime.\n" << endl;

    return 0;
}
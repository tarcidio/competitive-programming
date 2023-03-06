#include <bits/stdc++.h>

using namespace std;


//a: first number or the rest of division between old a and b
//b: second number 

//O( log( min(a,b) ) )
int gcd(int a, int b){
    if(b == 0)
        return a;
    return gcd(b, a%b);
}

//O( log( min(a,b) ) )
int lcm(int a, int b){
    //This way we avoid overflow
    return a* (b/gcd(a,b));
    //return a*b/gcd(a,b);
}

int main (){

    return 0;
}
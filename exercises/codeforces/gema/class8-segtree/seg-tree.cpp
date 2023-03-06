//Problem: Given a array with N elements a[i], process Q operations of the type:
//1 i v => a[i] = v
//2 i r => print sum(i=0 to r)a[i]

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;
int a[MAXN];
int seg[4*MAXN];

//"Constructor"
//Default: build(1, 1, num_elem);
void build(int node, int i, int j){
    if(i == j)//If we arrived in graph sheet
        seg[node] = a[i];
    else{
        int m = (i + j)/2;
        build(2*node, i, m);
        build(2*node + 1, m + 1, j);
        seg[node] = seg[2*node] + seg[2*node + 1];
    }  
}

//Query the sum
//Default: query(1, 1, num_elem, ..., ...);
//node: current node
//[i,j]: range that current node represent
//[l,r]: range that query wants
int query(int node, int i, int j, int l, int r){
    if(i >= l && j <= r)//If the range is in
        return seg[node];
    else if(j < l || i > r)//If the range is out
        return 0;

    int m = (i + j)/2;
    int L = query(2*node, i, m, l, r);
    int R = query(2*node + 1, m + 1, j, l, r);

    return L + R;
}

//Update the  graph sheet
//Default: update(1, 1, num_elem, ..., ...)
//node: current node
//[i,j]: range that current node represent
//a[id] = x
void update(int node, int i, int j, int id, int x){
    if(i == j)//If the range is 1, than we arrived in the graph sheet
        seg[node] = x;
    else{//Else, call left and right
        int m = (i + j)/2;
        if(id <= m)//
            update(2*node, i, m, id, x);
        else
            update(2*node + 1, m + 1, j, id, x);
        seg[node] = seg[2*node] + seg[2*node + 1];
    }
}

int main (){
    int num_elem, num_op;
    cin >> num_elem >> num_op;
    for(int i = 1; i <= num_elem; i++){//The node begin in 1
        cin >> a[i];
    }

    build(1, 1, num_elem);

    for(int i = 0; i < num_op; i++){
        int op, num1, num2;
        cin >> op >> num1 >> num2;
        if(op == 1)
            update(1, 1, num_elem, num1, num2);
        else if(op == 2)
            cout << "\n" << query(1, 1, num_elem, num1, num2);
    }

    return 0;
}

/*
4 5
1 2 3 4
2 1 4
1 1 2
2 1 4
1 2 10
2 2 3
*/
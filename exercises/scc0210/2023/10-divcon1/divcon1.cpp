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
        seg[node] = min(seg[2*node],seg[2*node + 1]);
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
        return 0x3f3f3f3f;

    int m = (i + j)/2;
    int L = query(2*node, i, m, l, r);
    int R = query(2*node + 1, m + 1, j, l, r);

    return min(R,L);
}

int main (){
    int num_elem;
    while(cin >> num_elem){
      memset(a, 0x3f3f3f3f, sizeof(a));
      for(int i = 1; i <= num_elem; i++){//The node begin in 1
          cin >> a[i];
      }
      
      build(1, 1, num_elem);
    
      int num_op;
      cin >> num_op;
  
      for(int i = 0; i < num_op; i++){
          int l_input, r_input;
          cin >> l_input >> r_input;
          l_input++;
          r_input++;
          cout << query(1, 1, num_elem, l_input, r_input) << endl;
      }
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
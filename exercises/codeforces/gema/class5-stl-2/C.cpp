//NAME: T-shirt buying
//

#include <bits/stdc++.h>

using namespace std;

//p: price
//a_i: front color of the i
//b_i: back color of the i
//m: how many buyers
//j: buyer number j
//c_j: favorite color

struct t_shirt{
    int p;//price
    int a;//front color
    int b;//back color
};

const int MAX_N_M = 200001;

vector<t_shirt> inventory (MAX_N_M);
int buyers [MAX_N_M];

int main (){
    int n;//numbers of shirts
    int m;//number os buyers

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> inventory[i].p;
    for(int i = 0; i < n; i++)
        cin >> inventory[i].a;
    for(int i = 0; i < n; i++)
        cin >> inventory[i].b;
    cin >> m;
    for(int j = 0; j < m; j++)
        cin >> buyers[j];

    //https://www.cnblogs.com/EDGsheryl/p/6865151.html
    //https://blog.csdn.net/tigerisland45/article/details/116355669
    //https://blog.karatos.in/a?ID=00700-bef04cb4-2185-4711-a6e4-7b64a39f9efa
    
    /*
    This is VERY ineficient

    for(int j = 0; j < m; j++){
        vector<int> possible (MAX_N_M);
        int cont = 0;
        for(int i = 0; i < n; i++)
            if(inventory[i].a == buyers[j] || inventory[i].b == buyers[j]){
                possible[cont] = inventory[i].p;
                cont++;
            }
        if(cont == 0)
            cout << "-1 ";
        else{
            sort(possible.begin(), possible.end());
            cout << possible[0] << endl;
            for(auto it = inventory.begin(); it != inventory.end(); it++)
                if(it->p == possible[0])
                    inventory.erase(it);
        }
    }*/
   
    return 0;
}
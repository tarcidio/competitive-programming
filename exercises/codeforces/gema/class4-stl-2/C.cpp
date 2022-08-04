//NAME: T-shirt buying
//O(logn) ou O(n)

#include <bits/stdc++.h>

using namespace std;

//p: price
//a_i: front color of the i
//b_i: back color of the i
//m: how many buyers
//j: buyer number j
//c_j: favorite color

const int MAXN = 2e6 + 1;
int a[MAXN];//front color
int b[MAXN];//back color
int p[MAXN];//price
int c[MAXN];//favorite color
set<int> price_color[4];
//price_color[0]: isn't used
//price_color[1]: price of the t-shirts of color type 1
//price_color[2]: price of the t-shirts of color type 2
//price_color[3]: price of the t-shirts of color type 3

int main (){
    int n;//numbers of shirts
    int m;//number os buyers

    //read the tshirts
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> p[i];
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++)
        cin >> b[i];

    //fill the set
    for(int i = 0; i < n; i++){
        price_color[a[i]].insert(p[i]);
        price_color[b[i]].insert(p[i]);
        //ex: if i = 0 take a[0]= 1 and p[0] = 500, then 
        //price_color[1] = {500} 
        //price_color[2] = {} 
        //price_color[3] = {} 
    }

    //read the buyers
    cin >> m;
    for(int j = 0; j < m; j++)
        cin >> c[j];
    
    //algorithm
    for(int j = 0; j < m; j++){
        if(price_color[c[j]].empty()){
            cout << "-1 ";
        }else{
            int price_of_the_color = *(price_color[c[j]].begin());//take the smallest element of the set
            cout << price_of_the_color << " ";
            for(int i = 1; i <= 3; i++)
                price_color[i].erase(price_of_the_color);//this only is possible because p_i's are distinct
        }
    }
    
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
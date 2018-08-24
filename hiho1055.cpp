//树上背包
#include <bits/stdc++.h>
using namespace std;
const int maxn = 102;
vector<int> e[maxn];
int w[maxn];
int n, m;

int main(){
    while(cin>>n>>m){
        for(int i = 1; i <= n; i++){
            cin>>w[i];
            e[i].clear();
        }
        int u, v;
        for(int i = 1; i < n; i++){
            cin>>u>>v;
            e[u].push_back(v);
            e[v].push_back(u);
        }

    }
}
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;
vector<int> e[maxn];
int vb[maxn], vg[maxn];
int mcb[maxn];

bool dfs(int u){
    vg[u] = 1;
    for(int i = 0; i < e[u].size(); i++){
        int v = e[u][i];
        if(vb[v]) continue;
        vb[v] = 1;
        if(mcb[v] == -1 || dfs(mcb[v])){
            mcb[v] = u;
            return 1;
        }
    }
    return 0;
}

int color[maxn];
int bi(int u){
    for(int i = 0; i < e[u].size(); i++){
        int v = e[u][i];
        if(color[u] == color[v]) return 0;
        if(!color[v]){
            color[v] = 3 - color[u];
            if(!bi(v)) return 0;
        }
    }
    return 1;
}

int main(){
    int n, m;
    while(cin>>n>>m){
        int u, v;
        for(int i = 0; i < m; i++){
            cin>>u>>v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        for(int i = 1; i <= n; i++) if(!color[i]){
            color[i] = 1;
            bi(i);
        }
        memset(mcb, -1, sizeof mcb);
        int res = 0;
        for(int i = 1; i <= n; i++) if(color[i] == 1){
            memset(vb, 0, sizeof vb);
            memset(vg, 0, sizeof vg);
            if(dfs(i)) res++;
        }
        cout<<res<<endl;
    }
}
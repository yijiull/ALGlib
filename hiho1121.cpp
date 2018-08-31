#include <bits/stdc++.h>
using namespace std;
const int maxn = 10010;

vector<int> e[maxn];
int color[maxn];
bool dfs(int u, int c){
    color[u] = c;
    for(int i = 0; i < e[u].size(); i++){
        int v = e[u][i];
        if(color[v] == color[u]) return 0;
        if(!color[v] && !dfs(v, 3 - c)){
            return 0;
        }
    }
    return 1;
}
bool bi(int u){
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
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        //init
        for(int i = 0; i < n; i++) e[i].clear();
        memset(color, 0, sizeof color);

        int u, v;
        for(int i = 0; i < m; i++){
            cin>>u>>v;
            u--; v--;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        bool ok = 1;
        for(int i = 0; i < n; i++) if(!color[i]){
            ok = dfs(i, 1);
            if(!ok) break;
        }
        for(int i = 0; i < n; i++) if(ok && !color[i]) ok = 0;
        if(ok){
            cout<<"Correct"<<endl;
        }else{
            cout<<"Wrong"<<endl;
        }
    }
    return 0;
}
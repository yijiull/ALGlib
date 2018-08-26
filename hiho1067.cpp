#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, m;
string names[maxn];
unordered_map<string, int> mp;
vector<int> e[maxn];
vector<int> q[maxn];
vector<int> id[maxn];
int ans[maxn], d[maxn], vis[maxn];
int f[maxn];
int gf(int x){
    return x == f[x] ? x : f[x] = gf(f[x]);
}
void dfs(int u){
    for(int i = 0; i < e[u].size(); i++){
        dfs(e[u][i]);
        f[e[u][i]] = u;
    }
    vis[u] = 1;
    for(int i = 0; i < q[u].size(); i++){
        if(vis[q[u][i]]){
            ans[id[u][i]] = gf(q[u][i]);
        }
    }
}

int main(){
    while(cin>>n){
        mp.clear();
        int cnt = 0;
        memset(d, 0, sizeof d);
        memset(vis, 0, sizeof vis);
        string a, b;
        for(int i = 0; i < n; i++){
            cin>>a>>b;
            if(!mp.count(a)) names[cnt] = a, mp[a] = cnt++;
            if(!mp.count(b)) names[cnt] = b, mp[b] = cnt++;
            d[mp[b]]++;
            e[mp[a]].push_back(mp[b]);
        }
        for(int i = 0; i < cnt; i++) f[i] = i;
        cin>>m;
        for(int i = 0; i < m; i++){
            cin>>a>>b;
            q[mp[a]].push_back(mp[b]);
            q[mp[b]].push_back(mp[a]);
            id[mp[a]].push_back(i);            
            id[mp[b]].push_back(i);            
        }
        for(int i = 0; i < cnt; i++){
            if(d[i] == 0) {
                dfs(i);
                break;
            }
        }
        for(int i = 0; i < m; i++){
            cout<<names[ans[i]]<<endl;
        }
    }
}
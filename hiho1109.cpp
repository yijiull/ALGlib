#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
const int maxe = 1e6 + 10;
const int inf = 1e9;

vector<int> g[maxn];
struct Edge{
    int u, v, w;
    bool operator< (const Edge &a)const{
        return w > a.w;
    }
};
vector<Edge> e;

void add(int u, int v, int w){
    e.push_back({u, v, w});
    e.push_back({v, u, w});
    int m = e.size();
    g[u].push_back(m - 2);
    g[v].push_back(m - 1);
}
int  d[maxn], vis[maxn];
int prime(int n){
    int res = 0;
    for(int i = 0; i <= n; i++) d[i] = inf;
    memset(vis, 0, sizeof vis);
    priority_queue<pair<int, int>> p; //这里可以换成自己写的堆 "heap.h"
    d[0] = 0;
    p.push({0, 0});
    int cnt = 0;
    while(!p.empty()){
        auto cur = p.top();
        p.pop();
        cur.first = -cur.first;
        int u = cur.second;
        if(d[u] < cur.first){
            continue;
        }
        res += cur.first;
        cnt++;
        vis[u] = 1;
        if(cnt == n) break;
        for(int i = 0; i < g[u].size(); i++){
            auto temp = e[g[u][i]];
            int v = temp.v;
            if(!vis[v] && temp.w < d[v]){
                d[v] = temp.w;
                p.push({-temp.w, v});
            }
        }
    }
    return res;
}
int main(){
    int n, m;
    while(cin>>n>>m){
        int u, v, w;
        for(int i = 0; i < m;i++){
            cin>>u>>v>>w;
            u--, v--;
            add(u, v, w);
        }
        cout<<prime(n)<<endl;
    }
    return 0;
}
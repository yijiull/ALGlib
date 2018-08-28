#include "dijkstra.h"

Dij::Dij(){
    init();
}
void Dij::init(){
    for(int i = 0; i < maxn; i++) d[i] = 1e9;
}

void Dij::addEdge(int u, int v, int w){
    e.push_back({u, v, w});
    e.push_back({v, u, w});
    int m = e.size();
    g[u].push_back(m - 2);
    g[v].push_back(m - 1);
}

int Dij::dijkstra(int s, int t){
    d[s] = 0;
    std::priority_queue<std::pair<int, int>> pq;
    pq.push({0, s});
    while(!pq.empty()){
        auto cur = pq.top();
        pq.pop();
        int u = cur.second;
        if(d[u] < cur.first) continue;
        for(int i = 0; i < g[u].size(); i++){
            auto temp = e[g[u][i]];
            int v = temp.v;
            if(d[u] + temp.w < d[v]){
                d[v] = d[u] + temp.w;
                p[v] = g[u][i];
                pq.push({d[v], v});
            }
        }
    }
    return d[t];
}

#include <iostream>
using namespace std;
Dij dij;
int main(){
    int n, m, s, t;
    while(cin>>n>>m>>s>>t){
        int u, v, w;
        for(int i = 0; i < m; i++){
            cin>>u>>v>>w;
            dij.addEdge(u, v, w);
        }
        cout<<dij.dijkstra(s, t)<<endl;
    }
}
#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+10;
int n, m;
string s1, s2;
map<string, int> mp;
string names[maxn];
int cnt;
vector<int> e[maxn];

int node[maxn << 1], dep[maxn << 1], first[maxn];
int id;
void dfs(int u, int d){
    node[id] = u;
    dep[id] = d;
    first[u] = id++;
    for(int i = 0; i < e[u].size(); i++){
        dfs(e[u][i], d + 1);
        node[id] = u;
        dep[id++] = d;
    }
}

int dpmin[maxn << 1][25];
void rmqInit(){
    for(int i = 0; i < id; i++) dpmin[i][0] = i;
    int k = log2(id);
    for(int j = 1; j <= k; j++){
        for(int i = 0; i + (1 << j) - 1 < id; i++){
            int a = dpmin[i][j - 1];
            int b = dpmin[i + (1 << j - 1)][j - 1];
            dpmin[i][j] = dep[a] < dep[b] ? a : b;
        }
    }
}
int rmq(int a, int b){
    a = first[a];
    b = first[b];
    int aa = min(a, b), bb = max(a, b);
    int k = log2(bb - aa + 1);
    a = dpmin[aa][k];
    b = dpmin[bb - (1 << k) + 1][k];
    return dep[a] < dep[b] ? node[a] : node[b];
}

int main(){
    while(cin>>n){
        //std::ios::sync_with_stdio(false);
        //std::cin.tie(0);

        //init
        id = 0;
        cnt = 0;
        mp.clear();
        for(int i = 0; i < maxn; i++) e[i].clear();

        for(int i = 0; i < n; i++){
            cin>>s1>>s2;
            if(!mp.count(s1)){
                names[cnt] = s1;
                mp[s1] = cnt++;
            }
            if(!mp.count(s2)){
                names[cnt] = s2;
                mp[s2] = cnt++;
            }
            e[mp[s1]].push_back(mp[s2]);
        }
        dfs(0, 0);
        rmqInit();
        cin>>m;
        while(m--){
            cin>>s1>>s2;
            int i = rmq(mp[s1], mp[s2]);
            cout<<names[i]<<endl;
        }
    }
    return 0;
}
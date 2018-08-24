//树的直径
#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;

vector<int> e[maxn];

//递归法
int d1[maxn], d2[maxn];
int ans;
void solve(int u, int f){
    for(int i = 0; i < e[u].size(); i++){
        int v = e[u][i];
        if(v != f){
            solve(v, u);
            int temp = d1[v] + 1;
            if(temp > d1[u]){
                d2[u] = d1[u];
                d1[u] = temp;
            }else if(temp > d2[u]){
                d2[u] = temp;
            }

        }
    }
    if(ans < d1[u] + d2[u]) ans = d1[u] + d2[u];
}

//两遍dfs
int id; //标记最远点
int dfs(int u, int f, int w){
    if(e[u].size() == 1){
        //leaf
        if(ans < w){
            ans = w;
            id = u;
        }
    }
    for(int i = 0; i < e[u].size(); i++){
        if(e[u][i] != f) dfs(e[u][i], u, w + 1);
    }
    return id;
}


int main(){
    int n;
    while(cin>>n){
        int u, v;
        ans = 0;
        for(int i = 1; i < n; i++){
            cin>>u>>v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        //memset(d1, 0, sizeof d1);
        //memset(d2, 0, sizeof d2);
        //solve(1, 0);
        int op = dfs(1, 0, 0);
        dfs(op, 0, 0);
        cout<<ans<<endl;
    }
}

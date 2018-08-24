//树上背包
#include <bits/stdc++.h>
using namespace std;
const int maxn = 102;
vector<int> e[maxn];
int w[maxn];
int dp[maxn][maxn];
int n, m;
void solve(int u, int f, int c){
    dp[u][0] = 0;
    dp[u][1] = w[u];
    for(int i = 0; i < e[u].size(); i++){
        int v = e[u][i];
        if(v == f) continue;
        solve(v, u, c - 1);
        for(int j = c; j >= 2; j--){
            for(int k = 1; k < j; k++){
                dp[u][j] = max(dp[u][j], dp[v][k] + dp[u][j - k]);
            }
        }
    }
}
int main(){
    while(cin>>n>>m){
        for(int i = 1; i <= n; i++){
            cin>>w[i];
            e[i].clear();
        }
        memset(dp, 0, sizeof dp);
        int u, v;
        for(int i = 1; i < n; i++){
            cin>>u>>v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        solve(1, 0, m);
        cout<<dp[1][m]<<endl;
    }
}
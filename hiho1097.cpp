#include <bits/stdc++.h>
using namespace std;
const int maxn = 1001;
const int inf = 1e9;
int d[maxn][maxn];
int pd[maxn], vis[maxn];
int prime(int n){
    memset(vis, 0, sizeof vis);
    int res = 0;
    for(int i = 0; i < n; i++){
        pd[i] = d[0][i];
    }
    vis[0] = 1;
    for(int i = 1; i < n; i++){
        int sel, m = inf;
        for(int j = 0; j < n; j++) if(!vis[j]) {
            if(pd[j] < m){
                m = pd[j];
                sel = j;
            }
        }
        if(m == inf) break;
        vis[sel] = 1;
        res += m;
        for(int j = 0; j < n; j++) {
            if(!vis[j] && pd[j] > d[sel][j]) pd[j] = d[sel][j];
        }
    }
    return res;
}
int main(){
    int n;
    while(cin>>n){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin>>d[i][j];
            }
        }
        cout<<prime(n)<<endl;
    }
}
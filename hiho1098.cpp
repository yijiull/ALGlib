#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
const int maxe = 1e6 + 10;
int f[maxn];
int gf(int x){
    return x == f[x] ? x : f[x] = gf(f[x]);
}
struct Edge{
    int u, v, w;
    bool operator< (const Edge &a){
        return w < a.w;
    }
}e[maxe];
int main(){
    int n, m;
    while(cin>>n>>m){
        for(int i = 0; i < m; i++){
            cin>>e[i].u>>e[i].v>>e[i].w;
        }
        sort(e, e + m);
        for(int i = 0; i <= n; i++){
            f[i] = i;
        }
        int res = 0;
        for(int i = 0; i < m; i++){
            int a = gf(e[i].u), b = gf(e[i].v);
            if(a != b){
                f[a] = b;
                res += e[i].w;
            }
        }
        cout<<res<<endl;
    }
}
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1030;
const int mod = 1e9 + 7;
int n, m;
int c[maxn][6][maxn];
int dp(int x, int y, int s){
    if(c[x][y][s]) return c[x][y][s];
    if(x == n ){
        return 1;
    }
    int res = 0;
    if(s & (1 << y)){
        if(y < m - 1) res = dp(x, y + 1, s);
        else if(y == m - 1) res = dp(x + 1, 0, s >> m);
    }else{
        if((y == m - 1 || (s & (1 << (y+1)))) && (x == n - 1 || (s & (1 << (y + m))))) res = 0;
        else{
            if(y < m - 1 && !(s & (1 << (y+1)))) res = dp(x, y, s | (3 << y));
            if(x < n - 1 && !(s & (1 << (y+m)))) res = res + dp(x, y, s | (1 << y) | (1 << (y + m)));
        }
    }
    c[x][y][s] = res;
    return res % mod;
}

int p[2][1 << 10];

int main(){
    while(cin>>n>>m){
        memset(c, 0, sizeof c);
        if( n * m & 1) cout<<0<<endl;
        else cout<<dp(0, 0, 0)<<endl;
    }
}
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1024 + 10;

int dp[maxn][maxn];

int bits(int x){
    int cnt = 0;
    while(x){
        if(x & 1) cnt++;
        x >>= 1;
    }
    return cnt;
}
int main(){
    int n, m, q;
    int w;
    while(cin>>n>>m>>q){
        memset(dp, 0, sizeof dp);
        int stat = 1 << m;
        for(int i = 1; i <= n; i++){
            cin>>w;
            for(int s = 0; s < stat; s++){
                //int temp = (s >> 1) | (1 << (m - 1));
                //if(bits(temp) <= q){
                //    dp[i][temp] = max(dp[i - 1][s] + w, dp[i][temp]);
                //}
                //dp[i][s >> 1] = max(dp[i-1][s], dp[i][s >> 1]);
                if(bits(s) <= q){
                    dp[i][s] = max(dp[i-1][s >> 1], dp[i-1][(s >> 1) | (1 <<(m - 1))]) + ((s >> (m - 1)) & 1) * w;
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < stat; i++){
            //cout<<dp[n][i]<<" ";
            ans = max(ans, dp[n][i]);
        }
        cout<<ans<<endl;
    }
}
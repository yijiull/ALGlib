#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000010;
int dpmin[maxn][20]; // (1 << 20) = 1048576
int n, m;
void rmqInit(){
    int k = log2(n);
    for(int j = 1; j <= k; j++){
        for(int i = 0; i + (1 << j) - 1 < n; i++){
            dpmin[i][j] = min(dpmin[i][j - 1], dpmin[i + (1 << j - 1)][j - 1]);
        }
    }
}
int rmq(int a, int b){
    int aa = min(a, b);
    int bb = max(a, b);
    int k = log2(bb - aa + 1);
    return min(dpmin[aa][k], dpmin[bb - (1 << k) + 1][k]);
}

int main(){
    std::ios::sync_with_stdio(false);  //不关同步的话用cin和cout会超时,注意关了之后不要混用printf和cout
    std::cin.tie(0); //接触cin与cout的绑定
    while(cin>>n){
        for(int i = 0; i < n; i++){
            cin>>dpmin[i][0];
        }
        rmqInit();
        cin>>m;
        int a, b;
        while(m--){
            cin>>a>>b;
            a--; b--;
            cout<<rmq(a, b)<<endl;
        }
    }
    return 0;
}
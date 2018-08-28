#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
int f[maxn << 2];
void build(int l, int r, int rt){
    if(l == r){
        cin>>f[rt];
        return ;
    }
    int m = l + r >> 1;
    build(l, m, rt << 1);
    build(m + 1, r, rt << 1 | 1);
    f[rt] = min(f[rt << 1], f[rt << 1 | 1]);
}
void update(int p, int v, int l, int r, int rt){
    if(l == r){
        f[rt] = v;
        return;
    }
    int m = l + r >> 1;
    if(p <= m) update(p, v, l, m, rt << 1);
    else update(p, v, m + 1, r, rt << 1 | 1);
    f[rt] = min(f[rt << 1], f[rt << 1 | 1]);
}

int query(int ql, int qr, int l, int r, int rt){
    if(ql <= l && r <= qr){
        return f[rt];
    }
    int m = l + r >> 1;
    int ans = 1e9;
    if(ql <= m) ans = min(ans, query(ql, qr, l, m, rt << 1));
    if(qr > m) ans = min(ans, query(ql, qr, m + 1, r, rt << 1 | 1));
    return ans;
}

int main(){
    int n;
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    while(cin>>n){
        build(1, n, 1);
        int q;
        int op, a, b;
        cin>>q;
        while(q--){
            cin>>op>>a>>b;
            if(op){
                update(a, b, 1, n, 1);
            }else{
                cout<<query(a, b, 1, n, 1)<<endl;
            }
        }
    }
}
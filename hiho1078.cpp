#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int sum[maxn << 2], tag[maxn << 2];

void build(int l, int r, int rt){
    tag[rt] = 0;
    if(l == r) {
        cin>>sum[rt];
        return ;
    }
    int m = l + r >> 1;
    build(l, m, rt << 1);
    build(m + 1, r, rt << 1 | 1);
    sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}
void pushdown(int rt, int m){
    if(tag[rt]){
        tag[rt << 1] = tag[rt];
        sum[rt << 1] = tag[rt] * (m - (m >> 1)); // !!
        tag[rt << 1 | 1] = tag[rt];
        sum[rt << 1 | 1] = tag[rt] * (m >> 1);
        tag[rt] = 0;
    }
}

void update(int ql, int qr, int v, int l, int r, int rt){
    if(ql <= l && r <= qr) {
        tag[rt] = v;
        sum[rt] = (r - l + 1) * v;
        return;
    }
    pushdown(rt, r - l + 1);
    int m = l + r >> 1;
    if(ql <= m) update(ql, qr, v, l, m, rt << 1);
    if(qr > m) update(ql, qr, v, m + 1, r, rt << 1 | 1);
    sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}

int query(int ql, int qr, int l, int r, int rt){
    if(ql <= l && r <= qr) {
        return sum[rt];
    }
    pushdown(rt, r - l + 1);
    int m = l + r >> 1;
    int ans = 0;
    if(ql <= m) ans += query(ql, qr, l, m, rt << 1);
    if(qr > m) ans += query(ql, qr, m + 1, r, rt << 1 | 1);
    return ans;
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int n;
    while(cin>>n){
        build(1, n, 1);
        int q;
        cin>>q;
        int op, ql, qr, v;
        while(q--){
            cin>>op;
            if(op){
                cin>>ql>>qr>>v;
                update(ql, qr, v, 1, n, 1);
            }else{
                cin>>ql>>qr;
                cout<<query(ql, qr, 1, n, 1)<<endl;
            }
        }
    }
    return 0;
}
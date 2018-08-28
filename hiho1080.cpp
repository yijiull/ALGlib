#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int sum[maxn << 2], ad[maxn << 2], st[maxn << 2];

void build(int l, int r, int rt){
    ad[rt] = st[rt] = 0;
    if(l == r){
        cin>>sum[rt];
        return;
    }
    int m = l + r >> 1;
    build(l, m, rt << 1);
    build(m + 1, r, rt << 1 | 1);
    sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}

void pushdown(int rt, int m){
    if(st[rt]){
        st[rt << 1] = st[rt << 1 | 1] = st[rt];
        ad[rt << 1] = ad[rt << 1 | 1] = 0;
        sum[rt << 1] = st[rt] * (m - (m >> 1));
        sum[rt << 1 | 1] = st[rt] * (m >> 1);
        st[rt] = 0;
    }
    if(ad[rt]){
        ad[rt << 1] += ad[rt];
        ad[rt << 1 | 1] += ad[rt];
        sum[rt << 1] += ad[rt] * (m - (m >> 1));
        sum[rt << 1 | 1] += ad[rt] * (m >> 1);
        ad[rt] = 0;
    }
}
void update(int op, int ql, int qr, int v, int l, int r, int rt){
    if(ql <= l && r <= qr){
        if(op){
            st[rt] = v;
            ad[rt] = 0;
            sum[rt] = (r - l + 1) * v;
        }else{
            ad[rt] += v;
            sum[rt] += (r - l + 1) * v;
        }
        return; //
    }
    pushdown(rt, r - l + 1);
    int m = l + r >> 1;
    if(ql <= m) update(op, ql, qr, v, l, m, rt << 1);
    if(qr > m) update(op, ql, qr, v, m + 1, r, rt << 1 | 1);
    sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}

int main(){
    int n, m;
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin>>n>>m){
        n++;
        //init
        build(1, n, 1);
        int op, ql, qr, v;
        while(m--){
            cin>>op>>ql>>qr>>v;
            ql++, qr++;
            update(op, ql, qr, v, 1, n, 1);
            cout<<sum[1]<<endl;
        }
    }
}
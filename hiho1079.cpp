#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;

int pa[maxn], pb[maxn], vis[maxn];
int c[maxn << 1];
int cnt;

int tag[maxn << 2];

void pushdown(int rt){
    if(tag[rt] != -1){
        tag[rt << 1] = tag[rt];
        tag[rt << 1 | 1] = tag[rt];
        tag[rt] = -1;
    }
}
void update(int ql, int qr, int v, int l, int r, int rt){
    if(ql <= l && r <= qr){
        tag[rt] = v;
        return;
    }
    //if(l + 1 == r) return;  //
    pushdown(rt);
    int m = l + r >> 1;
    if(ql < m) update(ql, qr, v, l, m, rt << 1);
    if(qr > m) update(ql, qr, v, m, r, rt << 1 | 1);
}

/*
case:
2 100
0 1
2 3
*/
int query(int ql, int qr, int l, int r, int rt){
    if(ql <= l && r <= qr) {
        if(tag[rt] != -1){
            if(!vis[tag[rt]]){
                vis[tag[rt]] = 1;
                return 1;
            }else{
                return 0;
            }
        }else{
            if(l + 1 == r) return 0; //
            int m = l + r >> 1;
            return query(ql, qr, l, m, rt << 1) + query(ql, qr, m, r, rt << 1 | 1);
        }
    }
    if(l + 1 == r) return 0;  //
    int m = l + r >> 1;
    int ans = 0;
    if(ql < m) ans += query(ql, qr, l, m, rt << 1);
    if(qr > m) ans += query(ql, qr, m, r, rt << 1 | 1);
    return ans;
}

int main(){
    int n, l;
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    while(cin>>n>>l){
        //init
        cnt = 0;
        memset(vis, 0, sizeof vis);
        memset(tag, -1, sizeof tag);

        int a, b;
        for(int i = 0; i < n; i++){
            cin>>pa[i]>>pb[i];
            c[cnt++] = pa[i];
            c[cnt++] = pb[i];
        }
        //c[cnt++] = 0;
        //c[cnt++] = l;
        sort(c, c + cnt);
        cnt = unique(c, c + cnt) - c;
        //cout<<cnt<<endl;
        for(int i = 0; i < n; i++){
            a = lower_bound(c, c + cnt, pa[i]) - c;
            b = lower_bound(c, c + cnt, pb[i]) - c;
            //cout<<"  == "<<a<<" "<<b<<endl;
            update(a, b, i, 0, cnt - 1, 1);
        }
        cout<<query(0, cnt - 1, 0, cnt - 1, 1)<<endl;
    }
}
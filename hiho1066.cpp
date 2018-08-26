#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
map<string, int> mp;
int cnt;
int f[maxn];
int gf(int x){
    return x == f[x] ? x : f[x] = gf(f[x]);
}
int main(){
    string s, p;
    int op;
    int n;
    while(cin>>n){
        for(int i = 0; i < maxn; i++) f[i] = i;
        mp.clear();
        for(int i = 0; i < n; i++){
            cin>>op>>s>>p;
            if(op){
                if(!mp.count(s) || !mp.count(p)){
                    cout<<"no\n";
                    continue;
                }
                int a = gf(mp[s]), b = gf(mp[p]);
                if(a == b) cout<<"yes\n";
                else cout<<"no\n";
            }else{
                if(!mp.count(s)) mp[s] = cnt++;
                if(!mp.count(p)) mp[p]=  cnt++;
                f[gf(mp[s])] = gf(mp[p]);
            }
        }
    }
}
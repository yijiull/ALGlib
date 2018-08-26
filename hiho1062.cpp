#include <bits/stdc++.h>
using namespace std;
const int maxn = 210;
int f[maxn], vis[maxn];
map<string, int> mp; 
string q[maxn];
int main(){
    int n, m;
    string s, p;
    while(cin>>n){
        int cnt = 0;
        mp.clear();
        for(int i = 0; i < maxn; i++) f[i] = i;
        for(int i = 0; i < n; i++){
            cin>>s>>p;
            if(!mp.count(s)){
                q[cnt] = s;
                mp[s] = cnt++;
                
            }
            if(!mp.count(p)){
                q[cnt] = p;
                mp[p] = cnt++;
            }
            f[mp[p]] = mp[s];
        }
        cin>>m;
        while(m--){
            memset(vis, 0, sizeof vis);
            cin>>s>>p;
            int id1 = -1, id2 = -1;
            if(mp.count(s)) id1 = mp[s];
            if(mp.count(p)) id2 = mp[p];
             if(s == p){
                cout<<s<<endl;
                continue;
            }
            if(id1 == -1 || id2 == -1) {
                cout<<-1<<endl;
                continue;
            }
            while(!vis[id1]) {
                vis[id1] = 1;
                id1 = f[id1];
            }
            while(!vis[id2] && id2 != f[id2]){
                vis[id2] = 1;
                id2 = f[id2];
            }
            if(vis[id2]) cout<<q[id2]<<endl;
            else cout<<-1<<endl;
        }
    }
}

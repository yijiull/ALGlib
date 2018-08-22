#include "ac.h"
#include <queue>
void AC::insert(const std::string &s, int v){
    int n = s.length(), u = 0;
    for(int i = 0; i < n; i++){
        int c = idx(s[i]);
        if(!ch[u][c]){ //new node
            memset(ch[sz], 0, sizeof( ch[sz]));
            //val[sz] = 0;
            match[sz] = 0;
            ch[u][c] = sz++;
        } 
        u = ch[u][c];
    }
    //val[u] = v;
    match[u] = 1;
}
void AC::getFail(){
    std::queue<int> q;
    f[0] = 0;
    for(int i = 0; i < sigma; i++){
        int u = ch[0][i];
        if(u){
            q.push(u);
            f[u] = 0;
            //last[u] = 0;
        }
    }
    while(!q.empty()){
        int r = q.front();
        q.pop();
        for(int c = 0; c < sigma; c++){
            int u =ch[r][c];
            if(!u) {
                ch[r][c] = ch[f[r]][c];    
                continue;
            }
            q.push(u);
            int v = f[r];
            while(v && !ch[v][c]) v = f[v];
            f[u] = ch[v][c];
            //last[u] = val[f[u]] ? f[u] : last[f[u]];
            match[u] |= match[f[u]];
        }
    }
}
void AC::print(int u){
    if(u){
       // cnt[val[u]]++;
       // print(last[u]);
    }
}

int AC::find(const std::string &s){
    int n = s.length();
    int u = 0;
    for(int i = 0; i < n; i++){
        int c = idx(s[i]);
        while(u && !ch[u][c]) u = f[u];
        u = ch[u][c];
        if(match[u]) return 1;
        //if(val[u]) print(u);
        //else if(last[u]) print(last[u]);
    }
    return 0;
}

//hiho1036trie图
AC ac;
#include <iostream>
using namespace std;
int main(){
    string s, p;
    int n;
    cin>>n;
    while(n--){
        cin>>s;
        ac.insert(s, 0);
    }
    ac.getFail();
    cin>>p;
    if(ac.find(p)){
        cout<<"YES\n";
    }else{
        cout<<"NO\n";
    }
}
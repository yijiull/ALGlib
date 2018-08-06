#include "ac.h"
#include <queue>
void AC::insert(const std::string &s, int v){
    int n = s.length(), u = 0;
    for(int i = 0; i < n; i++){
        int c = idx(s[i]);
        if(!ch[u][c]){ //new node
            memset(ch[sz], 0, sizeof( ch[sz]));
            val[sz] = 0;
            ch[u][c] = sz++;
        } 
        u = ch[u][c];
    }
    val[u] = v;
}
void AC::getFail(){
    std::queue<int> q;
    f[0] = 0;
    for(int i = 0; i < sigma; i++){
        int u = ch[0][i];
        if(u){
            q.push(u);
            f[u] = 0;
            last[u] = 0;
        }
    }
    while(!q.empty()){
        int r = q.front();
        q.pop();
        for(int c = 0; c < sigma; c++){
            int u =ch[r][c];
            if(!u) continue;
            q.push(u);
            int v = f[r];
            while(v && !ch[v][c]) v = f[v];
            f[u] = ch[v][c];
            last[u] = val[f[u]] ? f[u] : last[f[u]];
        }
    }
}
void AC::print(int u){
    if(u){
        cnt[val[u]]++;
        print(last[u]);
    }
}
void AC::find(const std::string &s){
    int n = s.length();
    int u = 0;
    for(int i = 0; i < n; i++){
        int c = idx(s[i]);
        while(u && !ch[u][c]) u = f[u];
        u = ch[u][c];
        if(val[u]) print(u);
        else if(last[u]) print(last[u]);
    }
}
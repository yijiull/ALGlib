#include "trie.h"
#include <cstring>
Trie::Trie(){
    clear();
}
void Trie::clear(){
    memset(ch[0], 0, sizeof ch[0]);
    val[0] = 0;
    sz = 1;
}
int Trie::idx(char c){
    return c - 'a';
}
bool Trie::insert(char *s){
    int len = strlen(s);
    int u = 0;
    val[u]++;
    for(int i = 0; i < len; i++){
        int c = idx(s[i]);
        if(ch[u][c] == 0){
            memset(ch[sz], 0, sizeof ch[sz]);
            val[sz] = 0;
            ch[u][c] = sz++;
        }
        u = ch[u][c];
        val[u]++;
    }
}
int Trie::find(char *s){
    int len = strlen(s);
    int u = 0;
    for(int i = 0; i < len; i++){
        int c = idx(s[i]);
        if(ch[u][c] == 0){
            return 0;
        }
        u = ch[u][c];
    }
    return val[u];
}
#include <iostream>
using namespace std;
char s[11];
Trie trie;
 int main(){
     int n, m;
     while(cin>>n){
         trie.clear();
         for(int i = 0; i < n; i++){
             cin>>s;
             trie.insert(s);
         }
         cin>>m;
         while(m--){
             cin>>s;
             cout<<trie.find(s)<<endl;
         }
     }
 }
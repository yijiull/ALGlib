#include <string>
#include <cstring>
using namespace std;
#include "manacher.h"
Manacher::Manacher(string ms):s(ms){
    maxlen = 0;
    st = 0;
    solve();
}
void Manacher::setString(string ms){
    s = ms;
    solve();
}
string Manacher::getString(){
    return s;
}
void Manacher::solve(){
    int n = s.length();
    int *r = new int[n * 2 + 10];
    memset(r, 0, sizeof r);
    string sx;
    sx.push_back('$');
    for(int i = 0; i <= n; i++){
        sx.push_back('*');
        sx.push_back(s[i]);
    }
    int c = 0, m = 0;
    n += n + 1;
    for(int i = 2; i < n; i++){
        if(r[c] + c > i) r[i] = min(r[c * 2 - i], r[c] + c - i);
        else r[i] = 1;
        while(sx[i - r[i]] == sx[i + r[i]]) r[i]++;
        if(c + r[c] < i + r[i]) c = i;
        if(m < r[i]) {
            m = r[i];
            int temp = (i - 2) / 2;
            //if((i - 2) & 1) {
            //    st = temp - (m - 1) / 2 + 1;
            //}else{
            //    st = temp - (m - 1) / 2;
            //}
            st = temp - (m - 1) / 2;
            if((i - 2) & 1){
                st++;
            }
        }
    }
    maxlen = m - 1;
    delete[] r;
}
string Manacher::getMaxString(){
    return s.substr(st, st + maxlen);
}
int Manacher::getMaxLen(){
    return maxlen;
}
#include <iostream>
int main(){
    int n;
    cin>>n;
    string s;
    Manacher manacher;
    while(n--){
        cin>>s;
        manacher.setString(s);
        cout<<manacher.getMaxLen()<<endl;
        //cout<<manacher.getMaxString()<<endl;
    }
}
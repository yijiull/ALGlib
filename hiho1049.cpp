#include <bits/stdc++.h>
using namespace std;
//前序遍历：s1；中序遍历：s2；输出后续遍历
void post(string s1, string s2){
    char rt = s1[0];
    int cntl = 0;
    while(s2[cntl] != rt){
        cntl++;
    }
    if(cntl + 1 > 1) post(s1.substr(1, cntl), s2.substr(0, cntl));
    if(cntl + 1 < s1.length()) post(s1.substr(cntl + 1), s2.substr(cntl + 1));
    cout<<rt;
}
int main(){
    string s1, s2;
    while(cin>>s1>>s2){
        post(s1, s2);
        cout<<endl;
    }    
}
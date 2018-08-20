#include "kmp.h"
KMP::KMP(std::string text, std::string pattern) :
    text(text), pattern(pattern) {}

void KMP::setText(std::string s){
    text = s;
}
void KMP::setPattern(std::string s){
    pattern = s;
}
std::vector<int>& KMP::getResult(){
    return result;
}
void getFail(const std::string &s, std::vector<int> &fail){
    int n = s.length();
    fail.push_back(0);
    fail.push_back(0);
    for(int i = 1; i < n; i++){
        int j = fail[i];
        while(j && s[i] != s[j]) j = fail[j];
        fail.push_back(s[i] == s[j] ? j + 1 : 0); 
        //下面几行是对这里fail数组的优化，不过优化之后就没有循环节的性质了
        //优化完之后反而过不了hiho1015了，还不知道原因
        //if(s[i] == s[j]){
        //    if(s[i + 1] == s[j + 1]) fail.push_back(fail[j + 1]);
        //    else fail.push_back(j + 1);
        //}else{
        //    fail.push_back(0);
        //}
    }
}

std::vector<int>& KMP::kmp(){
    result.clear();
    std::vector<int> fail;
    getFail(pattern, fail);
    int n = text.length();
    int m = pattern.length();
    int j = 0;
    for(int i = 0; i < n; i++){
        while(j && pattern[j] != text[i]) j = fail[j];
        if(pattern[j] == text[i]) j++;
        if(j == m) {
            result.push_back(i - m + 1);
            //j = 0;  //是否计算重叠部分
        }
    }
    return result;
}

std::vector<int>& KMP::bm(){
    result.clear();
    //TODO
    return result;
}

void preProcess(const std::string &s, std::vector<int> &mv){
    int n = s.length();
    for(int i = 0; i < n; i++){
        mv[s[i]] = i;
    }
}

std::vector<int>& KMP::sunday(){
    result.clear();
    std::vector<int> res, mv(256, -1); //
    int n = text.length(), m = pattern.length();
    preProcess(pattern, mv);
    int i = 0;
    int nm = n - m;
    while(i <= nm){ //=
        int j = 0;
        for(; j < m; j++){
            if(text[i] != pattern[j]) break;
            else i++;
        }
        if(j == m){
            result.push_back(i - m);
        }/*else*/{  //这里的else如果不注释掉，就不统计重叠的部分
            i += m - j;
            i -= mv[text[i]];
        }
    }
    return result;
}
#include <iostream>
using namespace std;
int main(){
    string s, p;
    int n;
    cin>>n;
    KMP kmp;
    //kmp.setPattern("aa");
    //kmp.setText("aaaaaaaa");
    //cout<<kmp.sunday().size()<<endl;
    //cout<<kmp.kmp().size()<<endl;
    while(n--){
        cin>>p>>s;
        kmp.setText(s);
        kmp.setPattern(p);
        auto v1 = kmp.kmp(); //这个题用sunday会超时，可能数据针对kmp设计的
        cout<<v1.size()<<endl;
    }
}
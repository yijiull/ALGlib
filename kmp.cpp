#include "kmp.h"
void getFail(const std::string &s, std::vector<int> &fail){
    int n = s.length();
    fail.push_back(0);
    fail.push_back(0);
    for(int i = 1; i < n; i++){
        int j = fail[i];
        while(j && s[i] != s[j]) j = fail[j];
        //fail.push_back(s[i] == s[j] ? j + 1 : 0); 
        //下面几行是对这里fail数组的优化，不过优化之后就没有循环节的兴致了
        if(s[i] == s[j]){
            if(s[i + 1] == s[j + 1]) fail.push_back(fail[j + 1]);
            else fail.push_back(j + 1);
        }else{
            fail.push_back(0);
        }
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
        if(j == m) result.push_back(i - m + 1);
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
        }else{
            i += m - j;
            i -= mv[text[i]];
        }
    }
    return result;
}
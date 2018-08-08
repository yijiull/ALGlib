#include "sa.h"

void SA::rmqInit(){
    int k = 0;
    while(1 << (1 + k) <= n){
        k++;
    }
    for(int i = 1; i <= n; i++) dp[i].push_back(height[i]);
    for(int i = 1; i <= k; i++){
        for(int j = 1; j + (1 << i) <= n; j++){
            dp[i].push_back(min(dp[i][j-1], dp[i + (1 << j-1)][j-1]));
        }
    }
}
int SA::rmq(int a, int b){
    a = rank[a];
    b = rank[b];
    if(a > b) swap(a, b);  //    
    a++;
    int k = 0;
    while(1<<(k+1) <= b-a+1) k++;
    return min(dp[a][k], dp[b - (1<<k) + 1][k]);
}

void SA::calHeight(){
    int i, j, k=0;
    for(i = 1; i <= n; i++) rank[sa[i]]=i; 
    for(i = 0; i < n; i++) {
        if(k) k--;
        j = sa[rank[i]-1];
        while(s[i+k]==s[j+k]) k++;
        height[rank[i]] = k;
    }
}

void SA::process(){
    int i, *x = new int[n], *y = new int[n];
    int *c = new int[m]; //sum
    for(i = 0; i < m; i++) c[i] = 0;
    for(i = 0; i < n; i++) c[x[i] = s[i]]++;
    for(i = 1; i < m; i++) c[i] += c[i-1];
    for(i = n-1; i >= 0; i--) sa[--c[x[i]]] = i;

    for(int k = 1; k <= n; k <<= 1){
        int p = 0;
        for(i = n-k; i < n; i++) y[p++] = i;
        for(i = 0; i < n; i++) if(sa[i] >= k) y[p++] = sa[i]-k; 
        for(i = 0; i < m; i++) c[i] = 0;
        for(i = 0; i < n; i++) c[x[y[i]]]++;
        for(i = 1; i< m; i++) c[i] += c[i-1];
        for(i = n-1; i >= 0; i--) sa[--c[x[y[i]]]] = y[i];
        swap(x,y);
        p = 1;
        x[sa[0]] = 0;
        for(i = 1; i < n; i++) 
          x[sa[i]] = y[sa[i]]==y[sa[i-1]] && y[sa[i]+k]==y[sa[i-1]+k]? p-1 : p++;
        if(p>=n) break;
        m=p;
    }
    calHeight();
    delete[] x;
    delete[] y;
}

SA::SA(string s = "banana$"): s(s) {
    n = s.length();
    m = 256;
    sa = new int[n];
    rank = new int[n];
    height = new int[n];
    for(int i = 0; i < n; i++) {
        vector<int> v;
        dp.push_back(v); // 这里局部变量应该是复制的吧，释放也没事
    }
    process();
    rmqInit();
};

SA::~SA(){
    delete[] sa, rank, height;
}

void SA::setString(string _s){
    s = _s;
    n = s.length() + 1;
    s[n - 1] = '$'; // !
    if(sa != nullptr){
        dp.clear();
        delete sa;
        delete rank;
        delete height;
        sa = new int[n];
        rank = new int[n];
        height = new int[n];
        for(int i = 0; i < n; i++) {
            vector<int> v;
            dp.push_back(v); // 这里局部变量应该是复制的吧，释放也没事
        }
    }
    process();
    rmqInit();
}

int* SA::getSa(){
    return sa;
};
int* SA::getRank(){
    return rank;
}
int* SA::getHeight(){
    return height;
}
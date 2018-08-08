#include "kmp.h"
#include <iostream>
using namespace std;

void add(vector<vector<int>> &temp){
    for(int i = 0; i < 10; i++){
        vector<int> v(10, i);
        temp.push_back(v);
    }
}

int main(){
    KMP kmp;
    vector<int> v = kmp.kmp();
    for(int i= 0; i < v.size(); i++) cout<<v[i]<<" ";
    cout<<endl;
    v = kmp.sunday();
    for(int i= 0; i < v.size(); i++) cout<<v[i]<<" ";
    cout<<endl;
    vector<vector<int>> temp;
    add(temp);
    for(int i = 0; i < temp.size(); i++){
        for(int j = 0; j < temp[i].size(); j++){
            cout<<temp[i][j]<<" ";
        }
        cout<<endl;
    }
}
#include "kmp.h"
#include <iostream>
using namespace std;

int main(){
    KMP kmp;
    vector<int> v = kmp.kmp();
    for(int i= 0; i < v.size(); i++) cout<<v[i]<<" ";
    cout<<endl;
    v = kmp.sunday();
    for(int i= 0; i < v.size(); i++) cout<<v[i]<<" ";
    cout<<endl;

}
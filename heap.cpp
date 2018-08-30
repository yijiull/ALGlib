#include "heap.h"
#include <random>
#include <iostream>

template<typename T>
void Heap<T>::siftdown(int id){
    int n = v.size();
    int m = n / 2 - 1;
    while(id <= m){
        int ls = id << 1 | 1;
        int rs = ls + 1;
        if(rs < n && v[ls] < v[rs]) ls = rs; 
        if(v[ls] < v[id]) break;
        swap(v[ls], v[id]);
        id = ls;
    } 
}

template<typename T>
void Heap<T>::siftup(int id){
    while(id > 0){
        int f = (id - 1) / 2;
        if(v[f] >= v[id]) break;
        swap(v[f], v[id]);
        id = f;
    }
}

template<typename T>
Heap<T>::Heap(T *a, int n){
    build(a, n);
}

template<typename T>
void Heap<T>::clear(){
    v.clear();
}
template<typename T>
void Heap<T>::build(T *a, int n){
    for(int i = 0; i < n; i++){
        v.push_back(a[i]);
        siftup(i);
    }
}

template<typename T>
T Heap<T>::top(){
    return v[0];
}

template<typename T>
void Heap<T>::pop(){
    swap(v[0], v[v.size() - 1]);
    v.pop_back();
    siftdown(0);
}
template<typename T>
void Heap<T>::push(const T &a){
    v.push_back(a);
    siftup(v.size() - 1);
}

template<typename T>
bool Heap<T>::empty(){
    return v.size() == 0;
}
template<typename T>
T Heap<T>::get(const int &i){
    return v[i];
}
template<typename T>
void Heap<T>::print(){
    cout<<"------test------\n";
    for(int i = 0; i < v.size(); i++) cout<<v[i]<<" ";
    cout<<"\n------test------\n";
}
#include <queue>

void test(){
    default_random_engine e(0);
    uniform_int_distribution<int> u(0, 1313131);
    int n;
    while(cin>>n){
        Heap<int> p;
        priority_queue<int> q;
        
        int *a = new int[n];
        for(int i = 0; i < n; i++){
            a[i] = u(e);
        }
        p.build(a, n);
        for(int i = 0; i < n; i++){
            q.push(a[i]);
        }
        cout<<"------norm------\n";
        while(!q.empty()){
            cout<<q.top()<<" ";
            q.pop();
        }
        cout<<"\n------norm------\n";
        cout<<"\n------test------\n";
        while(!p.empty()){
            cout<<p.top()<<" ";
            p.pop();
        }
        cout<<"\n------test------\n";
        delete[] a;
    }
}
Heap<int> p;
int main(){
    int n;
    while(cin>>n){
        string op;
        int a;
        p.clear();
        while(n--){
            cin>>op;
            if(op == "A"){
                cin>>a;
                p.push(a);
            }else{
                cout<<p.top()<<endl;
                p.pop();
            }
        }
    }
}
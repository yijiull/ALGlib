#include <vector>
using namespace std;

template<typename T>
class Heap{
private:
    vector<T> v;
    void siftdown(int id);
    void siftup(int id);
public:
    Heap(T *a = nullptr, int n = 0);
    void clear();
    void build(T *a, int n);
    T top();
    void pop();
    void push(const T &a);
    bool empty();
    T get(const int &i);
    void print();
};
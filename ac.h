//ac自动机对不同题目有不同的处理，不好给出一个模板
#include <vector>
#include <string>
#include <cstring>

class AC{
private:
    const static int maxnode = 10010;
    const static int sigma = 26;
    int ch[maxnode][sigma];
    int last[maxnode], val[maxnode], cnt[maxnode];
    int f[maxnode];
    int sz;

public:
    AC(){
        memset(ch[0], 0, sizeof( ch[0]));
        memset(cnt, 0, sizeof( cnt));
        sz = 1;
    }
    int idx(char c){
        return c - 'a';
    };
    void insert(const std::string &s, int v);
    void getFail();
    void print(int u);
    void find(const std::string &s);

};
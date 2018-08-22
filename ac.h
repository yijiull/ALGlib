//ac自动机对不同题目有不同的处理，不好给出一个模板
#include <vector>
#include <string>
#include <cstring>

const int maxnode = 10010; //节点数
const int sigma = 26; //字符集大小

class AC{
private:
    int ch[maxnode][sigma];
    //int last[maxnode], val[maxnode], cnt[maxnode];
    int match[maxnode];
    int f[maxnode];
    int sz;

public:
    AC(){
        memset(ch[0], 0, sizeof( ch[0]));
        //memset(cnt, 0, sizeof( cnt));
        memset(match, 0, sizeof match);
        sz = 1;
    }
    int idx(char c){
        return c - 'a';
    };
    void insert(const std::string &s, int v);
    void getFail();
    void print(int u);
    int find(const std::string &s);

};
const int maxnode = 1000010; //100000 * 10 + 10
const int sigma = 26;
class Trie{
private:
    int ch[maxnode][sigma];
    int val[maxnode];
    int sz;
    int idx(char c);
public:
    Trie();
    void clear();
    bool insert(char *s);
    int find(char *s);
};
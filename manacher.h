#include <string>
class Manacher{
private:
    std::string s;
    int maxlen;
    int st; //最长回文串的起始下标
    void solve();
public:
    Manacher(std::string s = "abchjhabcba");
    void setString(std::string ms);
    std::string getString();
    std::string getMaxString();
    int getMaxLen();
};
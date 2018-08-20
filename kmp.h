#include <string>
#include <vector>
class KMP{
private:
    std::string text, pattern; //文本串、要查找的模式串
    std::vector<int> result; //匹配的位置
public:
    KMP(std::string text = "hello search ababa abanisearchhao search wosearrld search ",
     std::string pattern = "aba");
    void setText(std::string s);
    void setPattern(std::string s);
    std::vector<int>& getResult();
    std::vector<int>& kmp();
    std::vector<int>& bm(); //TODO
    std::vector<int>& sunday();
};
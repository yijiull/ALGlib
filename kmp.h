#include <string>
#include <vector>
class KMP{
private:
    std::string text, pattern; //文本串、要查找的模式串
    std::vector<int> result; //匹配的位置

public:
    //answer:6,15,25,42
    KMP(std::string text = "hello search nisearchhao search wosearrld search ",
     std::string pattern = "search") :
        text(text), pattern(pattern) {}

    void setText(std::string s){
        text = s;
    }
    void setPattern(std::string s){
        pattern = s;
    }
    std::vector<int>& getResult(){
        return result;
    }
    std::vector<int>& kmp();

    std::vector<int>& bm();

    std::vector<int>& sunday();

};
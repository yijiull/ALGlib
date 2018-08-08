#include <string>
#include <vector>
using namespace std;

class SA{
private:
    string s;
    int n, m;
    int *sa, *rank;
    int *height;  //LCP

    //RMQ
    vector<vector<int>> dp;
    void rmqInit(); //处理heigth数组

    void process(); //计算sa
    void calHeight(); //计算height

public:
    SA(string s = "banana$");
    ~SA();
    void setString(string _s);
    int* getSa();
    int* getRank();
    int* getHeight();
    int rmq(int a, int b); //计算任意两个后缀的最长公共前缀
};
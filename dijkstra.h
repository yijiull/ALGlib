#include <vector>
#include <queue>
const int maxn = 1010;
class Dij{
private:
    struct Edge{
        int u, v, w;
    };
    std::vector<Edge> e;
    std::vector<int> g[maxn];
public:
    int d[maxn], p[maxn];
    Dij();
    void init();
    void addEdge(int u, int v, int w);
    int dijkstra(int s, int t);
    void floyd();
};
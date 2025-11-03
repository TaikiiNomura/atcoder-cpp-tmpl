#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <deque>
#include <string>
#include <vector>
#include <limits>
#include <numeric>

using namespace std;

#ifdef LOCAL
#include "bin/debug.h"
#else
#define debug(...)
#endif

#define REP(i, S, E) for(int i = S; i < (int)E; i++)
#define rep(i, N) REP(i, 0, N)
#define all(V) V.begin(), V.end()

template<class T>void print_v(const vector<T> &V){rep(i, V.size()) cout << V[i] << (i == V.size()-1 ? '\n': ' ');}
template<class T> inline bool chmin(T& a, const T& b){ if(a>b){a=b; return true;} return false; }
template<class T> inline bool chmax(T& a, const T& b){ if(a<b){a=b; return true;} return false; }

// const int dx4[4] = {0, 0, 1, -1};
// const int dy4[4] = {-1, 1, 0, 0};
// const int dx8[8] = { -1,-1,-1,0,1,1,1,0 };
// const int dy8[8] = { -1,0,1,1,1,0,-1,-1 };
// const int INF = 1e9;

// 無向・有向グラフ
// 最短距離
// 訪問順・到達判定
// 木DFS
// Dijkstra
// 0-1 BFS
// Bellman-Ford
// LCA
// DSU
// トポロジカルソート

using Graph = vector<vector<int>>;
using WGraph = vector<vector<pair<int, int64_t>>>;

Graph read_graph(int n, int m, bool directed = false)
{
    Graph g(n);
    rep(i, m)
    {
        int u,v; cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        if(!directed)g[v].push_back(u);
    }
    return g;
}

WGraph read_wgraph(int n, int m, bool directed = false)
{
    WGraph g(n);
    reo(i, m)
    {
        int u, v;
        int64_t w;
        cin >> u >> v >> w;
        u--; v--;
        g[u].push_back({v, w});
        if(!directed)g[v].push_back({v, w});
    }
    return g;
}

vector<int> bfs(const Graph &g, int start)
{
    int n = (int)g.size();
    vector<int> dist(n, INF);
    queue<int> q;
    dist[start] = 0;
    q.push(start);
    while(!q.empty())
    {
        int v = q.front();
        q.pop();
        for(int nv : g[v])
        {
            if(dist[nv] == INF)
            {
                dist[nv] = dist[v] + 1;
                q.push(nv);
            }
        }
    }
    return dist;
}

/*}}}*/

void solve()
{
    // problem logic
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while(T--)
    {
        solve();
    }
}

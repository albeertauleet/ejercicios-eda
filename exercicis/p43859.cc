#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

typedef pair<double, int> ArcP;
typedef vector<vector<ArcP>> Graph;

int const infinit = numeric_limits<int>::max();

void entrar_graf (Graph& g, int n, int m)
{
    g = Graph(n);
    int x, y;
    int p;
    for (int i = 0; i < m; ++i)
    {
        cin >> x >> y >> p;
        g[x].push_back(make_pair(p, y));
    }

}



void dijkstra(const Graph& g, int x, int y, vector<int>& d , vector<int>& p, int& dis)
{
    int n = g.size();
    dis = -1;
    d = vector<int>(n, infinit);
    d[x] = 0;
    p = vector<int>(n, -1);
    vector<bool> S (n, false);
    priority_queue<ArcP, vector<ArcP>, greater<ArcP>> Q;
    Q.push(ArcP(0, x));

    while (not Q.empty())
    {
        int u = Q.top().second;
        Q.pop();
        if (not S[u])
        {
            S[u] = true;
            if (u == y)
            {
                dis = d[u];
                return;
            }
            int m = g[u].size();
            for (int i = 0; i < m; ++i) 
            {
                int v = g[u][i].second;
                int c = g[u][i].first;
                if (d[v] > d[u] + c)
                {
                    d[v] = d[u] + c;
                    p[v] = u;
                    Q.push(ArcP(d[v], v));
                }
            }
        }
    }
}

int main()
{
    int n, m;
    while (cin >> n >> m)
    {
        Graph g;
        entrar_graf(g, n, m);
        vector<int> d;
        vector<int> p;
        int x, y;
        cin >> x >> y;
        int dis;
        dijkstra(g, x, y, d, p, dis);
        if (dis != -1) cout << dis << endl;
        else cout << "no path from " << x << " to " << y << endl;

    }
}
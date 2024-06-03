#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

typedef pair<int, int> ArcP;
typedef vector<vector<ArcP>> Graph;

const int infinit = numeric_limits<int>::max();


void entrar_graf(Graph& g, int n, int m)
{
    g = Graph(n);
    int x, y, p;
    for (int i = 0; i < m; ++i)
    {
        cin >> x >> y >> p;
        g[x].push_back(make_pair(p, y));
    }
}

void dijkstra(const Graph& g, vector<int>& distance, vector<int>& prev, int x, int y, int& dis)
{
    int n = g.size();
    dis = -1;
    priority_queue<ArcP, vector<ArcP>, greater<ArcP>> Q;
    distance[x] = 0;
    vector<bool> vis(n, false);
    vector<int> cami(n, 0);
    Q.push(ArcP(0 , x));
    while (not Q.empty())
    {
        int u = Q.top().second;
        Q.pop();
        if (not vis[u])
        {
            vis[u] = true;
            if (u == y)
            {
                dis = distance[u];
                int passos = cami[u];
                cout << "cost " << dis << ", " << passos << " step(s)" << endl;
                return;
            }
            else
            {
                int m = g[u].size();
                for (int i = 0; i < m; ++i)
                {
                    int v = g[u][i].second;
                    int c = g[u][i].first;
                    if (distance[v] > distance[u] + c or ((distance[v] == distance[u]+ c) and cami[v] > cami[u] + 1))
                    {
                        distance[v] = distance[u] + c;
                        prev[v] = u;
                        cami[v] = cami[u] + 1; 
                        Q.push(ArcP(distance[v], v));
                    }

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
        vector<int> distance(n, infinit);
        vector<int> prev(n, -1);
        int x, y;
        cin >> x >> y;
        int dis;
        dijkstra(g, distance, prev, x, y, dis);
        if (dis == -1) cout << "no path from " << x << " to " << y << endl;
    }
}
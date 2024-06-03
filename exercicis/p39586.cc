#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int infinit = numeric_limits<int>::max();

typedef pair<int, int> ArcP;
typedef vector<vector<ArcP>> Graph;

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

void dijkstra(const Graph& g, vector<int>& distance, vector<int>& prev, int x, int y, int& dis, vector<int>& num)
{
    int n = g.size();
    distance[x] = 0;
    num[x] = 1;
    vector<bool> vis(n, false);
    priority_queue<ArcP, vector<ArcP>, greater<ArcP>> Q; 
    Q.push(ArcP(0, x));
    while (not Q.empty())
    {
        int u = Q.top().second;
        Q.pop();
        if (not vis[u])
        {
            
            vis[u] = true;
            int m = g[u].size();
            for (int i = 0; i < m; ++i)
            {
                int v = g[u][i].second;
                int c = g[u][i].first;
                if (distance[v] > distance[u] + c)
                {
                    distance[v] = distance[u] + c;
                    prev[v] = u;
                    Q.push(ArcP(distance[v], v));
                    num[v] = num[u];
                }
                else if (distance[v] == distance[u] + c) num[v] += num[u];
             
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
        int contador = 0;
        int dis;
        int x, y;
        cin >> x >> y;
        vector<int> num(n, 0);
        dijkstra(g, distance, prev, x, y, dis, num);
        if (distance[y] != infinit)
        {
            cout << "cost " << distance[y] << ", " << num[y] << " way(s)" << endl;
        }
        else cout << "no path from " << x << " to " << y << endl;
    }
}
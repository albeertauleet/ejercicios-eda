#include <iostream>
#include <vector>
#include <queue>
#include <list>
using namespace std;

typedef vector<vector<int>> Graph;

void entrar_graf(Graph& g, int n, int m)
{
    g = Graph(n);
    int x, y;
    for (int i = 0; i < m; ++i)
    {
        cin >> x >> y;
        g[x].push_back(y);
    }
}

void quines_abans(Graph& g)
{
    int n = g.size();
    priority_queue<int, vector<int>, greater<int>> s;
    vector<int> ordre(n, 0);
    for (int i = 0; i < n; ++i)
    {
        for (int u = 0; u < g[i].size(); ++u)
        {
            ++ordre[g[i][u]];
        }
        
    }
    for (int u = 0; u < n; ++u)
    {
        if (ordre[u] == 0) s.push(u);
    }
    list<int> l;
    while (not s.empty())
    {
        int u = s.top();
        s.pop();
        l.push_back(u);
        for (int i = 0; i < g[u].size(); ++i)
        {
            if (--ordre[g[u][i]] == 0) s.push(g[u][i]);
        }
    }
    bool first = true;
    for (list<int>::iterator it = l.begin(); it != l.end(); ++it)
    {
        if (first)
        {
            cout << *it;
            first = false;
        }
        else 
            cout << " " << *it;
    }
    cout << endl;
}


int main()
{
    int n, m;
    while (cin >> n >> m)
    {
        Graph g;
        entrar_graf(g, n, m);
        quines_abans(g);
    }
}
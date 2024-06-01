#include <iostream>
#include <vector>

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
        g[y].push_back(x);
    }

}

void es_colorejable(Graph& g, int i,  int color, vector<int>& v, bool& es)
{
    v[i] = color;
    for (int u : g[i])
    {
        if (v[u]  == color) es = false;
        else if (v[u] == -1) es_colorejable(g, u, (color+1)%2, v, es);
    }
}

bool dfs(Graph& g)
{
    vector<int> vis(g.size() , -1);
    bool es = true;
    for(int i = 0; i < g.size(); ++i)
    {
        if(vis[i] == -1)
        {
            es_colorejable(g, i, 0, vis, es);
    
        }
        
    }
    return es;
}

int main()
{
    int n, m;
    while (cin >> n >> m)
    {
        Graph g;
        entrar_graf(g, n, m);
        if (dfs(g)) cout << "yes" << endl;
        else cout << "no" << endl;

    }


}
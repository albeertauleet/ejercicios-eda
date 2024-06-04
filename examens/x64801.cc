#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> Graph;
int n, m;
Graph g;
vector<bool> vis, recStack;
bool te_cicle;

void entrar_graf()
{
    g = Graph(n);
    int x, y;
    for (int i = 0; i < m; ++i)
    {
        cin >> x >> y;
        g[x].push_back(y);
    }
}

void es_ciclic(int actual)
{
    if (!vis[actual])
    {
        vis[actual] = true;
        recStack[actual] = true;

        int m = g[actual].size();
        for (int i = 0; i < m; ++i)
        {
            if (!vis[g[actual][i]])
            {
                es_ciclic(g[actual][i]);
                if (te_cicle) return;
            }
            else if (recStack[g[actual][i]])
            {
                te_cicle = true;
                return;
            }
        }
    }

    recStack[actual] = false;  
}

int main()
{  
    while (cin >> n >> m)
    {
        vis = vector<bool> (n, false);
        recStack = vector<bool> (n, false);
        entrar_graf();
        te_cicle = false;
        for (int i = 0; i < n; ++i) 
        {
            if (!vis[i]) es_ciclic(i);
            if (te_cicle) break;
        }
        if (te_cicle) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}
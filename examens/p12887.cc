#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> ArcP;
typedef vector<vector<ArcP>> Graph;
typedef vector<bool> VB;

Graph g;
VB vis;
int n, m, pes;

void entrar_graf()
{
    vis = VB(n, false);
    g = Graph(n);
    int x, y, p;
    for (int i = 0; i < m; ++i)
    {
        cin >> x >> y >> p;
        g[x-1].push_back(make_pair(p,y-1));
        g[y-1].push_back(make_pair(p,x-1));
    }
}

int minim_pes()
{
    priority_queue<ArcP, vector<ArcP>, greater<ArcP>> q;
    q.push(make_pair(0,0));
    int sum = 0;
    while (not q.empty())
    {
        int c = q.top().first;
        int x = q.top().second;
        q.pop();
        if (not vis[x])
        {
            vis[x] = true;
            sum += c;
            int m = g[x].size();
            for (int i = 0; i < m; ++i)
            {
                ArcP temp = g[x][i];
                int c2 = temp.first;
                int x2 = temp.second;
                q.push(make_pair(c2, x2));
            }
        }
    }
    return sum;
}

int main()
{
    while (cin >> n >> m)
    {
        entrar_graf();
        cout << minim_pes() << endl;
    }
}
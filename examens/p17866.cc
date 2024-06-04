#include <iostream>
#include <queue>
#include <vector>
#include <limits>
using namespace std;

typedef vector<vector<char>> MC;
typedef vector<vector<bool>> MB;
typedef vector<vector<int>> MI;
typedef pair<int, int> Pair;


int n, m;
MC g;
MB vis;
MI passos;
const int infinit = numeric_limits<int>::max();
const int DI[] = {2, -2, 2, -2, 1, -1, 1, -1};
const int DJ[] = {1, 1, -1, -1, 2, 2, -2, -2};


void entrar_graf()
{
    g = MC(n, vector<char>(m));
    vis = MB(n, vector<bool>(m, false));
    passos = MI(n, vector<int>(m, infinit));
    for (int u = 0; u < n; ++u)
    {
        for (int i = 0; i < m; ++i)
        {
            cin >> g[u][i];
        }
    }
}

bool pos_oky(int x, int y)
{
    return x >= 0 and y >= 0 and x < n and y < m and g[x][y] != 'X';
}

int passos_minims(int x, int y)
{
    
    passos[x][y] = 0;
    queue<Pair> q;
    Pair pos = make_pair(x, y);
    q.push(pos);
    while (not q.empty())
    {
        Pair p = q.front();
        int f = p.first;
        int c = p.second;
        q.pop();
        if (not vis[f][c])
        {
            vis[f][c] = true;
            if (g[f][c] == 'p') return passos[f][c];
            for (int i = 0; i < 8; ++i)
            {
                int nx = f + DI[i];
                int ny = c + DJ[i];
                if (pos_oky(nx, ny) and passos[nx][ny] > passos[f][c] + 1)
                {
                    passos[nx][ny] = passos[f][c] + 1;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
    return -1;
    
}


int main()
{
    while (cin >> n >> m)
    {
        entrar_graf();
        int x, y;
        cin >> x >> y;
        int res = passos_minims(x-1, y-1);
        if (res == -1) cout << "no" << endl;
        else cout << res << endl;
    }
}
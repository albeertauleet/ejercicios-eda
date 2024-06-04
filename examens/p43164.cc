#include <iostream>
#include <vector>
#include <limits>
using namespace std;

typedef vector<vector<char>> MC;
typedef vector<vector<bool>> MB;
typedef vector<vector<int>>  MI;
typedef pair<int, int> Pair;


MC g;
MB vis;
MI dis;
int n, m;
Pair pos_m;
Pair pos_sm;
const int infinit = numeric_limits<int>::max();
const int DI[] = {0, 1, 0, -1};
const int DJ[] = {1, 0, -1, 0};


void entrar_graf()
{
    for (int u = 0; u < n; ++u)
    {
        for (int o = 0; o < m; ++o)
        {
            cin >> g[u][o]; 
        }
    }
}

bool pos_oky(int x, int y)
{
    return x >= 0 and y >= 0 and x < n and y < m and g[x][y] != 'X';
}

#include <queue>

void segon_tresor(int x, int y, int& maxim, int& segon_max)
{
    queue<Pair> q;
    q.push(make_pair(x, y));
    while (not q.empty())
    {
        Pair p = q.front();
        q.pop();
        int x = p.first;
        int y = p.second;
        if (not vis[x][y]) 
        {
            vis[x][y] = true;
            if (g[x][y] == 't')
            {
                if (dis[x][y] > maxim)
                {
                    segon_max = maxim;
                    pos_sm = pos_m;
                    maxim = dis[x][y];
                    pos_m = make_pair(x, y);
                }
                else if (dis[x][y] <= maxim and dis[x][y] > segon_max)
                {
                    segon_max = dis[x][y];
                    pos_sm = make_pair(x, y);
                }
            }
            for (int i = 0; i < 4; ++i)
            {
                int nx = x + DI[i];
                int ny = y + DJ[i];
                if (pos_oky(nx, ny) and dis[nx][ny] > dis[x][y] + 1)
                {
                    dis[nx][ny] = dis[x][y] + 1;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
}

int main()
{
    
    cin >> n >> m;
    g = MC(n, vector<char>(m));
    vis = MB(n, vector<bool>(m, false));
    dis = MI(n, vector<int>(m, infinit));
    entrar_graf();
    int maxim, segon_max;
    maxim = -1;
    segon_max = -1;
    int x, y;
    cin >> x >> y;
    dis[x-1][y-1] = 0;
    segon_tresor(x-1, y-1, maxim, segon_max);
    if (segon_max != -1) cout << "segona distancia maxima: " << dis[pos_sm.first][pos_sm.second] << endl;
    else cout << "no es pot arribar a dos o mes tresors" << endl;
    
}
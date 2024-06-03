#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <map>

using namespace std;

typedef vector<vector<char>> Graph;

int pos_x;
int pos_y;

const int DI[] = {0, 0, 1, -1, -1, -1, 1, 1 };
const int DJ[] = {1, -1, 0, 0, 1, -1, 1, -1 };


bool pos_oky(int x, int y, int n, int m)
{
    return x >= 0 and y >= 0 and x < n and y < m;
}

void entrar_graf(Graph& g, int n, int m)
{
    g = Graph(n, vector<char>(m));
    char c;
    for (int i = 0; i < n; ++i)
    {
        for (int u = 0; u < m; ++u)
        {
            cin >> c;
            g[i][u] = c;
            if (c == 'K')
            {
                pos_x = i;
                pos_y = u;
            }
        }
    }
}

void print_cami(map<pair<int,int>,pair<int, int>>& cami,  int x, int y)
{
    
    list<pair<int, int>> cami_be;
    pair<int, int> final = make_pair(x, y);
    cami_be.push_front(final);
    pair<int,int> pos = cami[final];
    while (pos.first != -1)
    {
        cami_be.push_front(pos);
        pos = cami[pos];
    }
    cout << cami_be.size();
    for (list<pair<int, int>>::const_iterator it = cami_be.begin(); it != cami_be.end(); ++it)
    {
        cout << "  " << (*it).first << " " << (*it).second;
    }
    cout << endl;
    

}

void cami_minim(const Graph& g, int n, int m)
{
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    queue<pair<int, int>> q;
    map<pair<int,int>, pair<int,int>> cami;

    pair<int, int> start = make_pair(pos_x, pos_y);
    q.push(start);
    cami[start] = {-1, -1};
    vis[pos_x][pos_y] = true;

    while (not q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (g[x][y] == 'F')
        {
            print_cami(cami, x, y);
            return;
        }

        for (int i = 0; i< 8; ++i)
        {
            int nx = x + DI[i];
            int ny = y + DJ[i];
            if (pos_oky(nx, ny, n, m) and not vis[nx][ny] and  g[nx][ny] != 'X')
            {
                pair<int, int> pos = make_pair(nx, ny);
                q.push(pos);
                cami[pos] = make_pair(x, y);
                vis[nx][ny] = true;
            }
        }
    }
    cout << 0 << endl;
}

int main()
{
    int n, m;
    while (cin >> n >> m)
    {
        Graph g;
        entrar_graf(g, n, m);
        cami_minim(g, n, m);
    }
}
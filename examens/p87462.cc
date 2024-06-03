#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<char>> Graph;

int pos_f;
int pos_c;
int f;
int c;

const int DI[] = {1, 0, -1, 0};
const int DJ[] = {0, 1, 0, -1};

const int CI[] = {0, 0, 1, -1, 1, 1, -1, -1};
const int CD[] = {1, -1, 0, 0, 1, -1, 1, -1};

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
            if (c == 'P')
            {
                pos_f = i;
                pos_c = u;
            }
        }
    }
}

bool pos_oky(const Graph& g, int files, int columnes)
{
    if (files >= 0 and columnes >= 0 and files < f and columnes < c)
    {
        for (int i = 0; i < 8; ++i)
        {
            int nx = files + CI[i];
            int ny = columnes + CD[i];
            if ((nx >= 0 and ny >= 0 and nx < f and ny < c) and g[nx][ny] == 'F') return false;
        }
        return true;
    }
    else return false;
}

void pot_bolet(const Graph& g, int fi, int co, vector<vector<bool>>& vis, bool& pot)
{
    if (not vis[fi][co])
    {
        vis[fi][co] = true;
        char x = g[fi][co];
        if (x != 'X')
        {
            if (x == 'B') 
            {
                pot = true;
                return;
            }
            else 
            {
                for (int i = 0; i < 4; ++i)
                {
                    int nx = fi + DI[i];
                    int ny = co + DJ[i];
                    if (pos_oky(g, nx, ny)) pot_bolet(g, nx, ny, vis, pot);
                }
            }
        }
    }
}

int main()
{
    
    //int f, c;
    while (cin >> f >> c)
    {
        Graph g;
        entrar_graf(g, f, c);
        vector<vector<bool>> vis(f, vector<bool>(c, false));
        bool pot = false;
        if (pos_oky(g, pos_f, pos_c)) pot_bolet(g, pos_f, pos_c, vis, pot);
        if (pot) cout << "si" << endl;
        else cout << "no" << endl;
    }
}

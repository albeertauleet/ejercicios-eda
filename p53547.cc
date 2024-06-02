// Me pasa el público, pero el privado me da WA

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int files;
int columnes;
int num_bishops;
int num_caselles;
int num_per_casella;

const int DI[] = {-1, -1, 1, 1};
const int DJ[] = {-1, 1, -1, 1};

bool oky(int x, int y)
{
    return x >= 0 and x < files and y >= 0 and y < columnes;
}

void entrar_graf(vector<vector<string>>& matriu, int n, int m)
{
    files = n;
    columnes = m;
    num_bishops = 0;
    num_caselles = 0;
    num_per_casella = 0;
    for (int u = 0; u < n; ++u)
    {
        for(int k = 0; k < m; ++k)
        {
            string c;
            cin >> c;
            matriu[u][k] = c;
            if (c != "X")
            {
                ++num_caselles;
                num_bishops += stoi(c);
            }
        }
    }
    if (num_caselles > 0) num_per_casella = num_bishops / num_caselles;
}

void bfs(const vector<vector<string>>& matriu, vector<vector<bool>>& vis, int x, int y, int& num_sobrant, int& num_pendent)
{
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    while (not q.empty())
    {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; ++i)
        {
            int nx = x + DI[i];
            int ny = y + DJ[i];
            if (oky(nx, ny) and matriu[nx][ny] != "X" and not vis[nx][ny])
            {
                vis[nx][ny] = true;
                int num = stoi(matriu[nx][ny]);
                if (num > num_per_casella) num_sobrant += num - num_per_casella;
                else if (num < num_per_casella) num_pendent += num_per_casella - num;
                q.push(make_pair(nx, ny));
            }
        }
    }
}


bool es_possible(const vector<vector<string>>& matriu, vector<vector<bool>> vis)
{
    
    for (int i = 0; i < files; ++i)
    {
        for (int j = 0; j < columnes; ++j)
        {
            if (not vis[i][j] and matriu[i][j] != "X")
            {
                //vis[i][j] = true;
                int num_sobrant = 0;
                int num_pendent = 0;
                bfs(matriu, vis, i, j, num_sobrant, num_pendent);
                if (num_pendent != num_sobrant) return false;
            }
        }
    }
    return true;
}


int main() 
{
    int t;
    cin >> t; 
    for (int i = 0; i < t; ++i)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<string>> matriu(n, vector<string>(m));
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        entrar_graf(matriu, n, m);
        if (es_possible(matriu, vis)) cout << "Case " << i+1 << ": yes" << endl;
        else cout << "Case " << i+1 << ": no" << endl;
    }
}

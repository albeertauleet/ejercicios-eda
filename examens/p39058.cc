#include <iostream>
#include <vector> 
#include<queue>
using namespace std;

typedef vector<vector<char>> MC;
typedef vector<vector<bool>> MB;

const int DI[] = {2, 1, 1, -2, -1, -1, -2, 2};
const int DJ[] = { 1, 2, -2, -1, -2, 2, 1, -1};
int n, m, pos_n, pos_m;
MC g;
MB vis;

void entrar_graf()
{
    char c;
    for (int u = 0; u < n; ++u)
    {
        for (int o = 0; o < m; ++o)
        {
            
            cin >> c;
            g[u][o] = c;
            if (c == 'C')
            {
                pos_n = u;
                pos_m = o;
            }
            
        }
    }
}

void print (const vector<int>& num_salts)
{
    if (num_salts.size() > 0) 
    {
        double suma = 0.0;
        cout << "flors accessibles: " << num_salts.size() << endl;
        for (int i = 0; i < num_salts.size(); ++i)
        {
            suma += num_salts[i];
        }
        cout << "distancia mitjana: " << suma/num_salts.size() << endl;
    }
    else cout << "el cavall no pot arribar a cap flor" << endl;
}


bool pos_oky(int x, int y)
{
    return x >= 0 and y >= 0 and x < n and y < m and g[x][y] != 'a';
}

#include <queue>

void flors_accessibles(int x, int y, vector<int>& num_salts)
{
    queue<pair<int, pair<int, int>>> q;
    q.push({0, {x, y}});
    while (not q.empty())
    {
        int n_ite = q.front().first;
        int x = q.front().second.first;
        int y = q.front().second.second;
        q.pop();
        if (not vis[x][y])
        {
            vis[x][y] = true;
            if (g[x][y] == 'F')
            {
                num_salts.push_back(n_ite);
            }
            for (int i = 0; i < 8; ++i)
            {
                int nx = x + DI[i];
                int ny = y + DJ[i];
                if (pos_oky(nx, ny)) q.push({n_ite+1, {nx, ny}});
            }
        }
    }
}

int main()
{
    cout.setf(ios::fixed);
    cout.precision(4);
    cin >> n >> m;
    g = MC(n, vector<char> (m));
    vis = MB(n, vector<bool>(m, false));
    vector<int> num_salts;
    entrar_graf();
    flors_accessibles(pos_n, pos_m, num_salts);
    print(num_salts);


}
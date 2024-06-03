#include <iostream>
#include <vector>

using namespace std;

int n;
vector<bool> files;
vector<bool> columnes;
vector<bool> d1;
vector<bool> d2;
vector<vector<char>> tauler;
bool parar;

void print_tauler()
{
    for (int i = 0; i < n; ++i)
    {
        for (int u = 0; u < n; ++u)
        {
            cout << tauler[i][u];
        }
        cout << endl;
    }
    
}

void colocar_reines(int f)
{
    if (f >= n)
    {
        print_tauler();
        parar = true;
    }
    else
    {
        for (int c = 0; c < n; ++c)
        {
            if (not files[f] and not columnes[c] and not d1[f+c] and not d2[n-1+c-f])
            {
                files[f] = true;
                columnes[c] = true;
                d1[f+c] = true;
                d2[n-1+c-f] = true;
                tauler[f][c] = 'Q';
                colocar_reines(f+1);
                if (not parar)
                {
                    tauler[f][c] = '.';
                    files[f] = false;
                    columnes[c] = false;
                    d1[f+c] = false;
                    d2[n-1+c-f] = false;
                }

            }
        }
        

    }
    
}

int main()
{
    cin >> n;
    files = vector<bool>(n, false);
    columnes = vector<bool>(n, false);
    d1 = vector<bool>(n*2 - 1, false);
    d2 = vector<bool> (n*2 - 1, false);
    parar = false;
    tauler = vector<vector<char>>(n, vector<char>(n, '.'));
    colocar_reines(0);
    if (not parar) cout << "NO SOLUTION" << endl; 

}

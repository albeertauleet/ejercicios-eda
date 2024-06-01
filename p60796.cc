#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INFINITY = numeric_limits<int>::max();

typedef vector<char> VC;
typedef vector<VC> MC;
typedef vector<int> VB;
typedef vector<VB> MB;

int tamany_files;
int tamany_columnes;

const int N_DIRS = 4;
const int DI[N_DIRS] = {1, 0, -1, 0};
const int DJ[N_DIRS] = {0, 1,  0, -1};

bool oky(int i, int j) 
{
    if (i >= tamany_files) return false;
    if (j >= tamany_columnes) return false;
    if (i < 0) return false;
    if (j < 0) return false;
    return true;
}

int bfs(MC graf, MB dist, int f, int c) 
{
    queue<pair<int,int>> q;
    q.push(make_pair(f, c));
    dist[f][c] = 0;
    bool trobat = false;
    int d_def; 
    int f_oky;
    int c_oky;
    while (not q.empty() and not trobat)
    {
        
        for (int i = 0; i < N_DIRS; ++i)
        {
            f_oky = q.front().first + DI[i];
            c_oky = q.front().second + DJ[i];
            
            if (oky(f_oky, c_oky) and graf[f_oky][c_oky] != 'X')
            {
                if (dist[f_oky][c_oky] == INFINITY)
                {
                    dist[f_oky][c_oky] = dist[q.front().first][q.front().second] + 1;
                    q.push(make_pair(f_oky,c_oky));
                    if (graf[f_oky][c_oky] == 't') 
                    {
                        trobat = true;
                        d_def = dist[f_oky][c_oky];
                    }    
                }
        

            }
        }
        q.pop();
    }
    if (trobat) return d_def;
    else return -1;
}


int main()
{
    int files, columnes;
    cin >> files >> columnes;
    tamany_files= files;
    tamany_columnes = columnes;
    MC matriu(files, VC(columnes));
    for (int i = 0; i < files; ++i)
    {
        for (int j = 0; j < columnes; ++j)
        cin >> matriu[i][j];
    }
    MB dist(files, VB(columnes, INFINITY));
    int f, c;
    cin >> f >> c;
    int d = bfs(matriu, dist, f - 1, c - 1);
    if (d == -1) cout << "no es pot arribar a cap tresor" << endl;
    else cout << "distancia minima: " << d << endl;
}
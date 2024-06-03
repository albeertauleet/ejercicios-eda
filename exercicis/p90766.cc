#include <iostream>
#include <vector>
using namespace std;

typedef vector<char> VC;
typedef vector<VC> MC;
typedef vector<bool> VB;
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

void dfs_rec(MC& matriu, MB& boolea, int f, int c, int& contador)
{
    if (not boolea[f][c])
    {
        boolea[f][c] = true;
        if (matriu[f][c] == 't') ++contador;
        

        for (int y = 0; y < 4; ++y)
        {
            int ii = f + DI[y];
            int ij = c + DJ[y];
            if (oky(ii,ij) and matriu[ii][ij] != 'X')  dfs_rec(matriu, boolea, ii, ij, contador);
        }
        
    }
    
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
    MB m_bool(files, VB(columnes, false));
    
    int contador = 0;
    int f, c;
    cin >> f >> c;
    dfs_rec(matriu, m_bool, f - 1, c - 1, contador);
    cout << contador << endl;
    
}


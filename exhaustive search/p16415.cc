#include <iostream>
#include <vector>

using namespace std;

vector<bool> files;
vector<bool> columnes;
vector<bool> d1;
vector<bool> d2;

int colocar_reines(int f)
{
    if (f >= files.size()) 
    {
        return 1;
    }
    else 
    {
        int suma = 0;
        for (int i = 0; i < columnes.size(); ++i)
        {
            if (not files[f] and not columnes[i] and not d1[f+i] and not d2[files.size()-1+i-f])
            {
                files[f] = true;
                columnes[i] = true;
                d1[f+i] = true;
                d2[files.size()-1+i-f] = true;
                suma += colocar_reines(f+1);
                files[f] = false;
                columnes[i] = false;
                d1[f+i] = false;
                d2[files.size()-1+i-f] = false;
            }
        }
        return suma;
    }
}

int main()
{
    int n;
    cin >> n;
    files = vector<bool>(n, false);
    columnes = vector<bool>(n, false);
    d1 = vector<bool>(n*2 - 1, false);
    d2  = vector<bool>(n*2 - 1, false);
    cout << colocar_reines(0) << endl;
}
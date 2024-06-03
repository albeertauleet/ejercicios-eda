#include <iostream>
#include <vector>
#include <limits>
#include <map>

using namespace std;

const int infinit = numeric_limits<int>::max();
int n;
int mini;
map<int, string> llista;
vector<string> opcio;
vector<string> resultat;
vector<bool> vis;
vector<vector<int>> manies;

void imprimir_llista()
{
    cout << mini <<  endl;
    bool primer = true;
    for (int i = 0; i < n; ++i)
    {
        if (primer)
        {
            primer = false;
            cout << resultat[i];
        }
        else
        {
            cout << " " << resultat[i];
        }
    }
    cout << endl;
}

void entrar_llista()
{
    string s;
    for (int i = 0; i < n; ++i)
    {
        cin >> s;
        llista[i] = s;
    }
    int num;
    for (int u = 0; u < n; ++u)
    {
        for (int o = 0; o < n; ++o)
        {
            cin >> num;
            manies[u][o] = num;
        }
    }
}

void guardar_llista()
{
    for (int i = 0; i < n; ++i)
    {
        resultat[i] = opcio[i];
    }
}

void dispo_optima(int c, int& suma, int actual)
{
    if (c == n)
    {
        if (mini > suma) 
        {
            mini = suma;
            resultat = opcio;
        }
        
    }
    else if (suma < mini)
    {
        for (int u = 1; u < n; ++u)
        {
            if (not vis[u])  
            {
                vis[u] = true;
                suma += manies[u][actual];
                opcio[c] = llista[u];
                dispo_optima(c+1, suma, u);
                suma -= manies[u][actual];
                vis[u] = false;
                
            }
        }
    }
}


int main()
{
    while (cin >> n)
    {
        mini = infinit;
        vis = vector<bool>(n, false);
        manies = vector<vector<int>>(n, vector<int>(n));
        opcio = vector<string>(n, ""); 
        resultat = vector<string>(n);  
        entrar_llista();
        opcio[0] = llista[0];
        int suma = 0;
        dispo_optima(1, suma, 0);
        imprimir_llista();
    }
}
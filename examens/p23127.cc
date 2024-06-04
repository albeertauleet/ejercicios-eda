#include <iostream>
#include <map>
using namespace std;


int n, m;
map <string, string> propostes;
map <pair<string, string>, bool> vots;
map <string, int> persones;
map <string, pair<int, int>> recompte_propostes;

void entrar_propostes()
{
    string nom;
    string proposta;
    propostes = map <string, string>();
    vots = map <pair<string, string>, bool>();
    persones = map <string, int>();
    recompte_propostes = map <string, pair<int, int>> ();
    for (int i = 0; i < n; ++i)
    {
        cin >> nom >> proposta;
        persones[nom] = i;
        propostes[proposta] = nom;
        recompte_propostes[proposta] = make_pair(0,0);
    }
}

void entrar_vots()
{
    string nom, vot, proposta;
    for (int i = 0; i < m; ++i)
    {
        cin >> nom >> vot >> proposta;
        pair<string, string> vota = make_pair(nom, proposta);
        if (vot == "SI") 
        {
            vots[vota] = true;
        }
        else
        {
            vots[vota] = false;
        }
    }
}

void recompte_vots()
{
    for (map<pair<string, string>, bool>::const_iterator it = vots.begin(); it != vots.end(); ++it)
    {
        string proposta_votada = (*it).first.second;
        bool a_favor = (*it).second;
        if (a_favor) ++recompte_propostes[proposta_votada].first;
        else ++recompte_propostes[proposta_votada].second;

    }
    for (map<string, pair<int, int>>::const_iterator it = recompte_propostes.begin(); it != recompte_propostes.end(); ++it)
    {
        int vots_a_favor = (*it).second.first;
        int vots_en_contra = (*it).second.second;
        if (vots_a_favor != vots_en_contra)
        {
            if (vots_a_favor > vots_en_contra)
            {
                cout << (*it).first << ", de " <<  propostes[(*it).first] << ", que ha guanyat " << vots_a_favor << "-" << vots_en_contra << endl; 
            }

        }
    }
}

int main()
{
    while (cin >> n)
    {
        entrar_propostes();
        cin >> m;
        entrar_vots();
        recompte_vots();
        cout << "----------" << endl;
        
    }
}
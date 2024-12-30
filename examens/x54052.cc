#include <iostream>
#include <vector>

using namespace std;

void llegir_cadenes(vector<char>& p, vector<char>& s, int n, bool& parar)
{
    for (int i = 0; i < n; ++i)
    {
        cin >> p[i];
    }
    for (int u = 0; u < n; ++u)
    {
        cin >> s[u];
    }
    
    for (int j = 0; j < n; ++j)
    {
        if (p[j] == 'T')
        {
            if (s[j] == 'T' or s[j] == 'G' or s[j] == 'C') parar = true;
        }
        else if (p[j] == 'A')
        {
            if (s[j] == 'C' or s[j] == 'G' or s[j] == 'A') parar = true;
        }
        else if (p[j] == 'G')
        {
            if (s[j] == 'T' or s[j] == 'G' or s[j] == 'A') parar = true;
        }
        else if (p[j] == 'C')
        {
            if (s[j] == 'T' or s[j] == 'C' or s[j] == 'A') parar = true;
        }

    }
}

void print(const vector<char>& p, const vector<char>& s)
{
    for (int i = 0; i < p.size(); ++i)
    {
        cout << p[i];
    }
    cout << endl;
    for (int u = 0; u < s.size(); ++u)
    {
        cout << s[u];
    }
    cout << endl;
    cout << endl;
}

void imprimir_cadenes(int idx, vector<char>& p, vector<char>& s)
{
    if (idx == p.size())
    {
        print(p, s);
    }
    else
    {
        if (p[idx] != '.' or s[idx] != '.')
        {
            if (p[idx] == 'A')
            {
                s[idx] = 'T';
                imprimir_cadenes(idx+1, p, s);
            }
            else if (p[idx] == 'T')
            {
                s[idx] = 'A';
                imprimir_cadenes(idx+1, p, s);
            }
            else if (s[idx] == 'A')
            {
                p[idx] = 'T';
                imprimir_cadenes(idx+1, p, s);
            }
            else if (s[idx] == 'T')
            {
                p[idx] = 'A';
                imprimir_cadenes(idx+1, p, s);
            }
            else if (p[idx] == 'G')
            {
                s[idx] = 'C';
                imprimir_cadenes(idx+1, p, s);
            }
            else if (p[idx] == 'C')
            {
                s[idx] = 'G';
                imprimir_cadenes(idx+1, p, s);
            }
            else if (s[idx] == 'G')
            {
                p[idx] = 'C';
                imprimir_cadenes(idx+1, p, s);
            }
            else if (s[idx] == 'C')
            {
                p[idx] = 'G';
                imprimir_cadenes(idx+1, p, s);
            }

        }
        else 
        {
            p[idx] = 'A';
            s[idx] = 'T';
            imprimir_cadenes(idx+1, p, s);
            p[idx] = '.';
            s[idx] = '.';

            p[idx]= 'C';
            s[idx] = 'G';
            imprimir_cadenes(idx+1, p, s);
            p[idx] = '.';
            s[idx] = '.';

            p[idx] = 'G';
            s[idx] = 'C';
            imprimir_cadenes(idx+1, p, s);
            p[idx] = '.';
            s[idx] = '.';

            p[idx]= 'T';
            s[idx] = 'A';
            imprimir_cadenes(idx+1, p, s);
            p[idx] = '.';
            s[idx] = '.';


        }
    }
}


int main()
{
    int n;
    while (cin >> n)
    {
        vector<char> primera(n);
        vector<char> segona(n);
        bool parar = false;
        llegir_cadenes(primera, segona, n, parar);
        if (not parar) imprimir_cadenes(0, primera, segona);
        cout << "----------" << endl;
    }
    
}

#include <iostream>
#include <vector>
using namespace std;

vector<string> combi;
vector<string> paraules;
vector<bool> utilitzat;
int n;


void entrar_paraules()
{
    paraules = vector<string>(n);
    combi = vector<string>(n);
    utilitzat = vector<bool>(n, false);
    for (int i = 0; i < n; ++i)
    {
        cin >> paraules[i];
    }

}

void print()
{
    for (int i = 0; i < n; ++i)
    {
        cout << combi[i];
    }
    cout << endl;
}

void possibles_combis(int idx)
{
    if (idx == n)
    {
        print();
    }
    else
    {
        for (int i = 0; i < n; ++i)
        {
            string s = combi[idx-1];
            if (not utilitzat[i] and (idx == 0 or s[s.size()-1] != paraules[i][0]))
            {
                combi[idx] = paraules[i];
                utilitzat[i] = true;
                possibles_combis(idx + 1);
                combi[idx] = "";
                utilitzat[i] = false;
            }
        }
    }
}

int main()
{
    cin >> n;
    entrar_paraules();
    combi = vector<string>(n, "");
    int idx = 0;
    possibles_combis(idx);
    
}
#include <iostream>
#include <vector>

using namespace std;
int n;
vector<string> s;
vector<string> permu;
vector<bool> utilitzat;

void entrar_vector()
{
    string paraula;
    for (int i = 0; i < n; ++i)
    {
        cin >> paraula;
        s.push_back(paraula);
        utilitzat[i] = false;
    }
}

void print_vector()
{
    bool primer = true;
    for (int i = 0; i < permu.size(); ++i)
    {
        if (primer)
        {
            primer = false;
            cout << "(" << permu[i];
        }
        else 
        {
            cout << "," << permu[i];
        }
    }
    cout << ")" << endl;

}

void permutacio(int c)
{
    if (c >= n)
    {
        print_vector();
    }
    else
    {
        for (int i = 0; i < n; ++i)
        {
            if (not utilitzat[i])
            {
                permu[c] = s[i];
                utilitzat[i] = true;
                permutacio(c+1);
                utilitzat[i] = false;
            }
        }
    }
}

int main()
{
    cin >> n;
    permu = vector<string>(n);
    utilitzat = vector<bool>(n, false);
    entrar_vector();
    permutacio(0);
}
#include <iostream>
#include <vector>

using namespace std;

void print_vector(const vector<int>& combi)
{
    bool primer = true;
    for (int i = 0; i < combi.size(); ++i)
    {
        if (primer)
        {
            primer = false;
            cout << combi[i];
        }
        else cout << " " << combi[i];
    }
    cout << endl;
}

void dos_uns(vector<int>& combi, int u, int idx, int num_uns, int num_ceros)
{
    if (idx == combi.size())
    {
        print_vector(combi);    
    }

    else 
    { 
        if (num_ceros > 0)
        {
            combi[idx] = 0;
            dos_uns(combi, u, idx+1, num_uns, num_ceros-1);
        }
        if (num_uns > 0)
        {
            combi[idx] = 1;
            dos_uns(combi, u, idx+1, num_uns-1, num_ceros);
        }
 
    }
    
}

int main()
{
    int n, u;
    cin >> n >> u;
    int idx = 0;
    vector<int> combi(n, 0);
    dos_uns(combi, u, idx, u, n-u);
}

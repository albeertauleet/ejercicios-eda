#include <iostream>
#include <vector>
using namespace std;

typedef vector<char> VC;

int n, m;
VC combi;


void print(const vector<char>& combi)
{
    for (int i = 0; i < combi.size(); ++i)
    {
        cout << combi[i];
    }
    cout << endl;
}

void possibles_combis(int idx, int m, int n_x, int n_y, int n_z)
{
    if (idx == n)
    {
        print(combi);
    }
    else
    {
        if (n_x < m or combi[idx-1] != 'x')
        {
            combi[idx] = 'x';
            if(combi[idx-1] != 'x') n_x = 0;
            possibles_combis(idx+1, m, n_x+1, n_y, n_z);
            combi[idx] = '.';
            --n_x;
        }
        if (n_y < m or combi[idx-1] != 'y')
        {
            combi[idx] = 'y';
            if(combi[idx-1] != 'y') n_y = 0;
            possibles_combis(idx+1, m, n_x, n_y+1, n_z);
            combi[idx] = '.';
            --n_y;
        }
        if (n_z < m or combi[idx-1] != 'z')
        {
            combi[idx] = 'z';
            if(combi[idx-1] != 'z') n_z = 0;
            possibles_combis(idx+1, m, n_x, n_y, n_z+1);
            combi[idx] = '.';
            --n_z;
        }
        
    }
}

int main()
{
    while (cin >> n >> m)
    {
        combi = VC(n);
        int idx = 0;
        possibles_combis(idx, m, 0, 0, 0);
        cout << "--------------------" << endl;
    }
}
#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

void escriu(int x, int n, vector<int>& sol, vector<int>& m)
{
    cout << x << " = ";
    bool primer = true;
    for (int i = 0; i < 2*n; ++i)
    {
        if (sol[i] != 0)
        {
            if (primer) primer = false;
            else cout << " + ";
            cout << m[i];
            if (i % 2 == 1) cout << 'p';
        }
        
    }
    cout << endl;

}

void gen(int k, int sp, int x, int n, vector<int>& sol, vector<int>& m)
{
    if (sp > x) return;
    if (k == 2*n)
    {
        if (sp == x) escriu(x, n, sol, m);
    }
    else 
    {
        sol[k] = 1; gen(k+1, sp + m[k], x, n, sol, m);
        sol[k] = 0; gen(k+1, sp, x, n, sol, m);
    }
}

int main()
{
    int x, n;
    while (cin >> x >> n)
    {
        vector<int> m(2*n);
        for(int i = 0; i < 2*n; i += 2)
        {
            cin >> m[i];
            m[i+1] = m[i];
        }
        sort(m.begin(), m.end());
        vector<int> sol (2*n);
        gen(0, 0, x, n, sol, m);
        cout << "----------" << endl;
    }
}
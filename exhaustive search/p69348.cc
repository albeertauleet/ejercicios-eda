#include <iostream>
#include <vector>

using namespace std;



void perm(int k, vector<int>& p, vector<bool>& mkd)
{
    int n = p.size();
    if (k == n) {
        bool first = true;
        for (int x : p) 
        {
            if (first) 
            {
                cout << "(" << x;
                first = false;

            }
            else
            {
                cout << "," << x;
            }
        }

        cout << ")" << endl;
    }
    else
    {
        for (int i = 0; i < n; ++i)
        {
            if (not mkd[i])
            {
                p[k] = i+1;
                mkd[i] = true;
                perm(k+1, p, mkd);
                mkd[i] = false;
            }
        }
    }
}

int main()
{
    int  n;
    cin >> n;
    vector<int> p(n);
    vector<bool> mkd(n, false);
    perm(0, p, mkd);
}
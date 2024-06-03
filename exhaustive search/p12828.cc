#include <iostream>
#include <vector>

using namespace std;

void escriu_tires(int idx, vector<int>& v)
{
    if (idx == int (v.size()))
    {
        bool first = true;
        for (int x : v)
        {
            if(first)
            {
                cout << x;
                first = false;
            }
            else
            {
                cout << " " << x;
            }
        } 
        cout << endl;

    }
    else
    {
        v[idx] = 0;
        escriu_tires(idx+1, v);

        v[idx] = 1;
        escriu_tires(idx+1, v);
    }
}


int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    int idx = 0;
    escriu_tires(idx, v);
}
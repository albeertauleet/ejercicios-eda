#include <iostream>
#include <vector>
using namespace std;

int n;

void print(const vector<int>& v)
{
    for (int i = 0; i < v.size(); ++i)
    {
        cout << v[i];
    }
    cout << endl;
}

void escriu_rosers(int idx, vector<int>& testos, bool& parell, int r1, int r2, int r3)
{
    if (idx == testos.size())
    {
        if (parell) print(testos);
    }
    else 
    {
        
        if (r1 > 0)
        {
            if (idx == 0 or (not parell or (parell and testos[idx-1] != 1)))
            {
                testos[idx] = 1;
                bool parell_antic = parell;
                if (idx > 0  and testos[idx-1] == 1) parell = true;
                escriu_rosers(idx+1, testos, parell, r1-1, r2, r3);
                testos[idx] = 0;
                parell = parell_antic;
            }
            
        }
        if (r2 > 0)
        {
            if (idx == 0 or (not parell or (parell and testos[idx-1] != 2)))
            {
                testos[idx] = 2;
                bool parell_antic = parell;
                if (idx > 0 and testos[idx-1] == 2) parell = true;
                escriu_rosers(idx+1, testos, parell, r1, r2-1, r3);
                testos[idx] = 0;
                parell = parell_antic;
            }
            
        }
        if (r3 > 0)
        {
            if (idx == 0 or (not parell or (parell and testos[idx-1] != 3)))
            {
                testos[idx] = 3;
                bool parell_antic = parell;
                if (idx > 0 and testos[idx-1] == 3) parell = true;
                escriu_rosers(idx+1, testos, parell, r1, r2, r3-1);
                testos[idx] = 0;
                parell = parell_antic;
            }
            
        }
        
    }
}

int main()
{
    while (cin >> n)
    {
        int idx = 0;
        vector<int> testos(3*n);
        bool parell = false;
        escriu_rosers(idx, testos, parell, n, n, n);
        cout << "**********" << endl;
    }
}
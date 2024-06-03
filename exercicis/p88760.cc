#include <iostream>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

typedef vector<vector<double>> Graph;

struct roca
{
    double x;
    double y;
    double r;
};

double distancia(roca r1, roca r2)
{
    return sqrt(pow((r1.x-r2.x),2)+pow((r1.y-r2.y),2))-r1.r-r2.r;
}


int es_pot(vector<roca> roques, double d)
{
    int n = int(roques.size());

    vector<bool> visitats(n, false);
    vector<int> salts(n, 0);
    queue<int> q;
    q.push(0);
    visitats[0] = true;

    while (not q.empty())
    {
        int act = q.front();
        q.pop();
        if (act == n-1) return salts[act];
        else
        {
            for (int i = 0; i < n; ++i)
            {
                if (i != act and not visitats[i])
                {
    
                    if (distancia(roques[act], roques[i]) <= d)
                    {
                        salts[i] = salts[act] + 1;
                        q.push(i);
                        visitats[i] = true;
                    }
                    
                }
            }
        }
    }
    return 0;


}

int main()
{
    int n; 
    double s;
    while (cin >> n >> s)
    {
        vector<roca> roques(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> roques[i].x  >> roques[i].y >> roques[i].r;

        }
        if (es_pot(roques, s) < 1) cout << "Xof!" << endl;
        else cout << es_pot(roques, s) << endl;

    }


}
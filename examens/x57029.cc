#include <iostream>
#include <vector>

using namespace std;

int n;

void print(const vector<char>& trajectoria)
{
    for (int i = 0; i < n; ++i)
    {
        cout << trajectoria[i];
    }
    cout << endl;
}

void possibles_trajectories(vector<char>& trajectoria, int idx, int n_up, int n_h, int n_d)
{
    if (idx == n)
    {
        print(trajectoria);
    }
    else
    {
     
        
        if (n_up > n_d)
        {
            trajectoria[idx] = 'd';
            possibles_trajectories(trajectoria, idx+1, n_up, n_h, n_d+1);

        }

        trajectoria[idx] = 'h';
        possibles_trajectories(trajectoria, idx+1, n_up, n_h+1, n_d);
        

        trajectoria[idx] = 'u';
        possibles_trajectories(trajectoria, idx+1, n_up+1, n_h, n_d);
       
    }
}

int main()
{
    while (cin >> n)
    {
        vector<char> trajectoria(n);
        possibles_trajectories(trajectoria, 0, 0, 0, 0);
    }
}
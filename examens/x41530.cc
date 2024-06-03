#include <iostream>
#include <vector>
using namespace std;

typedef vector< vector<int > > Graph;

void llegir_graf(Graph& g, int n, int m){
    
    g = Graph (n);
    
    int x, y;
    for (int j = 0; j < m; j++) {
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    
}

void es_dirigit (const Graph& g, vector<bool>& visitats, int i, int anterior, bool& cicle) {
    if (!visitats[i]) {
        visitats[i] = true;
        
        for (int j = 0; j < g[i].size(); j++){ // Adjacents de cada node
            if (g[i][j] != anterior){ // Diferent del node de partida
                es_dirigit(g, visitats, g[i][j], i, cicle);
                if (cicle) return;
            }
        }
    }
    
    else cicle = true;
}

void dfs(const Graph& g){
    
    vector<bool> visitats(g.size(), false);
    
    int num_conexos = 0; 
    
    for (int i = 0; i < g.size(); i++){ 
        if (!visitats[i]) {
            bool cicle = false;
            es_dirigit(g, visitats, i, i, cicle);
            
            if (cicle) {
                cout << "no" << endl;
                return;
            }
            
            else ++num_conexos;
        }
    }
    cout << num_conexos << endl;
}

int main(){
    
    int n, m;
    
    while(cin >> n >> m){
        Graph g (n, vector<int> (n,0));
        llegir_graf(g, n, m);
        dfs(g);
    }
    
}
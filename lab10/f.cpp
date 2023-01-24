#include <iostream>
#include <queue>
using namespace std;

int inf = 1e9;
const int MAXN = 200200;

vector <int> g[MAXN];
vector <int> parent(MAXN, 0);

void dfs(int x, int col){
	parent[x] = col;
	for(int i = 0; i < g[x].size(); i++){
		if(!parent[g[x][i]]){
         	dfs(g[x][i], col);
        }
	}
}

int main(){
	int n, m, q, u, v;
	cin >> n >> m;
	for(int i = 1; i <= m; i++){
	 	cin >> u >> v;
	 	g[u].push_back(v);
	 	g[v].push_back(u);
	}

	for(int i = 1; i <= n; i++){
	 	if(!parent[i]){
        	dfs(i, i);
        }
	}


	cin >> u >> v;

	if(parent[u] == parent[v]) cout << "YES";
	else cout << "NO";


    return 0;
}
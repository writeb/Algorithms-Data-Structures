#include <iostream>
#include <queue>
using namespace std;

int Max = 1e9;

vector <int> g[220000];
vector <int> was(220000, Max);

void bfs(int x){
 	queue <int> q;
 	q.push(x);
 	was[x] = 0;
 	while(!q.empty()){
 	 	int v = q.front();
 	 	q.pop();
 	 	for(int i = 0; i < g[v].size(); i++){
 	 	 	if(was[v]+1 < was[g[v][i]]){
 	 	 		was[g[v][i]] = was[v] + 1;
 	 	 		q.push(g[v][i]); 			
 	 	 	}
 	 	}
 	}
}

int main(){
	int n, m, q, a, b;
	cin >> n >> m >> q;
	for(int i = 1; i <= m; i++){
	 	cin >> a >> b;
	 	g[a].push_back(b);
	 	g[b].push_back(a);
	}
	while(q--){
	 	cin >> a >> b;
	 	if(a == 1){
	 	 	bfs(b);
	 	}
	 	else{
	 		cout << (was[b] == Max ? -1 : was[b]) << '\n';
	 	}
	}



    return 0;
}
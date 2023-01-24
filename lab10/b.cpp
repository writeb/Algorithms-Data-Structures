#include <iostream>
#include <queue>
using namespace std;

vector <int> g[200200];
vector <int> was(200200, 0);

void bfs(int x){
 	queue <int> q;
 	q.push(x);
 	was[x] = 1;
 	while(!q.empty()){
 	 	int v = q.front();
 	 	q.pop();
 	 	for(int i = 0; i < g[v].size(); i++){
 	 	 	if(!was[g[v][i]]){
 	 	 		was[g[v][i]] = was[v] + 1;
 	 	 		q.push(g[v][i]); 			
 	 	 	}
 	 	}
 	}
}

int main(){
	int n, x;
	cin >> n;

	for(int i = 1; i <= n; i++){
	 	for(int j = 1; j <= n; j++){
	 	 	cin >> x;
	 	 	if(x == 1){
	 	 	 	g[i].push_back(j);	
	 	 	}
	 	}
	}
	int b, c;
	cin >> b >> c;
	bfs(b);
	cout << was[c]-1;

    return 0;
}
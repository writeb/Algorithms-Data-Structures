#include <iostream>
#include <queue>
using namespace std;

vector <int> g[200200];
vector <int> was(550);
int u, v;
bool flag;

void dfs(int val){
 	was[val] = 1;

 	for(int i : g[val]){
 		if(val == u && i == v) continue;
 		if(was[i] == 0) dfs(i);
 	 	if(was[i] == 1){
 	 	 	flag = 0;
 	 	 	return;		
 	 	}
 	}

 	was[val] = 2;
}



int main(){
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= m; i++){
	 	cin >> u >> v;
	 	g[u].push_back(v);
	}

	for(int i = 1; i <= n; i++){
	 	for(int j : g[i]){
	 		u = i; v = j;
	 		flag = 1;
      	 	fill(was.begin(), was.end(), 0);

			for(int i = 1; i <= n; i++){
				if(!was[i]) dfs(i);
			}
			if(flag)return cout << "YES", 0;
	 	}
	}
	cout << "NO";

    return 0;
}
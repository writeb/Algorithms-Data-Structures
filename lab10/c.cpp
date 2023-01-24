#include <iostream>
#include <queue>
using namespace std;

vector <int> g[220000];
vector <int> was(220000, 0);
vector <int> pr(220000, -1);

void bfs(int x){
 	queue <int> q;
 	q.push(x);
 	was[x] = 1;
 	while(!q.empty()){
 	 	int v = q.front();
 	 	q.pop();
 	 	if(v*2 <= 1e4 && !was[v*2]){
 	 	 	q.push(v*2);
 	 	 	pr[v*2] = v;
 	 	 	was[v*2] = was[v] + 1;
 	 	}
 	 	if(v-1 > 0 && !was[v-1]){
 	 		q.push(v-1);
 	 	 	pr[v-1] = v;
 	 	 	was[v-1] = was[v] + 1; 	
 	 	}
 	}
}

int main(){
	int n, a, b;
	cin >> a >> b;

	bfs(a);

	cout << was[b] - 1 << '\n';
	vector <int> ans;
	while(pr[b] != -1){
	 	ans.push_back(b);
	 	b = pr[b];
	}
	reverse(ans.begin(), ans.end());
	for(int i=0; i<ans.size(); i++) cout << ans[i] << ' ';
    return 0;
    
}
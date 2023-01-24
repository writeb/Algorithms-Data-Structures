#include <iostream>
#include <queue>
using namespace std;

int n, m, a[1000][1000], b[1000][1000];

vector <int> g[200200];
//vector <int> was(200200, 0);

void bfs(queue <pair <int, int> > q){
 	while(!q.empty()){
 	 	pair <int, int> v = q.front();
 	 	q.pop();
 	 	if(b[v.first][v.second] == -1){
 	 	 	b[v.first][v.second] = 0;
 	 	}
 	 	if(v.second-1 >= 0 && b[v.first][v.second-1] == -1 && a[v.first][v.second-1] == 1){
 	 		b[v.first][v.second-1] = b[v.first][v.second] + 1;
 	 		q.push(make_pair(v.first, v.second-1));	
 	 	}
 	 	if(v.second+1 < m && b[v.first][v.second+1] == -1 && a[v.first][v.second+1] == 1){
 	 		b[v.first][v.second+1] = b[v.first][v.second] + 1;
 	 		q.push(make_pair(v.first, v.second+1));	
 	 	}
 	 	if(v.first-1 >= 0 && b[v.first-1][v.second] == -1 && a[v.first-1][v.second] == 1){
 	 		b[v.first-1][v.second] = b[v.first][v.second] + 1;
 	 		q.push(make_pair(v.first-1, v.second));	
 	 	}
 	 	if(v.first+1 < n && b[v.first+1][v.second] == -1 && a[v.first+1][v.second] == 1){
 	 		b[v.first+1][v.second] = b[v.first][v.second] + 1;
 	 		q.push(make_pair(v.first+1, v.second));	
 	 	}
 	}
}

int main(){
	queue <pair <int, int> > q;
	cin >> n >> m;         
	for(int i = 0; i < n; i++){
	 	for(int j = 0; j < m; j++){
	 	 	cin >> a[i][j];
	 	 	if(a[i][j] == 2){
	 	 	 	q.push(make_pair(i, j));
	 	 	}
	 	 	b[i][j] = -1;
	 	}
	}

	bfs(q);
	int mx = 0;
	for(int i = 0; i < n; i++) {
	 	for(int j = 0; j < m; j++){
	 	 	if(a[i][j] == 1 && b[i][j] == -1){
	 	 	 	cout << -1;
	 	 	 	return 0;
	 	 	}
	 	 	if(a[i][j] == 1){
	 	 	 	mx = max(mx, b[i][j]);
	 	 	}
	 	}
	}
	cout << mx;

    return 0;
    
}
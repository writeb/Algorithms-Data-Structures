#include <iostream>
#include <queue>
using namespace std;

int inf = 1e9;
int n, m, q, a, b;
const int MAXN = 200200;

vector <int> g[MAXN];
int parent[1000][1000];
string second[1000];

void dfs(int x, int y, int col){
	parent[x][y] = col;
	if(y+1 < m && !parent[x][y+1] && second[x][y+1] == '1'){
     	dfs(x, y+1, col);
    }
    if(x+1 < n && !parent[x+1][y] && second[x+1][y] == '1'){
     	dfs(x+1, y, col);
    }
    if(y-1 >= 0 && !parent[x][y-1] && second[x][y-1] == '1'){
     	dfs(x, y-1, col);
    }
    if(x-1 >= 0 && !parent[x-1][y] && second[x-1][y] == '1'){
     	dfs(x-1, y, col);
    }
}

int main(){
	cin >> n >> m;
	for(int i = 0; i < n; i++){
	 	cin >> second[i];
	}
	int col = 1;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
		 	if(second[i][j] == '1' && !parent[i][j]){
		 	 	dfs(i, j, col++);
		 	}
		}
	}
	cout << col-1;

    return 0;
}
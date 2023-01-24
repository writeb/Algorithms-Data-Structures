#include <iostream>
#include <queue>
using namespace std;

int a[1005][1005];

int main(){
	int n, t;
	cin >> n >> t;
    //int a[n][n];
	for(int i = 1; i <= n; i++){
	 	for(int j = 1; j <= n; j++){
	 	 	cin >> a[i][j];
	 	}
	}
	int b, c, d;
	for(int i = 1; i <= t; i++){
	 	cin >> b >> c >> d;
	 	if(a[b][c] == 1 && a[b][d] == 1 && a[c][d] == 1) cout << "YES\n";
        else cout << "NO\n";
	}
    return 0;
    
}
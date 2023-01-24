#include <iostream>
#include <queue>
using namespace std;

#define ll long long

ll n, m;
vector<ll> gr[100100];
ll parent[100100];
ll num[100100];

void bfs(ll u){
    queue<ll> que;
    que.push(u);
    parent[u] = u;
    
    while(!que.empty()){
        ll cc = que.front();
        que.pop();
        for(ll i : gr[cc]){
            if (!parent[i]){
                parent[i] = cc;
                num[cc]++;
                que.push(i);
            }
        }
    }
}

int main(){
    cin >> n >> m;
    for(ll i = 0; i < m; i++){
        ll u, v;
        cin >> u >> v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }

    ll cnt = 0;
    for(ll  i = 1; i <= n; i++){
        if (!parent[i]) {
            bfs(i);
        }
    }

    for(ll i = 1; i <= n; i++){
        if (parent[i] != i){
            if (num[i] > num[parent[i]]) {
                cnt++;
            }
        }
        else cnt++;
    }

    cout << cnt;
    return 0;
}
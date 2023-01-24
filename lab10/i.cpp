#include <iostream>
#include <queue>
using namespace std;

#define ll long long
const int MAXN = 200200;

ll n, m;
vector<ll> gr[MAXN];
ll color[MAXN];
vector<ll> topp;

bool dfs(ll x){
    color[x] = 1;
    for(ll i : gr[x]){
        if(!color[i]) {
            if (dfs(i)) return true;
        }
        else if (color[i] == 1) return true;
    }
    color[x] = -1;
    topp.push_back(x);
    return false;
}

int main(){
    cin >> n >> m;
    for(ll i = 0; i < m; i++){
        ll a, b;
        cin >> a >> b;
        gr[a-1].push_back(b-1);
    }
    bool is_ans = false;
    for(ll i = 0; i < (n); i++) {
        if (!color[i]) {
            if (dfs(i)) {
                is_ans = true;
            }
        }
    }
    if(is_ans) cout << "Impossible";
    else{
        cout << "Possible" << '\n';
        topp = vector<ll>(topp.rbegin(), topp.rend());
        for(ll i : topp) cout << i+1 << ' ';
    }
    return 0;
}
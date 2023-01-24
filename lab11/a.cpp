#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, pair<int, int> > > edges;
vector<int> root;
long long ans = 0;

int parent(int v){
    if(v == root[v]){
        return v;
    }
    return root[v] = parent(root[v]);
}

int union_find(int a, int b, int cost){
    int d = parent(a);
    int e = parent(b);

    if(d != e){
        root[d] = e;
        ans += cost;
    }

    return d;

}

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        root.push_back(i);
    }

    for(int i = 0; i < m; i++){
        int l, r, c;
        cin >> l >> r >> c;
        l--;
        r--;

        edges.push_back(make_pair(c, make_pair(l, r)));
    }

    sort(edges.begin(), edges.end());

    for(int i = 0; i < m; i++){
        int l = edges[i].second.first;
        int r = edges[i].second.second;
        int cost = edges[i].first;

        for(int j = l+1; j <= r; j++){
            j = union_find(l, j, cost);
            if(j > r){
                break;
            }
        }

    }
    cout << ans;

}
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int, int> pii;
static const int MX_SIZE = 200200;

struct DSU{
    int parent[MX_SIZE];
    int sz[MX_SIZE];

    void build() {
        for(int i = 1; i < MX_SIZE; i++) {
            parent[i] = i;
            sz[i] = 1;
        }
    }

    int find(int x) {
        if(parent[x] == x) return parent[x];

        parent[x] = find(parent[x]);
        return parent[x];
    }

    void merge(int x, int y) {
        x = find(x); y = find(y);
        if(sz[y] > sz[x]) {
            swap(y, x);
        }
        sz[x] += sz[y];
        parent[y] = x;
    }
};

vector<int> g[(int)2e5 + 1234];

void update(int &total, int &cur){
    total = total - (cur - 1);
}

int main() {
    DSU dsu;
    dsu.build();

    int n;
    cin >> n;
    int q;
    cin >> q;
    while(q--) {
        int v, u;
        cin >> v >> u;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    int total = 0;
    vector<int> a;
    a.push_back(0);
    for(int i = n - 1; i >= 1; --i) {
        int cur = 0;
        int y = i + 1;
        for(int j = 0; j < g[y].size(); ++j) {
            int x = g[y][j];
            if(x <= i) continue;

            if(dsu.find(x) != dsu.find(y)) {
                cur++;
                dsu.merge(x, y);
            }
        }   
        update(total, cur);
        a.push_back(total);
    }
    reverse(a.begin(), a.end());
    for(int i=0; i<a.size(); i++) {
        cout<<a[i]<<endl;
    }


    return 0;
}
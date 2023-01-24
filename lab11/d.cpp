#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> pii;


class DSU {
public:
    static const int MX_SIZE = 2000;
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

vector<pair<int, pii> > g;

int main() {
    DSU dsu;
    dsu.build();

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++){
            int cost; cin >> cost;
            g.push_back({cost, {i, j}});
        }
    }
    sort(g.begin(), g.end());

    int total = 0;
    for(int i = 0; i < g.size(); i++) {
        int weight = g[i].first;
        int a = g[i].second.first;
        int b = g[i].second.second;
        if(dsu.find(a) == dsu.find(b)) {
            continue;
        }

        total += weight;
        dsu.merge(a, b);
    }

    cout << total << endl;


    return 0;
}
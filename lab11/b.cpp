#include <iostream>
#include <vector>
#include <algorithm>

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

void read(int *a, int n) {
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
}

void solve() {
    int n; cin >> n;
    int arr[n];
    read(arr, n);
    sort(arr, arr + n);
    long long total = 1ll * (n - 1) * arr[0];
    for(int i = n - 1; i >= 1; i--) {
        total += arr[i];
    }
    cout << total << endl;
}

int main() {
    solve();
    return 0;
}
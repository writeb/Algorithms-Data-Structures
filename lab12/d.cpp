#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 1000500, INF = 1e9;
long long n, m, a, b, c, x;
pair<long long,long long> ar[MAXN];
long long d[MAXN];
bool w[MAXN];

long long dijk(long long second, long long first){
    fill(d, d+n, INF);
    fill(w, w+n, 0);
    d[second] = 0;
    for(long long i = 0; i < n; i++){
        long long v = -1;
        for(long long j = 0; j < n; j++) if (!w[j] && (v == -1 || d[j] < d[v])) v = j;
        if (v == -1 || d[v] == INF) break;
        w[v] = true;
        for(long long j = 0; j < n; j++){
            long long to = j, len = abs(ar[j].first - ar[v].first) + abs(ar[j].second - ar[v].second);
            d[to] = min(d[to], max(d[v], len));
        }
    }
    return d[first];
}

int main(){
    cin >> n;
    for(long long i = 0; i < n; i++){
        cin >> ar[i].first >> ar[i].second;
    }
    cout << dijk(0, n-1);
    return 0;
}
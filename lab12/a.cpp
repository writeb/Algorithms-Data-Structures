#include <iostream>
 
using namespace std;

const long long N = 500+5 , inf = 2e9 + 7;
const long long INF = 1e18 ,   mod = 1e9+7 , P = 6547;

long long a[N][N];
long long mn[N][N];
long long x[N];
long long u[N];
long long n; 

void solving(long long tc) {
 cin >> n;
 for(long long i = 1; i <= n; i ++) {
  for(long long j = 1; j <= n; j ++) {
   cin >> a[i][j];
   mn[i][j] = inf;
  }
 }
 for(long long i = 1; i <= n; i ++) {
  cin >> x[i];
  long long answer = 0;
  for(long long j = 1; j <= i; j ++) {
   mn[x[j]][x[i]] = a[x[j]][x[i]];
   mn[x[i]][x[j]] = a[x[i]][x[j]];
  }
  for(long long k = 1; k <= i; k ++) {
   for(long long t = 1; t <= i; t ++) {
    mn[x[t]][x[i]] = min(mn[x[t]][x[i]] , mn[x[t]][x[k]] + mn[x[k]][x[i]]);
   }
  }
  for(long long k = 1; k <= i; k ++) {
   for(long long t = 1; t <= i; t ++) {
    mn[x[i]][x[t]] = min(mn[x[i]][x[t]] , mn[x[i]][x[k]] + mn[x[k]][x[t]]);
   }
  }
  for(long long k = 1; k <= i; k ++) {
   for(long long t = 1; t <= i; t ++) {
    mn[x[k]][x[t]] = min(mn[x[k]][x[t]] , mn[x[k]][x[i]] + mn[x[i]][x[t]]);
    if(mn[x[k]][x[t]] < inf) {
     answer = max(answer, mn[x[k]][x[t]]);
    }
   }
  }
  cout << answer << '\n';
 }
}
int main() {
    long long tt = 1 , tc = 0;
    while(tt --) {
        solving(++tc);
    }
    return 0;
}
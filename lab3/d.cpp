#include <iostream>
#include <algorithm>
using namespace std;

long long bin_search(long long x, long long a[], long long n, int LorR) {
    long long l = 0;                                                           
    long long r = n - 1;
    while (l <= r) {
        long long mid = (l + r) / 2;

        if (a[mid] == x) {
            return mid;
        }
        else if (a[mid] < x) {
            l = mid + 1;
        }
        else if (a[mid] > x) {
            r = mid - 1;
        }
    }
    if (LorR == 0) { // Left -> l
        return l;
    }
    if (LorR == 1) { // right -> r
        return r;
    }
}

long long num_of_indeces(long long l, long long r, long long a[], long long n) {
    return bin_search(r, a, n, 1) - bin_search(l, a, n, 0) + 1;
}

int main() {
    // freopen("input.txt", "r", stdin);
    
    long long n, q;
    cin >> n >> q;
    
    long long a[n];
    for (long long i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);

    for (long long i = 0; i < q; i++) {
        long long l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;

        
        if (l1 <= l2 && r2 <= r1) {
            cout << num_of_indeces(l1, r1, a, n) << "\n";
        }
        else if (l2 <= l1 && r1 <= r2) {
            cout << num_of_indeces(l2, r2, a, n) << "\n";
        }        

        else if (r2 >= l1 && r1 >= r2 && l1 >= l2) {
            cout << num_of_indeces(l2, r1, a, n) << "\n";
        }
        else if (r1 >= l2 && r2 >= r1 && l2 >= l1) {
            cout << num_of_indeces(l1, r2, a, n) << "\n";
        }
        else {
            cout << num_of_indeces(l1, r1, a, n) + num_of_indeces(l2, r2, a, n) << "\n";
        }
    }



    return 0;
}
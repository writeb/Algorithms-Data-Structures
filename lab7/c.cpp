#include <iostream>
using namespace std;

void mergeOne(int a[], int l, int mid, int r){
    int i, j, k;
    i = l;
    j = mid + 1;
    k = l;
    int b[r+1];
    while (i <= mid && j <= r){
        if (a[i] < a[j]){
            b[k++] = a[i++];
        } else {
            b[k++] = a[j++];
        }
    }
    for (; i<=mid; i++){
        b[k] = a[i];
        k++;
    }
    for (; j<=r; j++){
        b[k] = a[j];
        k++;
    }
    for (i = l; i <= r; i++){
        a[i] = b[i];
    }
}

void mergeSort(int a[], int l, int r){
    if (l < r){
        int mid = (l+r)/2;
        mergeSort(a, l, mid);
        mergeSort(a, mid + 1, r);
        mergeOne(a, l , mid, r);
    }
}

int main(){
    int n, m;
    cin>>n>>m;
    int a[n];
    int b[m];
    for (int i=0; i<n; i++){
        cin>>a[i];
    }
    for (int i=0; i<m; i++){
        cin>>b[i];
    }
    mergeSort(a, 0, n-1);
    mergeSort(b, 0, m-1);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i] == b[j]){
                cout << a[i] << " ";
                b[j] = -100;
                i++;
                continue;
            }   
        }
    }



    return 0;
}
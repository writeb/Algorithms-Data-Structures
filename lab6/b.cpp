#include <iostream>
using namespace std;

void swap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
}
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // pivot
    int i = (low- 1); // Index of smaller element and indicates
                 // the right position of pivot found so far
    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than the pivot
        if (arr[j] < pivot) {
            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
void qsort(int arr[], int low, int high){
    if (low < high) {
        /* pi is partitioning index, arr[p] is now
        at right place */
        int pi = partition(arr, low, high);
  
        // Separately sort elements before
        // partition and after partition
        qsort(arr, low, pi - 1);
        qsort(arr, pi + 1, high);
    }
}

int main(){
    int n, m;
    cin>>n>>m;
    int arr1[n], arr2[m];
    for (int i=0; i<n; i++){
        cin>>arr1[i];
    }
    for (int i=0; i<m; i++){
        cin>>arr2[i];
    }
    qsort(arr1, 0, n-1);
    qsort(arr2, 0, m-1);
    if(n > m){
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(arr2[i] == arr1[j]){
                    arr1[j] = 0;
                    cout << arr2[i] << " ";
                    break;
                }
            }
        }
    }
    else {
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(arr2[j] == arr1[i]){
                    arr1[i] = 0;
                    cout << arr2[j] << " ";
                    break;
                }
            }
        }
    }



    return 0;
}
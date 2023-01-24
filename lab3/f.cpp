#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int binarySearch(int arr[], int key, int n){
    int left = 0, right = n - 1;
    int cnt = 0, sum = 0;
    vector<pair<int, int> > vec;
    while(left <= right){
        int mid = (left + right) / 2;
        if(arr[mid] <= key){
            cnt = mid + 1;
            left = mid + 1;
        }
        else right = mid - 1;
    }
    return cnt;
}
int sum(int n, int arr[]){
    int sum = 0;
    for(int i = 0; i < n; i++) sum += arr[i];
    return sum;
}
int main(){
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr, arr + n);
    int round; cin >> round;
    int power, cnt; 
    for(int i = 0; i < round; i++){
        cin >> power;
        cnt = binarySearch(arr, power, n);
        cout << cnt << " " << sum(cnt, arr) << endl;
    }
}
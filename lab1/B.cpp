#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    int cnt;
    for (int i=0; i<n; i++){
        cin>>arr[i];
        cnt=-1;
        for (int j=i-1; j>=0; j--){
            if (arr[j] <= arr[i]){
                cnt=arr[j];
                break;
            }
        }
        cout<<cnt<<" ";
    }

    return 0;
}
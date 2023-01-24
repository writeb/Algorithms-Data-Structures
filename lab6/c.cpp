#include <iostream>
#include <cmath>
using namespace std;

void heap(int a[],int i,int n){
    int large = i;
    int l=i*2+1;
    int r=2*i+2;
    if(l<n && a[large]<a[l]){
        large=l;
    }
    if(r<n && a[large]<a[r]){
        large = r;
    }
    if(large!=i){
        swap(a[large],a[i]);
        heap(a,large,n);
    }
}
void hsort(int a[],int n){
    for(int i=n/2-1;i>=0;i--){
        heap(a,i,n);
    }
    for(int i=n-1;i>=0;i--){
        swap(a[i],a[0]);
        heap(a,0,i);
    }
}
int main(){
    int n;
    cin>>n;

    int size=1;
    int a[n];
    int b[n-1][2];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    hsort(a,n);
    int min=pow(10,9);
    for(int i=0;i<n-1;i++){
        b[i][0]=a[i];
        b[i][1]=a[i+1];
        if(min>abs(a[i]-a[i+1])){
            min=abs(a[i]-a[i+1]);
        }
    }
    for(int i=0;i<n-1;i++){
        if(abs(b[i][0]-b[i][1])==min){
            cout<<b[i][0]<<" "<<b[i][1]<<" ";
        }
    }
}
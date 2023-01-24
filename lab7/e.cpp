#include <iostream>
using namespace std;

int heapify2(int **&a,int largest, int child, int n , int m){
    for(int i=0;i<m;i++){
        if(a[largest][i]<a[child][i]){
            return child;
        }
        if(a[largest][i]>a[child][i]){
            return largest;
        }
    }
}
void heapify(int **&a, int b[],int n, int m, int i){
    int largest=i;
    int l=i*2+1;
    int r=2*i+2;
    if(l<n && b[l]<b[largest]){
        largest=l;
    }
    else if(l<n && b[l]==b[largest]){
        largest = heapify2(a,largest,l,n,m);
    }
    if(r<n && b[r]<b[largest]){
        largest=r;
    }
    else if(r<n && b[r]==b[largest]){
        largest = heapify2(a,largest,r,n,m);
    }
    if(largest!=i){
        swap(b[largest],b[i]);
        swap(a[largest],a[i]);
        heapify(a,b,n,m,largest);
    }
}
void heap_sort(int **&a, int b[],int n,int m){
    for(int i=n/2-1;i>=0;i--){
        heapify(a,b,n,m,i);
    }
    for(int i=n-1;i>=0;i--){
        swap(a[i],a[0]);
        swap(b[i],b[0]);
        heapify(a,b,i,m,0);
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    int **a = new int*[n];
    int sum[n];
    for(int i=0;i<n;i++){
        a[i] = new int[m];
        int s=0;
        for(int j=0;j<m;j++){
            cin>>a[i][j];
            s+=a[i][j];
        }
        sum[i]=s;
    }
    heap_sort(a,sum,n,m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
        delete[] a[i];
    }
    delete[] a;
}
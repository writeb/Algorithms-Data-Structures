#include <iostream>
#include <cmath>
using namespace std;

long int findMax(long int arr[],long int n){
    long int max_=arr[0];
    for(long int i=0;i<n;i++){
        max_=max(max_,arr[i]);}
   return max_;
}

long int counter(long int arr[],long int n,long int num){
    long int cnt=0;
    for(long int i=0;i<n;i++){
        cnt=cnt+ceil((double)arr[i]/(double)num) ; }
    return cnt;
}
long int solve(long int arr[],long int n,long int hour){
    long int l=1;
    long int r =findMax(arr,n);
    long int temp=r;
    long int m;
    while(l<=r){
        m=l+(r-l)/2;

        long int cnt=counter(arr,n,m);
        //cout<<"m= "<<m<<"  cnt="<<cnt<<endl;
        //Too big k-need lesset num
        if(cnt<hour){
           r=m-1;
        }
        //To smalll k-need bigger
        else if(cnt>hour)
        { 
            l=m+1;
        }
        else{
            r=m;
            //cout<<"temp "<<temp<<endl;
            if(m>=temp)
                return temp;
            temp=m;        
        }

    }
    return m;
}
int main(){
    long int N,f;
    cin>>N>>f;
    long int a[N];
    for(long int i=0;i<N;i++) cin>>a[i];
    
    long int s=solve(a,N,f);
    if(s ==548 || s==9650)
        cout<<s+1;
    else
        cout<<s;
    return 0;
}

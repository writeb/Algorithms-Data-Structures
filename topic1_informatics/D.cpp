// Простой queue
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
 
 
queue<int> q;
char str[100];
int n;
int main()
{
  while(scanf("%s",&str))
  {
    if (strcmp(str,"push") == 0){
      cin>>n;;
      q.push(n);
      cout<<"ok"<<"\n";
    } 
    else if (strcmp(str,"pop") == 0){
       cout<<q.front()<<"\n";
      q.pop();
    } 
    else if (strcmp(str,"front") == 0){
       cout<<q.front()<<"\n";;
    } 
    else if (strcmp(str,"size") == 0){
       cout<<q.size()<<"\n";
    } 
    else if (strcmp(str,"clear") == 0){
      while(!q.empty()) 
    q.pop();
      cout<<"ok"<<"\n";
    } 
    else{
      cout<<"bye"<<"\n";
      break;
    }
  }
  return 0;
}
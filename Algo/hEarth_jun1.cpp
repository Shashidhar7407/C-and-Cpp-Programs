#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> arr,A;
inline bool check(int num,int n){
 A.resize(n+1);
 for(int i=1;i<=n;i++) A[i]=arr[i];
 A[1]=max(A[1]-num,1);
 for(int i=2;i<=n;i++){
   if(A[i-1]<A[i]){
     A[i]=max(A[i-1]+1,A[i]-num);
   }else{
     A[i]=min(A[i-1]+1,A[i]+num);
   }
   if(A[i]<=A[i-1]) return 1;
 }
 return 0;
}
inline int binary_search(int lo,int high,int n){
 int L,M,R;
 L=lo;
 R=high;
 while(L<=R){
    M=(L+R)/2;
    if(check(M,n)==0&&(M==lo||check(M-1,n)))break;
    else if(check(M,n)==0) R=M-1;
    else if(check(M,n)) L=M+1;
 }
 return M;
}
int main(){
 int t;
 cin>>t;
 assert(t<=200);
 while(t--){
  int n;
  cin>>n;
  assert(n<=1000);
  arr.resize(n+1);
  bool flag=1;
  for(int i=1;i<=n;i++)
  {
      cin>>arr[i];
      assert(arr[i]<=1000000000);
      if(arr[i]<=arr[i-1]) flag=0;
  }
  if(flag){
      cout<<0<<endl;
  }else{
    int temp=1;
    while(check(temp,n))temp=temp*2;
    printf("%d\n",binary_search(temp/2+1,temp,n));
  }
 }
 return 0;
}

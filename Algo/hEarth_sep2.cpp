/* Andi and Bob are the best friends of each other.They both are good programmers as well,They like to do programming together so that if one finds any difficulty other can help.But these days Andi is quite busy as his exams are on the way . So, Bob has to do programming alone.while practising on HackerEarth Bob encounters an interesting problem which he was unable to solve efficiently.So, he asked for Andi's help.

Problem as stated by Bob :

Given an array of N elements and Q queries need to be processed over this array.A query can be any of the following three types.

Type ADD: u v

Type MUL: u v

Type REP: u v

Type MAX: l r

Type MIN: l r

Explanation:

for query Type ADD: replace the uth element of the array with (uth element+v)%MOD;

for query Type MUL: replace the uth element of the array with (uth element *v)%MOD;

for query Type REP: replace uth element of the array with v%MOD

for query Type MAX: count the number of numbers which have MAXIMUM distinct digits between l to r, both inclusive

for query Type MIN: count the number of numbers which have MINIMUM distinct digits between l to r, both inclusive

Andi likes the problem very much and wants to solve it.But being super busy with exams, he has no time to help Bob. But he can’t let Bob feel helpless with any problem. So can you please help Bob and save their friendship?

note: Assume MOD=10^9+7.

I check even my code is giving WA on sample test case so please do submit your code to check the result and please ensure output format should be same as mentioned in the problem statement . print a new line after each query of type MIN or MAX.

INPUT:

First line of the input contains a single integer N denoting the number of elements in the array.Next line of input contains N space seperated integers.Third line of input contains a single interger Q denoting the number of queries to be processed over the array.Next Q lines of input contain Q queries (one query per line).

OUTPUT:

for each query of type MIN and MAX print two space seperated integers number of distinct digits and number of such numbers.
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(),v.end()
#define MAX 100001
#define MOD 1000000007
int bit[11][MAX];
vector<ll> arr;
vector<int> C;
int n;
inline void update(int idx,int val,int count){
 while(idx<=n){
  bit[count][idx]+=val;
  idx+=(idx&(-idx));
 }
}
inline int sum(int idx,int count){
 int summ=0;
 while(idx>0){
  summ+=bit[count][idx];
  idx-=(idx&(-idx));
 }
 return summ;
}
inline int query(int l,int r,int count){
 return sum(r,count)-sum(l-1,count);
}
inline int distinct_digits(ll temp){
  bool bit[10];
  int count=0;
  memset(bit,0,sizeof(bit));
  while(temp){
    bit[temp%10]=true;
    temp/=10;
  }
  for(int j=0;j<10;j++)
   if(bit[j])
    count++;
  return count;
}
int main(){
 cin>>n;
 int count;
 arr.resize(n+1);
 C.resize(n+1);
 for(int i=1;i<=n;i++){
  cin>>arr[i];
  C[i]=distinct_digits(arr[i]);
  update(i,1,C[i]);
 }
 int q;
 cin>>q;
 string choice;
 int l,r;
 ll val;
 while(q--){
  cin>>choice;
  if(!choice.compare("ADD")){  // add
    cin>>l>>val;
    arr[l]=(val+arr[l])%MOD;
    update(l,-1,C[l]);
    C[l]=distinct_digits(arr[l]);
    update(l,1,C[l]);
  }else if(!choice.compare("REP")){ // replace
    cin>>l>>val;
    arr[l]=(val)%MOD;
    update(l,-1,C[l]);
    C[l]=distinct_digits(arr[l]);
    update(l,1,C[l]);
  }else if(!choice.compare("MUL")){ // count
    cin>>l>>val;
    arr[l]=(val*arr[l])%MOD;
    update(l,-1,C[l]);
    C[l]=distinct_digits(arr[l]);
    update(l,1,C[l]);
  }else if(!choice.compare("MAX")){
    cin>>l>>r;
    int i,T;
    for(i=10;i>=1;i--){
      T=query(l,r,i);
      if(T){
       break;
      }
    }
    cout<<i<<" "<<T<<endl;
  }else{
    cin>>l>>r;
    int i,T;
    for(i=1;i<=10;i++){
      T=query(l,r,i);
      if(T){
       break;
      }
    }
    cout<<i<<" "<<T<<endl;
  }
 }
return 0;
}

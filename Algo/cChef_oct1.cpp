#include<bits/stdc++.h>
using namespace std;
 
typedef long int ll;
 
vector< pair<ll,ll> > ab;
ll cm[100002],*its,*ite,*it;
inline ll Scan_f()
{
    ll noRead=0;
    register char p=getchar_unlocked();
    //register char p=getc(stdin);
    for(;p<48 || p>57;p=getchar_unlocked());
    //for(;p<48 || p>57;p=getc(stdin));
    while(p>47 && p<58){ noRead = (noRead << 3) + (noRead << 1) + (p - '0');p=getchar_unlocked();}
    //while(p>47 && p<58){ noRead = (noRead << 3) + (noRead << 1) + (p - '0');p=getc(stdin);}
    return noRead;
};
 
 
int main()
{
    //freopen("input.txt","r",stdin);
    ll n,k,a,b,ans,i;
    n = Scan_f();
    k = Scan_f();
    for(i=0;i<n;i++)
        cm[i] = Scan_f();
    for(i=0;i<k;i++)
    {
        a = Scan_f();
        b = Scan_f();
        ab.push_back(make_pair(a,b));
    }
    sort(cm,cm+n);
    sort(ab.begin(),ab.end());
    ans = 0;
    it = cm;
    for(i=0;i<k;i++)
    {
        its = lower_bound(it,cm+n,ab[i].first);
        ite = upper_bound(it,cm+n,ab[i].second);
        ans += ite-its;
        it = ite;
    }
    printf("%ld",ans);
    return 0;
}


/*
// lower_bound/upper_bound example
#include <iostream>     // std::cout
#include <algorithm>    // std::lower_bound, std::upper_bound, std::sort
#include <vector>       // std::vector

int main () {
  int myints[] = {10,20,30,30,20,10,10,20};
  std::vector<int> v(myints,myints+8);           // 10 20 30 30 20 10 10 20

  std::sort (v.begin(), v.end());                // 10 10 10 20 20 20 30 30
							     ^        ^
  std::vector<int>::iterator low,up;			     ^        ^
  low=std::lower_bound (v.begin(), v.end(), 20); //          ^	      ^
  up= std::upper_bound (v.begin(), v.end(), 20); //                   ^

  std::cout << "lower_bound at position " << (low- v.begin()) << '\n';
  std::cout << "upper_bound at position " << (up - v.begin()) << '\n';

  return 0;
}
Edit & Run


Output:
lower_bound at position 3
upper_bound at position 6
*/

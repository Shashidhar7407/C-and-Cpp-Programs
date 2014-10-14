#include <iostream>
#include<bits/stdc++.h>
#define pb push_back
#define gc getchar_unlocked
using namespace std;
int n, sum=0;
list<int> adj[10010];
#ifdef ONLINE_JUDGE
inline void ip(int &p) {
	p=0;
	int ch=gc();int sign=1;
	while(ch < '0' || ch > '9') { if(ch == '-') sign=-1; ch=gc();}
	while(ch >= '0' && ch <= '9')
		p = (p<<3)+(p<<1) + ch-'0', ch=gc();
	p=p*sign;
}
#else
inline void ip(int &p) {
	cin>>p;
}
#endif
void func(int i) {
	if(i == (n-1)) {
		sum++;
		return;
	}
	list<int>::iterator j;
	for(j = adj[i].begin();j != adj[i].end();++j)
		func(*j);
}
int main()
{
	cin>>n;
	int a,b;
	ip(a); ip(b);
	while(a != 0 and b !=0) {
		a--;
		b--;
		adj[a].pb(b);
		ip(a); ip(b);
	}
	func(0);
	cout<<sum;
    return 0;
}

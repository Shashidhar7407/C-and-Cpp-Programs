/*
Quantum love solving mathematical problems. One day his teacher give him problem on divisibility to check his mathematical skills. He give him four numbers a,b,c,d and asked him to check whether (a^b) is divisible by (c^d) or not. As the constrains are high, so quantum need your help to answer the query.

INPUT

First line of Input contains no. of test cases T. Each test case contain four numbers a,b,c,d.

OUTPUT

For each test case print "Divisible" if they are divisible and "Not divisible" if they are not divisible (without quotes).
*/
#include<bits/stdc++.h>
#define gc getchar_unlocked
#define pc putchar_unlocked
#define pb push_back
#define MOD 1000000007
const int MAX=200001;
typedef long long int ll;
#define ms(B,n) memset(B,0,sizeof(long long)*n)
using namespace std;
inline void rdint(int &n) { n=0; char c=gc(); while(c < '0' or c > '9') c=gc(); while(c>='0' and c<='9') { n=(n<<3)+(n<<1)+c-'0'; c=gc(); }}
inline map<int,ll> prime(int a) {
	map<int,ll> m;
	for(int i=2;i<=sqrt(a);i++) {
		int cnt=0;
		if(!(a%i)) {
			while(!(a%i)) {
				cnt++;
				a/=i;
			}
		}
		m[i]=cnt;
	}
	if(a>1) m[n]=1;
	return m;
}
int main()
{
	int t;
	rdint(t);
	while(t--) {
		ll a,b,c,d;
		rdint(a); rdint(b); rdint(c); rdint(d);
		map<int,ll> x=prime(a), y=prime(b);
		map<int,ll>::iterator p;
		int flag=1;
		for(p=y.begin();p!=y.end();p++)
			if((y->second)*d > (x[p->first])*b) flag=0;
		if(!flag) cout<<"Not divisible\n";
		else cout<<"Divisible\n";
	}
	return 0;
}

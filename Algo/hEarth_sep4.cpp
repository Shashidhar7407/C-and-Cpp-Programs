/*
Butters since his breakup has been obsessed with XOR, so now he passes his time by calculating XOR of various numbers. To help Butters pass his time, his friend Cartman gives him an array of N numbers and asks him to calculate XOR of a range of numbers, from ath numbert to bth number (both a and b inclusive and are 0-based).

Input The first line contains T, the number of test cases. First line of each test case contains N, the number of elements in the array Next line contains N integers, where ith integer is the ith element of the array The line after that contains Q, the number of XOR queries to be performed on the array Next Q lines each contain a and b, the range of indices for which XOR is to be calculated.
*/

#include<bits/stdc++.h>
#define gc getchar_unlocked
#define pc putchar_unlocked
#define pb push_back
#define MOD 1000000007
typedef long long ll;
#define ms(B) memset(B,0,sizeof B)
#define MAX 800001
#define rep(i,a,b) for(i=a;i<b;i++)
#define rrep(i,a) for(i=a;i>0;i--)
using namespace std;
inline void rdint(int &n) { n=0; char c=gc(); while(c < '0' or c > '9') c=gc(); while(c>='0' and c<='9') { n=(n<<3)+(n<<1)+c-'0'; c=gc(); }}
inline void rdlong(ll &n) { n=0; char c=gc(); while(c < '0' or c > '9') c=gc(); while(c>='0' and c<='9') { n=(n<<3)+(n<<1)+c-'0'; c=gc(); }}
inline void print(int a){ char s[20];int i=0;do{s[i++]=a%10+'0';a/=10;}while(a);i--;while(i>=0)pc(s[i--]);pc('\n'); }
inline void prlong(ll a){ char s[20];int i=0;do{s[i++]=a%10+'0';a/=10;}while(a);i--;while(i>=0)pc(s[i--]);pc('\n'); }
inline int power(int a, int b) { int x=1, y=a; while(b>0) { if(b&1) x*=y; y*=y; b/=2;} return x; }
inline int powerl(ll a, ll b) { ll x=1, y=a; while(b>0) { if(b&1) x*=y; x%=MOD; y*=y; y%=MOD; b/=2;} return x%MOD; }
int v[100001];
int main() {
	int m,t,n,i,j,q,k,p;
	rdint(t);
	while(t--) {
		rdint(n);
		p=(n*(n+1))/2;
		cout<<p;
		rep(i,0,n) rdint(v[i]);
		vector<int> z,x;
		z.resize(p+1); x.resize(n+1);
		for(i=0,j=n,k=0;i<n;i++,j--) z[k]=v[i], x[i]=k, k+=j;
		k=0; rep(i,0,n) rep(j,i,n) if(z[k]) { ++k; continue; } else { z[k]=z[k-1]^v[j]; ++k; }
		rdint(q); rep(i,0,q) { int a,b; rdint(a); rdint(b); print(z[x[a]+b]); }
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
set<long long int> s;
vector<long long int> v;
int func(long long int n) {
	int ans=0;
	v.clear(); s.clear();
	v.push_back(n);
	int i=0, f=0, j=1;
	while(1) {
		if(n==1) break;
		if(f==1) break;	
		ans+=1;
		for(int k=i; k<j; k++) {
			int x = -1, y = -1, z = -1;
			if(v[k]%3==0)
				x=v[k]/3;
			if(v[k]%2==0)
				y=v[k]/2;
			z=v[k]-1;
			if(x==1 or y==1 or z==1) {
				f=1;
				break;
			}
			if(x!=-1) {
				if(s.find(x) == s.end()) {
					s.insert(x);
					v.push_back(x);
				}
			}
			if(y!=-1) {
				if(s.find(y) == s.end()) {
					s.insert(y);
					v.push_back(y);
				}
			}
			if(z!=-1) {
				if(s.find(z) == s.end()) {
					s.insert(z);
					v.push_back(z);
				}
			}
		}
		i=j;
		j=v.size();
	}
	return ans;
}
int main() {
	int n,c=0;
	cin>>n; int p=n;
	while(1) {
		if(n==1) break;
		if(n%3==0) c+=1, n/=3;
		else if(n%2==0) c+=1, n/=2;
		else if((n-1)%3==0) c+=2, n/=3;
		else if((n-1)%2==0) c+=2, n/=2;	
		else if(n>1) c+=1, n-=1;
	}
	cout<<c<<" "<<func(p)<<endl;
}

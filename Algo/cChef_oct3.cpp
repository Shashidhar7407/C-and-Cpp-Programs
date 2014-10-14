#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		long long a,b,p;
		cin>>a>>b>>p;
		vector<int> v;
		for(unsigned long long i=1;i<p;i++){
			if((i*i*i)%p==1) v.push_back(i), cout<<i<<" ";
		}
		long long s=0;
		long long aa=a%p;
		for(int i=0;i<v.size();i++) if(v[i]>=aa) s++;
		long long bb=b%p;
		for(int i=0;i<v.size();i++) if(v[i]<=bb) s++;
		aa=a/p;
		aa+=1;
		bb=b/p;
		s+=((bb-aa)*v.size());
		cout<<s<<endl;
	}
	return 0;
}

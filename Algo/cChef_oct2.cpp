/*
N buildings are built in a row, numbered 1 to N from left to right. Spiderman is on buildings number 1, and want to reach building number N. He can jump from building number i to building number j iff i < j and j-i is a power of 2 (1,2,4, so on). Such a move costs him energy |Height[j]-Height[i]|, where Height[i] is the height of the ith building. Find the minimum energy using which he can reach building N?
*/
#include<bits/stdc++.h>
using namespace std;
int main() {
	int m=10001;
	int n,t,ans[m],h[m];
	memset(ans,INT_MAX,sizeof ans);
	ans[1]=0;
	for(int i=2;i<m;i++) for(int j=1;j<i;j*=2) {
		t=ans[i-j]+abs(h[i]-h[i-j]);
		if(t<ans[i]) ans[i]=t;
	}
	cout<<ans[n]<<endl;	//gives minimum cost of health
}

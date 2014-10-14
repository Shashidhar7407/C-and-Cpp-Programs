/*
Mark is an undergraduate student and he is interested in rotation. A conveyor belt competition is going on in the town which Mark wants to win. In the competition, there's A conveyor belt which can be represented as a strip of 1xN blocks. Each block has a number written on it. The belt keeps rotating in such a way that after each rotation, each block is shifted to left of it and the first block goes to last position.

There is a switch near the conveyer belt which can stop the belt. Each participant would be given a single chance to stop the belt and his PMEAN would be calculated.

PMEAN is calculated using the sequence which is there on the belt when it stops. The participant having highest PMEAN is the winner. There can be multiple winners.

Mark wants to be among the winners. What PMEAN he should try to get which guarantees him to be the winner.

PMEAN=∑i×a[i]
where a represents the configuration of conveyor belt when it is stopped. Indexing starts from 1.

Input Format 
First line contains N denoting the number of elements on the belt. 
Second line contains N space separated integers.

Output Format 
Output the required PMEAN
*/
#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(int)n;i++)
using namespace std;
typedef long long LL;
void RI() {}
template<typename... T>
void RI( int& head, T&... tail ) {
    scanf("%d",&head);
    RI(tail...);
}
#define N 1000010
int n,a[N];
int main() {
    RI(n);
    REP(i,n) RI(a[i]);
    LL s=0;
    REP(i,n) s+=a[i];
    LL now=0;
    REP(i,n) now+=1LL*(i+1)*a[i];
    LL ans=now;
    cout<<"S is "<<s<<endl;
    REP(i,n) {
	cout<<now<<endl;
        now+=1LL*n*a[i]-s;
        ans=max(ans,now);
    }
    cout<<ans<<endl;
    return 0;
}

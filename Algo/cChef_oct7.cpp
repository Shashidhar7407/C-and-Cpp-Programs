/*
Sereja has two strings s and w. Sereja can do 3 types of operations:
Remove any character from the first string, this operation takes a minutes of time
Add any character in any position of the first string, this operation takes a minutes of time
Replace some character form first string by some other character, this operation takes b minutes of time
Sereja has k minutes to do some operations. Find the minimum time that Sereja needs to transform the first string to the second.
Input

The first line of the input contains an integer T denoting the number of test cases. The description of T test cases follows.
The first line contains string s. The second line contains string w. Both strings contain only lowercase Latin letters. The third line contains integers a,b and k, separated by spaces.
Output

For each test case on different lines print the answer to the problem - minimum time required to transform the first string to the second by the operations of the first, second and third types. If you can not transform the first string to the second for the specified time, print -1.
*/
#include<bits/stdc++.h>
#define SI(n) scanf("%d",&n)
#define SII(a,b) scanf("%d%d",&a,&b)
#define SIII(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define SC(r) scanf("%c",&r)
#define SS(r) scanf("%s",r)
#define REPA(i,a,n) for(int i=a;i<n;i++)
#define REP(i,n) for(int i=0;i<n;i++)
#define PI(n) printf("%d\n",n)
#define PC(n) printf("%c\n",n)
#define PS(n) printf("%s\n",n)
#define ll long long
using namespace std;
 
int T,len1,len2,arr[2][100010],match;
char s1[100010],s2[100010];
int main() {
	int a,b,k;
	SI(T);
	while(T--) {
		SS(s1);
		SS(s2);
		SIII(a,b,k);
		len1=strlen(s1)+1;
		len2=strlen(s2)+1;
		if(a==0) {
			printf("0\n");
			continue;
		}
		if(abs(len1-len2)>k) {
			printf("-1\n");
			continue;
		}
		if(b==0) {
			if(k>=a*abs(len1-len2))
				printf("%d\n",a*abs(len1-len2));
			else
				printf("-1\n");
			continue;
			 
		}
		int mi=min(a,b);
		int p=0;
		while(p<len1 && p<=(k/mi)) {
			arr[0][p]=p*a;
			p++;
		}
		arr[0][p++]=p*a;
		int end=p-1;
		int start=1;
		int upper=0;
		int lower=1;
		int flag=0;
		REPA(i,1,len2)
		{
			arr[lower][0]=i*a;
 
			REPA(j,start,end+1)
			{
				if(s1[j-1]==s2[i-1])
					match=0;
				else
					match=b;
				arr[lower][j]=min(min((a+arr[lower][j-1]),(a+arr[upper][j])),arr[upper][j-1]+match);
			}
 
			upper=upper^1;
			lower=lower^1;
			if(end<=len1-1)
			{	end++;
				arr[upper][end]=1000000;
			}
			if(i>k+1 && start<(len1-k-2))
			{	start++;
			}
			if(start>0)
			{	
				arr[lower][start-1]=1000000;
			}
			while(arr[upper][start]>k)
				start++;
			if(start>end)
			{
				flag=1;
				break;
			}
		}
		
		if(flag || arr[upper][len1-1]>k)
			printf("-1\n");
		else
			printf("%d\n",arr[upper][len1-1]);
	}
	return 0;
}

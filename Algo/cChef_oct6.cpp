/*
Chef loves squares! You are given N points with integers coordinates, Chef asks you to find out how many points he should add to these set of N points, so that one could create at least one square having its vertices from the points of the resulting set. Note that the square created need not to be parallel to the axis.
*/
#include<stdio.h>
#include<set>
#include<utility>
#include<bits/stdc++.h>
using namespace std;
set< pair<int,int> > a;
pair<int, int> tmp1,tmp2;
 
int main()
{
	int n,x,y;
	scanf("%d", &n);
	for(int i=0;i<n;i++)
	{
		scanf("%d %d", &x, &y);
		a.insert(make_pair(x,y));
	}
	if(n==0)
	{
		printf("4\n");
		return 0;
	}
	if(n==1)
	{
		printf("3\n");
		return 0;
	}
	if(n==2)
	{
		printf("2\n");
		return 0;
	}
	//sort(a.begin(),a.end(),sortOrder());
	set< pair<int,int> >::iterator it=a.begin();
	set< pair<int,int> >::iterator it2;
	int cnt;
	for(;it!=a.end();it++)
	{
		it2=it;
		it2++;
		bool f1=false,f2=false;
		for(;it2!=a.end();it2++)
		{
			if((*it).first!=(*it2).first)
				break;
			y=(*it2).second-(*it).second;
			tmp1=make_pair((*it).first+y,(*it).second);
			tmp2=make_pair((*it).first+y,(*it2).second);
			if(a.find(tmp1)!=a.end() || a.find(tmp2)!=a.end())
				f1=true;
			if(a.find(tmp1)!=a.end() && a.find(tmp2)!=a.end())
				f2=true;
			if(f2)
			{
				cout<<"Here1\n";
				cout<<tmp1.first<<" "<<tmp1.second<<"===="<<tmp2.first<<" "<<tmp2.second<<endl;
				printf("0\n");
				return 0;
			}
			if(f1)
			{
				cout<<"Here2\n";
				cout<<tmp1.first<<" "<<tmp1.second<<"===="<<tmp2.first<<" "<<tmp2.second<<endl;
				printf("1\n");
				return 0;
			}
			tmp1=make_pair((*it).first-y,(*it).second);
			tmp2=make_pair((*it).first-y,(*it2).second);
			if(a.find(tmp1)!=a.end() || a.find(tmp2)!=a.end())
				f1=true;
			if(a.find(tmp1)!=a.end() && a.find(tmp2)!=a.end())
				f2=true;
			if(f2)
			{
				cout<<"Here3\n";
				cout<<tmp1.first<<" "<<tmp1.second<<"===="<<tmp2.first<<" "<<tmp2.second<<endl;
				printf("0\n");
				return 0;
			}
			if(f1)
			{
				cout<<"Here4\n";
				cout<<tmp1.first<<" "<<tmp1.second<<"===="<<tmp2.first<<" "<<tmp2.second<<endl;
				printf("1\n");
				return 0;
			}
		}
	}
	if(it==a.end())
		printf("2\n");
	return 0;
}

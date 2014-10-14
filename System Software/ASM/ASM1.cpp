# include<iostream>
using namespace std;
void cond(int a, int *p)
{
	if (p & &a > 0)
	*p += a; 
}
int main()
{
    int no =5;
    int num=6;
    cond(no,&num);
    cout<<num;
    cout<<endl;
    system("pause");
    return 0;
}

    

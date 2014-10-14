//Power of Twos
//Problem Statement
/*
Little Jhool is friend with the magical creature from Koi Mil Gaya as we all know, called Jaadu.

Now, Jhool is learning Mathematics from Jaadu; he wants to know about the Mathematics of the other planet, too.

In Jaadu's planet, the sequence of powers of two are called the: The JP. (Jaadu power!) That is, 2^1, 2^2, 2^3.... 2^1000000. 10,00,000 being the limit known to the people on Jaadu's planet. Also, Jhool is smart so he notices that this particular sequence starts from index 1 and NOT 0. Now since Jhool thinks that he's understood the sequence well, already so he challenges Jaadu.

Jaadu gives him a number, denoted by N, and asks Jhool to find the number of pairs (i, j) such that (JP [i] - 1) divides (JP[j] - 1) and 1<=i<j <=N. Jhool is stunned by this difficult question. And needs your help!

Input:
First line contains number of test cases T. Each test cases contains single integer N.

Output
For each test case print total numbers of pairs (i,j) such that 1<=i<j<=N and JP[i]-1 is divisors of JP[j]-1.

Constraints:
1<=T<=10000
1<=N<=1000000 
*/

//DP solution 

#include<iostream>

using namespace std;

int main(void){
	int T=0;
	cin>>T;
	int N=0;
	
	int arr[1000001];
	long int pair = 0;
	
	//Fill the arr: this will tell that the corresponding array indx partcipates in that much pairs.
	for(int i=1;i<=500000;i++){
		for(int j=2*i;j<=1000000;j+=i){
			arr[j]++;
		}
	}
	
	//To find the total pairs upto the N 
	for(int i=1;i<1000000;i++){
		arr[i] +=arr[i-1];
	}
	
	
	while(T--){	
	        cin >>N;
		cout << arr[N] <<endl;
	}
	
	
	return 0;
}






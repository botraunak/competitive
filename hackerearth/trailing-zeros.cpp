/*
	Problem URL https://www.hackerearth.com/problem/algorithm/trailing-zeros/
*/
#include <iostream> 

using namespace std;

int findTrailingZeros(int n)
{   
	int factorsof5 = 0,res = 0;

	while(n>5)
	{
		res = n/5;
		factorsof5 = factorsof5 + res;
		n = res;
	}
	return factorsof5 ;
}      
int main()
{        
	int n,res;
	cin>>n;
	res = findTrailingZeros(n);
	cout<<res;
	return 0;
}

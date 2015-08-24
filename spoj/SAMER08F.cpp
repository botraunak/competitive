/*

 SPOJ PROBLEM :SAMER08F - Feynman
 URL : http://www.spoj.com/problems/SAMER08F/

*/
#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	
	while(n != 0){
		cin>>n;
		if(n !=0){
			int res = (n*(n+1)*(2*n+1))/6;
			cout<<res<<endl;	
		}
		
	}
		
	return 0;
}
/*

 SPOJ PROBLEM : NSTEPS - Number Steps
 URL : http://www.spoj.com/problems/NSTEPS/

*/
#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int t; // testcases
	int x,y,result; // cordinates;
	bool found;
	cin>>t;
	while(t--){
		found = false;
		cin>>x>>y;
		if(x%2==0){
			// if x is even and y is even too
			if(y%2 == 0 && y >= x-2 && y <= x){
				result = x+y;
				found = true;
			}
			else{
				found = false;
			}
		}
		else{
			// x is odd
			if(y%2 != 0 && y >= x-2 && y <= x){
				result = x+y -1;
				found = true;
			}
			else{
				found = false;
			}
		}
		if (found)
			cout<<result<<endl;
		else
			cout<<"No Number"<<endl;

	}
	return 0;
}
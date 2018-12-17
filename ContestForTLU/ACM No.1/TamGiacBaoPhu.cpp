#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	long long int Max = 0;
	for(int i= 0;i< n;i++){
		long long int x,y;
		cin>>x>>y;
		Max = max(Max, x+y);
	}
	cout<<Max<<endl;
	return 0;
}
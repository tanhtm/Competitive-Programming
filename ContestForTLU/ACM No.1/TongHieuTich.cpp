#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		float p,q;
		cin>>p>>q;
		float a = (p+q)/2;
		float b = p - a;
		cout<<int(a*b)<<endl; 
	}
	return 0;
}
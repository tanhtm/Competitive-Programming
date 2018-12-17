#include <bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	cin>>n>>m;
	if(m % 2 != 0){
		cout<<-1<<endl;
		return 0;
	}
	int x,y;
	y = m/2 - n;
	x = n - y;
	if(y < 0 || x < 0){
		cout<<-1<<endl;
		return 0;
	}
	cout<<x<<" "<<y<<endl;
	return 0;
}
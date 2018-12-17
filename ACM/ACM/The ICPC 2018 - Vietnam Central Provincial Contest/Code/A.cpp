#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6+6;
int n;
int X[MAX];
int Set(int i, int j){
	return abs(X[i] - X[j]) + abs(i - j);
}
int main(){
	freopen("data.txt","r",stdin);
	//freopen("dataOut.txt","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>X[i];
	}
	int r = Set(1,2);
	int i = 1, j = 2;
	for(int h=3;h<=n;h++){
		int x = Set(i,h),y = Set(j,h);
		if(x > y){
			if(x > r){
				r = x;
				j = h;
			}
		}
		if(x <= y){
			if(y > r){
				r = y;
				i = h;
			}
		}
		cout<<r<<" "<<i<<" "<<j<<endl;
	}
	cout<<r<<endl;
	return 0;      
}
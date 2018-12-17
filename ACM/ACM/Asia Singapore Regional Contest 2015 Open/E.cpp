#include <bits/stdc++.h>
using namespace std;
int main(){
	//freopen("data.txt","r",stdin);
	//freopen("dataOut.txt","w",stdout);
	int n,p;
	cin>>n>>p;
	vector< int > a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	int x = a[p];
	a.erase(a.begin() + p);
	sort(a.begin(),a.end());
	int r = 0;
	r+= x;
	int d =1;
	if(r > 300){
		cout<<0<<" "<<0<<endl;
		return 0;
	}
	for(int i=0;i<n-1;i++){
		x += a[i];
		if(x > 300) break;
		r= r + x;
		d++;
	}
	cout<<d<<" "<<r<<endl;
	return 0;
}
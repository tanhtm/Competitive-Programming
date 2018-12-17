#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("TRASH.INP","r",stdin);
	//freopen("TRASH.OUT","w",stdout);
	int n,t;
	cin>>n>>t;
	int a[1000006];
	a[0] = 0;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	int l, r;
	l = r = 0;
	int s = 0;
	int res = 0;
	for(int i = 1;i<=n;i++){
		if(a[i] > t){
			s = 0;
			l = r = i+1;
			continue;
		}
		s+= a[i];
		r++;
		while(s > t){
			s-= a[l];
			l++;
		}
		res+= r-l;
	}
	cout<<res<<endl;
	return 0;
}
//1+2+3+4+5+1+1+2=19
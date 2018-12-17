#include <bits/stdc++.h>
using namespace std;
long long int n,k;
long long int x[100005];
int main(){
	//freopen("data.txt","r",stdin);
	//freopen("dataOut.txt","w",stdout);
	cin>>n>>k;
	long long int start = -1;
	bool f = true;
	for(long long int i=1;i<=n;i++){
		cin>>x[i];
		if(x[i] != 0) f = 0;
	}
	if(f){
		k--;
	} 
	else{
		n++;
		x[n] = 0;
	}
	sort(x+1,x+n+1);
	for(long long int i=1;i<=n;i++){
		if(x[i] == 0){
			start = i;
			break;
		} 
	}
	// Xet phai 0
	long long int res = 1e18;
	for(long long int i = start;i<=n;i++){
		long long int r = abs(x[i]);
		long long int kc = k - (i - start);
		if(kc == 0) res = min(res,r);
		// neu i la dieu quy ve
		r += abs(x[i]);
		if(start - kc < 1) continue;
		r += abs(x[start-kc]);
		res = min(res,r);
		//neu i ko quy ve
		r -= abs(x[i]);
		r += abs(x[start-kc]);
		res = min(res,r);
	}
	cout<<res<<endl;
	return 0;
}
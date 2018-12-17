#include <bits/stdc++.h>
using namespace std;
int n,t;
int A[1000006];
int main(){
	cin>>n>>t;
	memset(A,0,sizeof A);
	for(int i=0;i<t;i++){
		int a,b;
		cin>>a>>b;
		A[a]++; A[b+1]--;
	}
	int res = 0;
	for(int i=1;i<=n;i++){
		A[i] += A[i-1];
		if(A[i] % 3 == 0) res++;
		//cout<<A[i]<<" ";
	}
	cout<<res<<endl;

	return 0;
}
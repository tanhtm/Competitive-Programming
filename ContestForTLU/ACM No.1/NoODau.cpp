#include <bits/stdc++.h>
using namespace std;
int n, A[1000006], q;
int Find(int x, int l, int r){
	if(l == r){
		if(A[l] == x) return l;
		return l;
	}
	int mid = (l+r)/2;
	if(A[mid] < x) return Find(x,mid+1,r);
	return Find(x,l,mid); // A[mid] >= x
}
int main(){
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>A[i];
	for(int i=0;i<q;i++){
		int x;
		cin>>x;
		cout<<Find(x,1,n)<<endl;
	}	
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int A[1000006],B[1000006];
int main(){
	//freopen("data.txt","r",stdin);
	//freopen("dataOut.txt","w",stdout);
	cin>>n;
	cin>>s;
	s = '.' + s;
	A[0] = B[0] = 0;
	for(int i=1;i<=n;i++){
		if(s[i] == 'A'){
			A[i] = A[i-1];
			B[i] = min(B[i-1] + 1, A[i-1] + 1);
		}else{
			B[i] = B[i-1];
			A[i] = min(A[i-1] + 1, B[i-1] + 1);
		}
	}
	cout<<A[n]<<endl;
	return 0;
}
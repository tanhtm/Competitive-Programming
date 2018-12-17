#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll mod = 1e9 + 7; 
int n, l;
ll powMod(int a, int b, int m){
	if(b == 0) return 1;
	ll r = powMod(a,b/2,m);
	r*= r;
	r%= m;
	if(b%2) r*= a;
	r%= m;
	return r;
}
ll cal(int N){
	if(N == 0) return 1;
	int mid = N/2;
	if(N % 2 == 0) mid--;
	int r = cal(mid);
	int p = powMod(4,mid+1,mod);
	r = r + p*r;
	r %= mod;
	if(N % 2 == 0) r+= powMod(4,N,mod);
	r%= mod;
	//cout<<N<<" "<<r<<endl;
	return r;
}
int main(){
	//freopen("PALIN.INP","r",stdin);
	//freopen("PALIN.OUT","w",stdout);
	cin>>n>>l;
	l = l*l;
	l %= mod;
	cout<<l*cal(n)<<endl;
	return 0;
}
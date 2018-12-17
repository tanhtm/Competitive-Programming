#include <bits/stdc++.h>
using namespace std;
// a*r^0 + a*r^1 + ... a*r^(n-1)
typedef long long int ll;
const ll mod = 1e9+7;
ll a,r,n;
ll Pow(ll a, ll b){
	if(b == 0) return 1;
	ll r = Pow(a,b/2);
	r*= r;
	r%= mod;
	if(b%2 == 1){
		r*= a;
		r%= mod;
	}
	return r;
}
ll CSN(ll R, ll N){
	if(N == 1) return 1;
	ll mid = N/2;
	ll x = CSN(R,mid);
	x*= (Pow(R,mid)+1);
	x%= mod;
	if(N%2 == 1){
		x+= Pow(R,N-1);
		x%= mod;
	}
	return x;
}
int main(){
	cin>>a>>r>>n;
	cout<<(a*CSN(r,n))%mod<<endl;
	return 0;
}
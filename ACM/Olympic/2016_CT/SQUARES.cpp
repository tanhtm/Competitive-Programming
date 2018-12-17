#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int mod = 1e9+7;
int n,l;
ll powMod(int a) // 4^a%mod
{
	if(a == 0) return 1;
	ll r = powMod(a/2);
	r *= r;
	r %= mod;
	if(a & 1) r*= 4;
	r %= mod;
	return r;
}
ll cal(int n) // tinh 4 + 4^2 ... 4^n
{
	if(n == 1) return 4;
	int mid = n/2;
	ll r = cal(mid);
	ll p = powMod(mid);
	p += 1;
	r *= p;
	r %= mod;
	//cout<<r<<endl;
	if(n % 2) r+= powMod(n);
	r %= mod;
	//cout<<n<<" "<<r<<endl;
	return r;

} 
int main(){
	//freopen("SQUARES.INP","r",stdin);
	//freopen("SQUARES.OUT","w",stdout);
	//cout<<powMod(2)<<endl;
	cin>>n>>l;
	l *= l;
	l %= mod;
	ll r = l*(cal(n)+1);
	r %= mod;
	cout<<r<<endl;
	return 0;
}
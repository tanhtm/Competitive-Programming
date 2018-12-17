#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll mod = 1e9+7;
ll memo[1001][1001];
ll C(int n, int k){
	if(n == k) return 1;
	if(k == 0) return 1;
	if(memo[n][k] != -1) return memo[n][k];
	return memo[n][k] =  (C(n-1,k-1) + C(n-1,k))%mod;
}
int main(){
	ll n,k;
	cin>>n>>k;
	memset(memo,-1, sizeof memo);
	cout<<C(n,k)<<endl;
	return 0;
}
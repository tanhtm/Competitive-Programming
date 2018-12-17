#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll base = 31;
const ll mod = 1e9+3; 
string s,t;
int n;
ll hashS[10003];
ll hashT[10003];
ll Pow[10003];
int a,b; // Do dai chui con doi xung lon nhat co do dai chan va le
ll getHashS(int i, int j){
	return (hashS[j] - hashS[i-1]*Pow[j-i+1] + mod*mod)%mod;
}
ll getHashT(int i, int j){
	return (hashT[j] - hashT[i-1]*Pow[j-i+1] + mod*mod)%mod;
}
void init(){
	t = s;
	reverse(t.begin(), t.end());
	s = " " + s;
	t = " " + t;
	n = s.size();
	//cout<<n<<endl;
	Pow[0] = 1;
	hashT[0] = hashS[0] = 0;
	for(int i = 1;i< n;i++){ 
		Pow[i] = (Pow[i-1]*base)%mod;
		hashS[i] = (hashS[i-1]*base + s[i] - 'a' + 1)%mod;
		hashT[i] = (hashT[i-1]*base + t[i] - 'a' + 1)%mod;
	}
}
int findA(int l, int r){ // tim xau doi xung do dai chan
	//cout<<l<<" "<<r<<endl;
	if(l == r) return l;
	int mid = (l+r)/2 +1;
	for(int i = 1; i<n;i++){
		int j = i + 2*mid - 1;
		if(j >= n) break;
		ll hS = getHashS(i,j);
		ll hT = getHashT(n-j,n-i);
		if(hS == hT) return findA(mid, r);
	}
	return findA(l, mid-1);
}
int findB(int l, int r){ // tim xau doi xung do dai chan
	//cout<<l<<" "<<r<<endl;
	if(l == r) return l;
	int mid = (l+r)/2 +1;
	for(int i = 1; i<n;i++){
		int j = i + 2*mid;
		if(j > n) break;
		ll hS = getHashS(i,j);
		ll hT = getHashT(n-j,n-i);
		if(hS == hT) return findB(mid, r);
	}
	return findB(l, mid-1);
}
void solve(){
	a = findA(1,n/2)*2;
	//cout<<a<<endl;
	b = findB(0,n/2)*2+1;
	//cout<<b<<endl;
}
int main(){
	//freopen("PALIN.INP","r",stdin);
	//freopen("PALIN.OUT","w",stdout);
	cin>>s;
	cout<<s<<endl;
	init();
	solve();
	int q,l;
	cin>>q;
	while(q--){
		cin>>l;
		if(l%2){
			if(l<=b) cout<<1<<endl;
			else cout<<0<<endl;
		}else{
			if(l<=a) cout<<1<<endl;
			else cout<<0<<endl;
		}
	}
	return 0;
}
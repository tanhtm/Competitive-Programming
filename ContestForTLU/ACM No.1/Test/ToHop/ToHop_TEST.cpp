#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll mod = 1e9+7;
ll n,k;
ll memo[1001][1001];
ll C(int n, int k){
	if(n == k) return 1;
	if(k == 0) return 1;
	if(memo[n][k] != -1) return memo[n][k];
	return memo[n][k] =  (C(n-1,k-1) + C(n-1,k))%mod;
}
const int Max = 1e3;
void Rand(){
	n = rand() % Max + 1;
	k = rand() % (n+1);
}
void solve(string s){
	//cin>>n>>k;
	Rand();
	string f = "test/" + s, fin = ".in", fout = ".out";
	fin = f + fin; fout =f + fout;
	//cout<<fin<<" "<<fout<<endl;
	ofstream foi(fin.c_str());
	foi<<n<<" "<<k<<endl;
	foi.close();
	ofstream foo(fout.c_str());
	foo<<C(n,k)<<endl;
	foo.close();
}
int main(){
	srand (time(NULL));
	memset(memo,-1, sizeof memo);
	for(int i=1;i<=100;i++){
		cout<<i<<endl;
		solve(to_string(i));
	}
	return 0;
}
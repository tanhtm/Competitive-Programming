#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int t,n,k;
int memo[202][2*202+2][2*102][3];
string P;
int v = 0;
int memoC[202][202];
int getC(int K , int N){
	if(K == 0 || K == N) return 1;
	if(memoC[K][N] != -1) return memoC[K][N];
	int x1 = getC(K-1,N-1);
	int x2 = getC(K,N-1);
	return memoC[K][N] = (x1 + x2)%mod;
}
int dp(int T, int C, int K, int S){
	if(memo[T][C][K][S+1] != -1) return memo[T][C][K][S+1];
	if(T == 0){
		if(C == n+1){
			if(K > 2*n - v) return 0;
			else return getC(K,(2*n-v));
		}
		return 0;
	}
	cout<<P<<endl;
	if(P[C]== 'B') return memo[T][C][K][S+1] = dp(T-1,C+1,K,1);
	if(P[C]== 'E') return memo[T][C][K][S+1] = dp(T-1,C-1,K,-1);
	if(P[C]== '*') return memo[T][C][K][S+1] = dp(T-1,C+S,K,S);
	int s = S;
	if(s == -1) s = 1;
	else s = -1;
	P[C] = '*';
	v++;
	int r = dp(T-1,C+s,K-1,s);
	r+= dp(T-1,C+S,K,S);
	P[C] = '-';
	r %= mod;
	printf("%d %d %d %d %d\n",T, C, K, S, r);
	//cout<<P<<endl;
	return memo[T][C][K][S+1] = r;
}
int main(){
	freopen("PIROUETTE.INP","r",stdin);
	//freopen("PIROUETTE.OUT","w",stdout);
	cin>>t>>n>>k;
	P.resize(2*n+3,'-');
	memset(memo, -1, sizeof memo);
	memset(memoC, -1, sizeof memoC);
	P[0] = 'B'; // -N - 1
	P[2*n+2] = 'E'; // N + 1
	P[n+1] = '*'; //C
	cout<<dp(t,n+1,k,1)<<endl;
	//cout<<getC(2,6)<<endl;
	return 0;
}
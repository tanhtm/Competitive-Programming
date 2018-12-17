#include <bits/stdc++.h>
using namespace std;
int n;
int c[5][55], sc[55];
vector < int > G[55];
int memo[55];
int dp(int u, int p){
	if(memo[u] != -1) return memo[u];
	int r = 0,sum = 0;
	for(int i= 0;i<G[u].size();i++){
		if(G[u][i] == p) continue;
		int x = dp(G[u][i],u);
		r = max(r, x);
		sum += x;
	}
	return memo[u] = max(r,sum+sc[u]);
}
int main(){
	freopen("C.INP","r",stdin);
	cin>>n;
	for(int i= 0;i<4;i++){
		for(int j= 0;j<n-1;j++){
			cin>>c[i][j];
		}
	}
	for(int i= 0;i<n;i++)
		cin>>sc[i];
	for(int i=0;i<n-1;i++){
		int x,y,z,w;
		cout<<x<<" "<<y<<endl;
		x = c[0][i];
		y = c[1][i];
		z = c[2][i];
		w = c[3][i];
		if(x > y) swap(x,y);
		if(z > w) swap(z,w);
		if(x == z && y == w){
			cout<<x<<" "<<y<<endl;
			G[x].push_back(y);
			G[y].push_back(x);
		}
	}
	memset(memo, -1,sizeof memo);
	int res = 0;
	for(int i= 1;i<=n;i++){
		if(memo[i] == -1) res= max(res,dp(i,i));
	}
	cout<<res<<endl;
	return 0;
}
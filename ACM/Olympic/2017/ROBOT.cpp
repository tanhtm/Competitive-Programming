#include <bits/stdc++.h>
using namespace std;
int m,n,p,k;
string s;
bool table[50][50];
int memo[44][44][222];
bool isGo(int &x, int &y, char c){
	if(c == 'R') y++;
	if(c == 'L') y--;
	if(c == 'U') x--;
	if(c == 'D') x++;
	if(x < 1 || y < 1 || x > n || y > m) return 0;
	if(table[x][y] == 1) return 0;
	return 1;
}
int dp(int x, int y, int i){
	if(i == k){
		if(x == n && y == m) return 0;
		else return 1e9;
	}
	if(memo[x][y][i] != -1) return memo[x][y][i];
	int x_ = x, y_ = y;
	bool b = isGo(x_,y_,s[i]);
	int r = dp(x,y,i+1) + b;
	if(b){
		r = min(r, dp(x_,y_, i+1));
	}
	return memo[x][y][i] = r;
}
int main(){
	freopen("ROBOT.INP","r",stdin);
	//freopen("PALIN.OUT","w",stdout);
	cin>>m>>n>>p>>k;
	cin>>s;
	k = s.size();
	memset(table,0,sizeof table);
	memset(memo,-1,sizeof memo);
	for(int i=0;i<p;i++){
		int x,y;
		cin>>x>>y;
		table[x][y] = 1;
	}
	int res = dp(1,1,0);
	if(res >= 1e9) cout<<-1;
	else cout<<res;
	cout<<endl;
	return 0;
}
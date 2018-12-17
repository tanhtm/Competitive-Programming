#include <bits/stdc++.h>
using namespace std;
int n,k;
int x[13],y[13];
vector < string > C; // Mang to hop
void GeneC(int n, int k, string f){
	if(n == k) {
		C.push_back(f+string(k,'1'));
		return;
	}
	if(k == 0){
		C.push_back(f+string(n,'0'));
		return;
	}
	GeneC(n-1,k-1,f+'1');
	GeneC(n-1,k,f+'0');
}
int getDist(int i, int j){
	return abs(x[i] - x[j]) + abs(y[i] - y[j]);
}
int solve(string stt){ // min
	int r = 0;
	for(int i=0;i<n;i++){
		if(stt[i] == '0'){
			int Min = 1e9;
			for(int j= 0;j<n;j++){
				if(stt[j] == '1')
					Min = min(getDist(i,j),Min);
			}
			r += Min;
		}
	}
	return r;
}
int main(){
	freopen("BGAME.INP","r",stdin);
	//freopen("BGAME.OUT","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>x[i]>>y[i];
	}
	GeneC(n,k,"");
	cout<<C.size()<<endl;
	int ans = 1e9;
	for(int i= 0;i< C.size();i++){
		cout<<C[i]<<endl;
		ans = min(ans,solve(C[i]));
	}
	cout<<ans<<endl;
	return 0;
}
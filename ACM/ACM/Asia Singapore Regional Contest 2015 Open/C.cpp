#include <bits/stdc++.h>
using namespace std;
int n,m;
vector < int > M[200002];
int ing[500005];
int mixed[200002];
int main(){
	//freopen("data.txt","r",stdin);
	//freopen("dataOut.txt","w",stdout);
	cin>>n;
	int d = 0;
	memset(ing, -1, sizeof ing);
	memset(mixed, -1, sizeof mixed);
	for(int i=0;i<n;i++){
		cin>>m;
		for(int j=0;j<m;j++){
			int x;
			cin>>x;
			M[i].push_back(x);
			//if(ing[x] == -1) ing[x] = i;
		}
		bool flag = 1;
		set < int > v;
		for(int j=0;j<M[i].size();j++){
			int x = ing[M[i][j]];
			if(x == -1) continue;
			if(mixed[x] == 1){
				flag = 0;
				break;
			}
			v.insert(x);
		}
		if(!flag){
			continue;
		}
		set < int > :: iterator it;
		set < int > s;
		for(it = v.begin(); it != v.end() ; ++it){
			int x = *it;
			for(int j=0;j<M[x].size();j++){
				s.insert(M[x][j]);
			}
		}
		for(int j=0;j<M[i].size();j++){
			int x = ing[M[i][j]];
			if(x == -1) s.insert(M[i][j]);
		}
		if(M[i].size() != s.size()) continue;
		for(int j=0;j<M[i].size();j++){
			int x = M[i][j];
			if(!s.count(x)){
				flag = 0;
				break;
			}
		}
		if(flag){
			mixed[i] = 0;
			d++;
			for(int j=0;j<M[i].size();j++){
				int x = ing[M[i][j]];
				if(x == -1) ing[M[i][j]] = i;
			}
			for(it = v.begin(); it != v.end() ; ++it){
				int x = *it;
				if(x == i) continue;
				if(mixed[x] == 0) mixed[x] = 1;
			}
		}
	}
	cout<<d<<endl;
	return 0;
}
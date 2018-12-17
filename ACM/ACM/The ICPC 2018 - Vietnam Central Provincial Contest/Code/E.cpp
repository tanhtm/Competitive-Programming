#include <bits/stdc++.h>
using namespace std;
int n;
typedef pair < int , int > ii;
ii c[200002];
int main(){
	//freopen("data.txt","r",stdin);
	//freopen("dataOut.txt","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		int x,w;
		cin>>x>>w;
		c[i] = ii(x,w);
	}
	sort(c,c+n);
	int r= c[0].second + c[0].first;
	int d  = 1;
	for(int i=1;i<n;i++){
		int x = c[i].first,w = c[i].second;
		if(x + w <= r) r = x + w;
		if(x - w >= r){
			d++;
			r = x+w;
		}
	}
	cout<<d<<endl;
	return 0;
}
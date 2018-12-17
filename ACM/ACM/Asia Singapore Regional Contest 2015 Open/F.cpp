#include <bits/stdc++.h>
using namespace std;
typedef pair < int, int > ii;
static int a[202];
ii h[101];
int main(){
	//freopen("data.txt","r",stdin);
	//freopen("dataOut.txt","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int l,r;
		cin>>l>>r;
		h[i] = ii(r,l);
	}
	sort(h,h+n);
	int x = 0;
	int d = 0;
	for(int i=0;i<n;i++){
		if(x < h[i].second){
			x = h[i].first;
			d++;
		}
	}
	cout<<d<<endl;
	return 0;
}
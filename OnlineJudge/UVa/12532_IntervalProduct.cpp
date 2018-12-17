#include <bits/stdc++.h>
using namespace std;
int n,k;
int X[100005];
struct node
{
	int sNega, sZero;
	node(){
		sNega = sZero = 0;
	}
	void print(){
		cout<<sZero<<" "<<sNega<<endl;
	}
};
vector < node > st;
void init(int id, int l, int r){
	if(l == r){
		if(X[l] < 0) st[id].sNega++;
		if(X[l] == 0) st[id].sZero++;
		return;
	}
	int mid = (l+r)/2;
	init(2*id,l,mid);
	init(2*id+1,mid+1,r);
	st[id].sNega = st[2*id].sNega + st[2*id+1].sNega;
	st[id].sZero = st[2*id].sZero + st[2*id+1].sZero;
	/*cout<<l<<" "<<r<<endl;
	st[id].print();
	cout<<endl;*/
}
void update(int id, int l, int r, int i, int v){
	//cout<<l<<" "<<r<<endl;
	if(i > r || i < l) return;
	if(l == r){
		//cout<<X[i]<<endl;
		//st[id].print();
		if(X[i] < 0) st[id].sNega--;
		if(X[i] == 0) st[id].sZero--;
		X[i] = v;
		if(v < 0) st[id].sNega++;
		if(v == 0) st[id].sZero++;
		/*cout<<l<<" "<<r<<endl;
		st[id].print();*/
		return;
	}
	int mid = (l+r)/2;
	update(id*2,l,mid,i,v);
	update(id*2+1,mid+1,r,i,v);
	st[id].sNega = st[2*id].sNega + st[2*id+1].sNega;
	st[id].sZero = st[2*id].sZero + st[2*id+1].sZero;
	/*cout<<l<<" "<<r<<endl;
	st[id].print();
	cout<<endl;*/
}
node get(int id, int l, int r, int u, int v){
	if(l >= u && r<= v) return st[id];
	if(r < u || l > v) return node();
	int mid = (l+r)/2;
	node x = get(id*2,l,mid,u,v);
	node y = get(id*2+1,mid+1,r,u,v);
	node z;
	z.sNega = x.sNega + y.sNega;
	z.sZero = x.sZero + y.sZero;
	return z;
}
int main(){
	/*freopen("data.txt","r",stdin);
	freopen("dataOut.txt","w",stdout);*/
	while(cin>>n>>k){
		st.assign(n*4,node());
		for(int i=0;i<n;i++) cin>>X[i];
		init(1,0,n-1);
		for(int i=0;i<k;i++){
			char c;
			int u, v;
			cin>>c>>u>>v;
			if(c == 'C') update(1,0,n-1,u-1,v);
			else{
				node x = get(1,0,n-1,u-1,v-1);
				if(x.sZero != 0) cout<<'0';
				else 
					if(x.sNega %2 != 0) cout<<'-';
				    else 
				    	cout<<'+';
			}
		}
		cout<<endl;
	}
	return 0;
}
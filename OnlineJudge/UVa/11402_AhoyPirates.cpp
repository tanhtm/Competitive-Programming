#include <bits/stdc++.h>
using namespace std;
string s;
int n;
vector < int > st;
vector < char > lazy;
void init(int id, int l, int r){
	if(l == r){
		if(s[l] == '1') st[id]++;
		return;
	}
	int mid = (l+r)/2;
	init(2*id,l,mid);
	init(2*id+1,mid+1,r);
	st[id] = st[2*id] + st[2*id+1];
}
void Lazy(int id, int l, int r){
	int mid= (l+r)/2;
	char c = lazy[id]; lazy[id] = '*';
	if(c == '*') return;
	if(c == 'E'){
		st[2*id] = 0;
		st[2*id+1] = 0;
		lazy[2*id] = lazy[2*id + 1] = 'E'; 
	}
	if(c == 'F'){
		st[2*id] = mid - l + 1;
		st[2*id+1] = r - (mid + 1) + 1;
		lazy[2*id] = lazy[2*id + 1] = 'F';
	}
	if(c == 'I'){
		st[2*id] = mid - l + 1 - st[2*id];
		st[2*id+1] = r - (mid + 1) + 1 - st[2*id+1];
		if(lazy[2*id] == 'E') lazy[2*id] = 'F';
		else 
			if(lazy[2*id] == 'F') lazy[2*id] = 'E';
			else 
				if(lazy[2*id] == 'I') lazy[2*id] = '*';
				else lazy[2*id] = 'I';
		if(lazy[2*id+1] == 'E') lazy[2*id+1] = 'F';
		else 
			if(lazy[2*id+1] == 'F') lazy[2*id+1] = 'E';
			else 
				if(lazy[2*id+1] == 'I') lazy[2*id+1] = '*';
				else lazy[2*id+1] = 'I';
	}
}
void update(int id, int l, int r, char c, int a, int b){
	//cout<<id<<endl;
	if(l >= a && r <= b){
		if(c == 'F') st[id] = r - l + 1;
		if(c == 'E') st[id] = 0;
		if(c == 'I') st[id] = r - l + 1 - st[id];
		if(c == 'E' || c == 'F') lazy[id] = c;
		else{
			if(lazy[id] == 'E') lazy[id] = 'F';
			else 
				if(lazy[id] == 'F') lazy[id] = 'E';
				else 
					if (lazy[id] == 'I') lazy[id] = '*';
					else lazy[id] = 'I';
		}
		return;
	}
	if(l > b || r < a) return;
	Lazy(id,l,r);
	int mid= (l+r)/2;
	update(2*id,l,mid,c,a,b);
	update(2*id+1,mid+1,r,c,a,b);
	st[id] = st[id*2] + st[id*2+1];
}
int get(int id, int l, int r, int a, int b){
	if(l > b || r < a) return 0;
	if(l >= a && r <= b){
		return st[id];
	}
	int mid= (l+r)/2;
	Lazy(id,l,r);
	int x = get(2*id,l,mid,a,b);
	int y = get(2*id+1,mid+1,r,a,b);
	return x+y;
}
void solve(){
	n = s.size();
	//cout<<s<<endl;
	st.assign(4*n,0);
	lazy.assign(4*n,'*');
	init(1,0,n-1);
	int q;
	cin>>q;
	int d = 1;
	for(int i=1;i<=q;i++){
		char c;
		int a,b;
		cin>>c>>a>>b;
		if(c != 'S') {
			update(1,0,n-1,c,a,b);
		}
		else cout<<"Q"<<d++<<": "<<get(1,0,n-1,a,b)<<endl;
	}
}
int main(){
	/*freopen("data.txt","r",stdin);
	freopen("dataOut.txt","w",stdout);*/
	int t;
	cin>>t;
	for(int i = 1;i<=t;i++){
		cout<<"Case "<<i<<":"<<endl;
		int m,T;
		s = "";
		string S;
		cin>>m;
		while(m--){
			cin>>T>>S;
			while(T--) s+=S;
		}
		solve();
	}
	return 0;
}
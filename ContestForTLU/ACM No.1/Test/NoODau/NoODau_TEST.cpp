#include <bits/stdc++.h>
using namespace std;
int n, A[1000006], q;
int Find(int x, int l, int r){
	if(l == r){
		if(A[l] == x) return l;
		return l;
	}
	int mid = (l+r)/2;
	if(A[mid] < x) return Find(x,mid+1,r);
	return Find(x,l,mid); // A[mid] >= x
}
void solve(string s){
	//cin>>n>>q;
	string f = "test/" + s, fin = ".in", fout = ".out";
	fin = f + fin; fout =f + fout;
	ofstream foi(fin.c_str());
	ofstream foo(fout.c_str());
	n = rand() % 100000 + 1;
	q = rand() % 100000 + 1; 
	foi<<n<<" "<<q<<endl;
	for(int i=1;i<=n;i++) {
		A[i] = rand()% 1000000 + 1;
	}
	A[0] = 0;
	sort(A,A+n+1);
	for(int i=1;i<=n;i++){
		foi<<A[i]<<" ";
	}
	foi<<endl;
	for(int i=0;i<q;i++){
		int x = rand()% 1000000 + 1;
		//cin>>x;
		foi<<x<<" ";
		foo<<Find(x,1,n)<<endl;
	}	
	foi<<endl;
	foi.close();
	foo.close();
}
int main(){
	srand (time(NULL));
	for(int i=91;i<=100;i++){
		cout<<i<<endl;
		solve(to_string(i));
	}
	return 0;
}
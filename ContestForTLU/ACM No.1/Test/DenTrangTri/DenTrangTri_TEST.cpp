#include <bits/stdc++.h>
using namespace std;
int n,t;
int A[1000006];
void solve(string s){
	string f = "test/" + s, fin = ".in", fout = ".out";
	fin = f + fin; fout =f + fout;
	ofstream foi(fin.c_str());
	//cin>>n>>t;
	n = rand() % 1000000 + 1;
	t = rand() % 100000 + 1;
	foi<<n<<" "<<t<<endl;
	memset(A,0,sizeof A);
	for(int i=0;i<t;i++){
		int a,b;
		//cin>>a>>b;
		b = rand()% n + 1;
		a = rand()% b + 1;
		foi<<a<<" "<<b<<endl;
		A[a]++; A[b+1]--;
	}
	foi.close();
	int res = 0;
	for(int i=1;i<=n;i++){
		A[i] += A[i-1];
		if(A[i] % 3 == 0) res++;
		//cout<<A[i]<<" ";
	}
	ofstream foo(fout.c_str());
	foo<<res<<endl;
	foo.close();
}
int main(){
	srand (time(NULL));
	for(int i=1;i<=100;i++){
		cout<<i<<endl;
		solve(to_string(i));
	}
	return 0;
}
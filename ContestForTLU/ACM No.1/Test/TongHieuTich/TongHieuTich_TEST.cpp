#include <bits/stdc++.h>
using namespace std;
void solve(string s){
	int t;
	//cin>>t;
	string f = "test/" + s, fin = ".in", fout = ".out";
	fin = f + fin; fout =f + fout;
	ofstream foi(fin.c_str());
	t = rand()% 1000 + 1;
	cout<<t<<endl;
	foi<<t<<endl;
	ofstream foo(fout.c_str());
	while(t--){
		float p,q;
		//cin>>p>>q;
		p = rand()% 1000+ 1;
		q = rand()% 1000+ 1;
		int b1 = rand()% 2;
		if(b1) p*= -1;
		int b2 = rand()% 2;
		if(b2) q*= -1;
		foi<<p<<" "<<q<<endl;
		float a = (p+q)/2;
		float b = p - a;
		foo<<int(a*b)<<endl; 

	}
	foi.close();
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
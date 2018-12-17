#include <bits/stdc++.h>
using namespace std;
int n,m;
void solve(string s){
	//cin>>n>>m;
	string f = "test/" + s, fin = ".in", fout = ".out";
	fin = f + fin; fout =f + fout;
	ofstream foi(fin.c_str());
	m = rand() % 1000000000 + 1;
	n = rand() % (m/2) + 1;
	foi<<n<<" "<<m<<endl;
	foi.close();
	ofstream foo(fout.c_str());
	if(m % 2 != 0){
		foo<<-1<<endl;
		foo.close();
		return;
	}
	int x,y;
	y = m/2 - n;
	x = n - y;
	if(y < 0 || x < 0){
		foo<<-1<<endl;
		foo.close();
		return;
	}
	foo<<x<<" "<<y<<endl;
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
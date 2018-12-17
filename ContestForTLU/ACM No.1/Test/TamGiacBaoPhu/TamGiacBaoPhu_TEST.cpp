#include <bits/stdc++.h>
using namespace std;
const int Max = 1e6;
void solve(string s){
	string f = "test/" + s, fin = ".in", fout = ".out";
	fin = f + fin; fout =f + fout;
	ofstream foi(fin.c_str());
	int n;
	n = rand() % 100000 + 1;
	foi<<n<<endl;
	long long int M = 0;
	for(int i=0;i<n;i++){
		long long int x,y;
		x = rand()%Max + 1;
		y = rand()%Max + 1;
		foi<<x<<" "<<y<<endl;
		M = max(M, x+y);
	}
	foi.close();
	ofstream foo(fout.c_str());
	foo<<M<<endl;
	foo.close();
}
int main(){
	srand (time(NULL));
	for(int i=76;i<=100;i++){
		cout<<i<<endl;
		solve(to_string(i));
	}
	return 0;
}
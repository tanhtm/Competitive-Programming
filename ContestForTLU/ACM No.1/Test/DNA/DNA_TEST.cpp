#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int A[1000006],B[1000006];
void Rand(){
	n = rand()%1000000 + 1;
	s = "";
	for(int i = 0;i<n;i++){
		int x = rand()%2;
		if(x) s+='A';
		else s+='B';
	}
}
void solve(string str){
	Rand();
	string f = "test/" + str, fin = ".in", fout = ".out";
	fin = f + fin; fout =f + fout;
	ofstream foi(fin.c_str());
	foi<<n<<endl<<s<<endl;
	//cout<<n<<endl<<s<<endl;
	foi.close();
	s = '.' + s;
	A[0] = B[0] = 0;
	for(int i=1;i<=n;i++){
		if(s[i] == 'A'){
			A[i] = A[i-1];
			B[i] = min(B[i-1] + 1, A[i-1] + 1);
		}else{
			B[i] = B[i-1];
			A[i] = min(A[i-1] + 1, B[i-1] + 1);
		}
	}
	ofstream foo(fout.c_str());
	foo<<A[n]<<endl;
	foo.close();
}
int main(){
	srand (time(NULL));
	for(int i=1;i<=100;i++){
		//cout<<i<<endl;
		solve(to_string(i));
	}
	return 0;
}
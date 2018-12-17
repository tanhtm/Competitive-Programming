#include <bits/stdc++.h>
using namespace std;
long long int n;
int R[50],L[50];
vector < int > l,r;
const long long int Max = 1e9;
void Rand(){
	n = rand() %Max + 1;
	//n*= 1e9;
	//cout<<n<<endl;
}
void solve(string s){
	Rand();
	//cin>>n;
	string f = "test/" + s, fin = ".in", fout = ".out";
	fin = f + fin; fout =f + fout;
	ofstream foi(fin.c_str());
	foi<<n<<endl;
	foi.close();
	///////////////
	for(int i=0;i<50;i++) R[i]= L[i] = 0;
	l.clear(); r.clear();
	int sz= 0;
	while(n != 0){
		R[sz] = n%3;
		sz++; n/=3;
	}
	for(int i= 0;i< sz;i++){
		if(R[i] <= 1) continue;
		if(R[i] == 2) L[i]++;
		R[i] = 0;
		R[i+1]++;
	}
	for(int i=0;i<50;i++){
		if(R[i] != 0) r.push_back(i);
		if(L[i] != 0) l.push_back(i);
	}
	////////////////////
	ofstream foo(fout.c_str());
	if(l.size() == 0) foo<<-1;
	else for(int i=0;i<l.size();i++) foo<<l[i]<<" ";
	foo<<endl;
	for(int i=0;i<r.size();i++) foo<<r[i]<<" ";
	foo<<endl;
	foo.close();
}
int main(){
	srand (time(NULL));
	for(int i=60;i<=100;i++){
		cout<<i<<endl;
		solve(to_string(i));
	}
	return 0;
}
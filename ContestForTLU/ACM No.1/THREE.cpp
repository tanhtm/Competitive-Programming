#include <bits/stdc++.h>
using namespace std;
long long int n;
int R[50],L[50];
vector < int > l,r;
int main(){
	cin>>n;
	for(int i=0;i<50;i++) R[i]= L[i] = 0;
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
	if(l.size() == 0) cout<<-1;
	else for(int i=0;i<l.size();i++) cout<<l[i]<<" ";
	cout<<endl;
	for(int i=0;i<r.size();i++) cout<<r[i]<<" ";
	cout<<endl;
	return 0;
}
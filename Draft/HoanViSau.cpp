#include <bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	map < string , int > M;
	sort(s.begin(), s.end());
	int d = 1;
	cout<<endl;
	cout <<s<<endl;
	M[s] = 1;
	while(next_permutation(s.begin(),s.end())){
		if(M[s]) continue;
		else{
			d++;
			cout<<s<<endl;
			M[s] = 1;
		}
	}
	cout<<d<<endl;
	
	return 0;
}
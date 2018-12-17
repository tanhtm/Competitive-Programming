#include <bits/stdc++.h>
using namespace std;
string s;
int B[27];
int main(){
	freopen("B.INP","r",stdin);
	//freopen("PALIN.OUT","w",stdout);
	cin>>s;
	int lr, rr;
	int nr = 0;
	int n = s.size();
	for(int i= 0;i<n;i++){
		memset(B,0,sizeof B);
		int R = 0;
		for(int j = i;j<n;j++){
			if(B[s[j]-'A'] == 0){
				R++;
				B[s[j]-'A']++;
			}else{ 
				if(nr == R){
					if(s[lr] > s[i]){
						lr = i; rr = j-1;
					}
				}
				if(nr < R){
					lr = i; rr = j-1;
					nr = R;
				}
				if(B[s[j]-'A'] == 1) R--;
				B[s[j]-'A']++;
			}
			//cout<<R<<endl;
		}
		if(nr < R){
			lr = i; rr = n-1;
			nr = R;
		}
		/*for(int j = lr; j<=rr; j++) cout<<s[j];
		cout<<endl;
		cout<<nr<<endl;*/
	}
	for(int j = lr; j<=rr; j++) cout<<s[j];
	cout<<endl;
	//cout<<nr<<endl;
	return 0;
}
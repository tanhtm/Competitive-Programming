#include <bits/stdc++.h>
using namespace std;
int n,k;
int x[13],y[13];
vector < string > C; // Mang to hop
void reset(){
	C.clear();
}
void GeneC(int n, int k, string f){
	if(n == k) {
		C.push_back(f+string(k,'1'));
		return;
	}
	if(k == 0){
		C.push_back(f+string(n,'0'));
		return;
	}
	GeneC(n-1,k-1,f+'1');
	GeneC(n-1,k,f+'0');
}
int getDist(int i, int j){
	return abs(x[i] - x[j]) + abs(y[i] - y[j]);
}
int solve(string stt){ // min
	int r = 0;
	for(int i=0;i<n;i++){
		if(stt[i] == '0'){
			int Min = 1e9;
			for(int j= 0;j<n;j++){
				if(stt[j] == '1')
					Min = min(getDist(i,j),Min);
			}
			r += Min;
		}
	}
	return r;
}
void Rand(){
	n = rand()%12 + 1;
	k = rand()%n + 1;
	for(int i=0;i<n;i++){
		x[i] = rand()%100;
		int dx = rand()%2;
		if(!dx) x[i]*= -1;
		y[i] = rand()%100;
		int dy = rand()%2;
		if(!dy) y[i]*= -1;
	}
}
void run(string s){
	reset();
	Rand();
	string f = "test/" + s, fin = ".in", fout = ".out";
	fin = f + fin; fout =f + fout;
	//cout<<fin<<" "<<fout<<endl;
	ofstream foi(fin.c_str());
	foi<<n<<" "<<k<<endl;
	for(int i=0 ;i< n;i++){
		foi<<x[i]<<" "<<y[i]<<endl;
	}
	foi.close();
	/*cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>x[i]>>y[i];
	}*/
	GeneC(n,k,"");
	//cout<<C.size()<<endl;
	int ans = 1e9;
	for(int i= 0;i< C.size();i++){
		//cout<<C[i]<<endl;
		ans = min(ans,solve(C[i]));
	}
	ofstream foo(fout.c_str());
	foo<<ans<<endl;
	foo.close();
}
int main(){
	srand (time(NULL));
	for(int i=1;i<=50;i++){
		cout<<i<<endl;
		run(to_string(i));
	}
	return 0;
}
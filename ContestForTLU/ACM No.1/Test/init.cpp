#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("init.yml","w",stdout);
	cout<<"archive: tests.zip\n";
	cout<<"test_cases:\n";
	for(int i=1;i<=100;i++){
		cout<<"- {in: "<<i<<".in, out: "<<i<<".out, points: 1}\n";
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
int n;
int X[101],Y[101];
int rx,ry;
int main(){
	int d = 1;
	freopen("data.txt","r",stdin);
	while(true){
		cin>>n;
		if(!n) break;
		cout<<"Floor #"<<d<<endl;
		d++;
		for(int i=0;i<n;i++) cin>>X[i]>>Y[i];
		rx = X[0]; ry = Y[0];
		bool fl = 1;
		for(int i= 1;i<n;i++){
			int vx1 = X[i] - rx, vy1 = Y[i] - ry;
			int id = 1;
			int j = 1;
			double maxAl = 0;
			while(j != 4){
				int x = X[(i+j)%n], y = Y[(j+i)%n];
				int vx2 = x - X[i], vy2 = y - Y[i];
				int dot = vx2*vx1 + vy2*vy1;
				double dv1 = sqrt(vx1*vx1 + vy1*vy1);
				double dv2 = sqrt(vx2*vx2 + vy2*vy2);
				double dv = dv1*dv2;
				double alpha = acos(dot/dv);
				//alpha = abs(alpha);
				cout<<int((alpha/3.14)*180)<<" ";
				if(maxAl < alpha){ 
					id = j;
					maxAl = alpha;
				}
				j++;
			}
			/*if(id == 3){
				fl = 0;
				cout<<"Surveillance is impossible."<<endl;
				break;
			}*/
			rx = X[i]; ry = Y[i];
			cout<<endl;
		}
		if(fl) cout<<"Surveillance is possible."<<endl;
	}
	return 0;
}
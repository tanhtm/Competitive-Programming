#include<iostream>
using namespace std;
int n,a,b;
int main(){
	cin>>n;
    for(int i=0 ;i< n;i++){
    	cin>>a>>b;
    	if(a>b) cout<<">";
    	else if(a < b) cout<<"<";
    		else cout<<"=";
    	cout<<endl;
    }
    return 0;
}
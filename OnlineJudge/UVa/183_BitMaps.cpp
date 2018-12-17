#include <iostream>
#include <string>
using namespace std;
char C;
int rows,columns;
string s;
char bitMap[200][200];
int K = 0;
string solveBtoD(int rb, int re, int cb, int ce){
	if(rb == re && cb == ce) return string() + bitMap[rb][cb];
	int midr = (rb+re)/2, midc = (cb + ce)/2;
	string a,b,c,d;
	if(rb == re){
		c = solveBtoD(rb,re,cb,midc);
		d = solveBtoD(rb,re,midc+1,ce);
		if(c == d)
			if(c.size() == 1) return c;
		return 'D' + c + d;
	}
	if(cb == ce){
		a = solveBtoD(rb,midr,cb,ce);
		b = solveBtoD(midr+1,re,cb,ce);
		if(a == b)
			if(a.size() == 1) return a;
		return 'D' + a + b;
	}
	a = solveBtoD(rb,midr,cb,midc);
	b = solveBtoD(rb,midr,midc+1,ce);
	c = solveBtoD(midr+1,re,cb,midc);
	d = solveBtoD(midr+1,re,midc+1,ce);
	if(a == b && b == c && c == d && a.size() == 1) return a;
	return 'D'+ a+ b+ c+ d;
}
void BtoD(){
	int d = 0;
	for(int i = 0;i< rows;i++){
		for(int j= 0; j <columns;j++){
			bitMap[i][j] = s[d];
			d++;
		}
	}
	cout<<solveBtoD(0,rows-1,0,columns-1)<<endl;
}
void solveDtoB(int rb, int re, int cb, int ce){
	if(rb > re || cb > ce) return;
	if(s[K] != 'D'){
		for(int x = rb;x<=re;x++){
			for(int y = cb;y<=ce;y++){
				bitMap[x][y] = s[K];
			}
		}
	}else{
		int midr = (rb+re)/2, midc = (cb + ce)/2;
		K++;
		solveDtoB(rb,midr,cb,midc);
		if(midc < ce){
			solveDtoB(rb,midr,midc+1,ce);
		}
		if(midr < re){
			solveDtoB(midr+1,re,cb,midc);
		}
		if(midr < re && midc < ce) solveDtoB(midr+1,re,midc+1,ce);
	}
}
void DtoB(){
	K = 0;
	solveDtoB(0,rows-1,0,columns-1);
	for(int i=0;i<rows;i++){
		for(int j=0;j<columns;j++){
			cout<<bitMap[i][j];
		}
	}
	cout<<endl;
}
int main(){
	//freopen("data.txt","r",stdin);
	//freopen("dataOut.txt","w",stdout);
	while(cin>>C && C!= '#'){
		cin>>rows>>columns>>s;
		if(C == 'B') BtoD();
		else DtoB();
	}
	return 0;
}
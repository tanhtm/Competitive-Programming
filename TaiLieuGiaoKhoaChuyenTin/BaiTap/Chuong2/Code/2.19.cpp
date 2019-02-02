// Tìm số ước, tổng ước của N! (N < 100)
#include <bits/stdc++.h>
using namespace std;
int fac[101];
vector < int > prime;
void ifactor(int n){
    int i = 2;
    while(n != 1){
        while(n%i) i++;
        while(n%i == 0){
            n/= i;
            fac[i]++;
        }
    }
}
int main(){
    memset(fac,0,sizeof fac);
    int n;
    cin>>n;
    for(int i=2;i<=n;i++) ifactor(i);
    int a = 1, b = 1;
    for(int i=2;i<=100;i++){
        a*= fac[i] + 1;
        b*= (pow(i,fac[i]+1)-1)/(i-1);
    }
    cout<<a<<endl<<b<<endl;

    return 0;
}
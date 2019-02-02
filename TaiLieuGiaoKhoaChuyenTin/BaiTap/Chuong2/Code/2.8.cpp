//Tìm k chữ số cuối cùng của M^N (0< K <= 9, 0 <= M, N <= 10^6 )
#include <bits/stdc++.h>
using namespace std;
long long int powMod(int m, int n, int mod){
    if(n == 0) return 1;
    long long int r = powMod(m,n/2,mod);
    r*=r;
    r%= mod;
    if(n%2) r*= m;
    return r%mod;
}
int main(){
    int k,m,n,k_;
    cin>>k>>m>>n;
    k_ = k;
    int mod = 1;
    while(k--) mod*= 10;
    int r = powMod(m,n,mod);
    string s = to_string(r);
    s = string(k_- s.size(),'0') + s;
    cout<<s<<endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int n,m;
string g,s;
const int Max = 26+ 26 + 1;
int mg[Max], ms[Max];
int getId(char c){
    if(c >= 'a' && c <= 'z') return c - 'a';
    return c - 'A' + 26;
}
bool check(){
    for(int i=0;i<52;i++)
        if(ms[i] != mg[i]) return false;
    return true;
}
int main(){
    //cin>>n>>m;
    cin>>g>>s;
    n= g.size(); m= s.size();
    for(int i=0;i<52;i++) ms[i] = mg[i] = 0;
    for(int i=0;i<n;i++) mg[getId(g[i])]++;
    for(int i=0;i<n;i++) ms[getId(s[i])]++;
    int d = 0;
    bool fl = 0;
    if(check()){
        d  = 1;
        fl = 1;
    }
    for(int i=n;i<m;i++){
        ms[getId(s[i-n])]--;
        ms[getId(s[i])]++;
        if(fl == 1){
            if(s[i] == s[i-n]) d++;
            else fl = 0;
        }else{
            if(ms[getId(s[i])] != mg[getId(s[i])]) continue;
            if(ms[getId(s[i-n])] != mg[getId(s[i-n])]) continue;
            bool b = check();
            if(b){
                fl = 1;
                d++;
            }
        }
    }
    cout<<d<<endl;
    return 0;
}
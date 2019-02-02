// Cân vật nặng N với các quả cân 3^i, N <= 10^100
#include <bits/stdc++.h>
using namespace std;
typedef pair < string , int > qr;
string n;
vector < int > base3;
qr div3(string s){
    string q;
    int r = 0;
    for(int i=0;i<s.size();i++){
        int x = s[i]-'0'+r*10;
        q+= x/3 + '0';
        r= x%3;
    }
    if(q[0] == '0' && q.size() > 1) q.erase(q.begin());
    return qr(q,r);
}
void pre(){
    while(n != "0"){
        qr QR = div3(n);
        n = QR.first;
        base3.push_back(QR.second);
    }
}
int main(){
    cin>>n;
    pre();
    vector < int > left, right;
    base3.push_back(0);
    for(int i=0;i<base3.size();i++){
        int x = base3[i];
        if(x == 1) left.push_back(i);
        if(x == 2){
            right.push_back(i);
            base3[i+1]++;
        }
        if(x == 3) base3[i+1]++;
    }
    for(int i=0;i<left.size();i++) cout<<left[i]<<" ";
    cout<<endl;
    for(int i=0;i<right.size();i++) cout<<right[i]<<" ";
    cout<<endl;
    return 0;
}
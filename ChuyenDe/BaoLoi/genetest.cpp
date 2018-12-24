#include <bits/stdc++.h>
using namespace std;

double frand(double fmin, double fmax){
    double f = (double)rand()/RAND_MAX;
    return fmin + f*(fmax - fmin);
}
int main(){
    freopen("input.txt","w",stdout);
    srand (time(NULL));
    int n= 100;
    cout<<n<<endl;
    for(int i=0;i<n;i++){
        double fx, fy;
        fx = frand(-100,100);
        fy = frand(-100,100);
        cout<<fx<<" "<<fy<<endl;
    }
    return 0;
}
//https://open.kattis.com/problems/convexhull
#include <bits/stdc++.h>
using namespace std;
struct point{
    double x,y;
};
bool operator < (point a, point b){
    if(a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}
bool operator == (point a, point b){
    return a.x == b.x && a.y == b.y;
}
int n;
point Points[10005];
bool isLeft(point a, point b, point c){ // Đang đi từ a -> b, từ b -> c có phải rẽ trái không ?
    double d = (b.x - a.x)*(c.y - b.y) - (b.y - a.y)*(c.x - b.x);
    return d < 0;
}
void solveConvexHull(){

    sort(Points,Points + n);
    point pU = Points[0], pD = Points[n-1];
    vector < point > Up,Down;
    // Thêm vào nửa trên
    for(int i=0;i<n;i++){
        if(i > 0 && Points[i] == Points[i-1]) continue;
        while(Up.size() >= 2 && isLeft(Up[Up.size()-2],Up[Up.size()-1],Points[i]))
            Up.pop_back();
        Up.push_back(Points[i]);
    }
    // Thêm vào nửa dưới
    for(int i=n-1;i>=0;i--){
        if(i < n-1 && Points[i] == Points[i+1]) continue;
        while(Down.size() >=2 && isLeft(Down[Down.size()- 2],Down[Down.size()-1],Points[i])) 
            Down.pop_back();
        Down.push_back(Points[i]);
    }
    int sz = Up.size() + Down.size() - 2;
    if(sz > 0) cout<<sz<<endl;
    else cout<<1<<endl;
    for(int i=0;i<Up.size();i++)
        cout<<Up[i].x<<" "<<Up[i].y<<endl;
    for(int i=1;i<Down.size()-1;i++)
        cout<<Down[i].x<<" "<<Down[i].y<<endl;
};
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++) cin>>Points[i].x>>Points[i].y;
    solveConvexHull();
    return 0;
}
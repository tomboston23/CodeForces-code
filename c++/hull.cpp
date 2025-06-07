#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
struct pt {
    int x;
    int y;
};

const int ccw = -1;
const int cw = 1;

int orientation(pt a, pt b, pt c) { // from cp-algorithms.com
    double v = a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y);
    if (v < 0) return ccw; // clockwise
    if (v > 0) return cw; // counter-clockwise
    return 0;
}

bool comp(pt p, pt q){

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    vector<pt> points(n);
    int left = INT_MAX;
    pt leftmost;
    int l;
    for(int i = 0; i < n; i++){
        cin >> points[i].x >> points[i].y;
        if (points[i].x < left){
            left = points[i].x;
            l = i;
        }
    }

    

    return 0;
}
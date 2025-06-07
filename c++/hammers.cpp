#include <bits/stdc++.h>
using namespace std;

struct hammer{
    int x;
    int y;
    int r;
};

/*    
def find(c):
if dsets[c] < 0:
    return c
else:
    dsets[c] = find(dsets[c])
    return dsets[c]
*/

int find(int c, vector<int> &dset){
    if(dset[c] < 0) return c;
    else {
        dset[c] = find(dset[c], dset);
        return dset[c];
    }
}

/*
    def add(c1,c2):
        sa = find(c1)
        sb = find(c2)
        if sa == sb:
            return sa
        if dsets[sa] > dsets[sb]:
            dsets[sb] += dsets[sa]
            dsets[sa] = sb
        else:
            dsets[sa] += dsets[sb]
            dsets[sb] = sa
*/

void add(int c1, int c2, vector<int> &dset){
    int sa = find(c1, dset);
    int sb = find(c2, dset);
    if (sa == sb) return;
    if (dset[sa] > dset[sb]){
        dset[sb] += dset[sa];
        dset[sa] = sb;
    } else {
        dset[sa] += dset[sb];
        dset[sb] = sa;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int width = 200;
    int height = 300;
    
    int N;
    cin >> N;
    vector<int> dset(2, -1); // index 0 represents left wall, index 1 represents right wall
    vector<hammer> hammers;
    for(int i = 0; i < N; i++){
        int index = i+2;
        dset.push_back(-1); //instantiate set for new element;
        int x, y, r;
        cin >> x >> y >> r;
        if (x-r <= 0) add(index, 0, dset);
        if (x+r >= width) add(index, 1, dset);
        for (int j = 0; j < i; j++){
            hammer h = hammers[j];
            int j_index = j + 2;
            int dx = h.x - x;
            int dy = h.y - y;
            int sq_dist = dx*dx+dy*dy;
            int r_sum = r + h.r;
            if (sq_dist <= r_sum*r_sum){
                add(j_index, index, dset);
                // cout << "adding two hammers: " << endl;
                // cout << x << ", " << y << ", " << r << endl;
                // cout << h.x << ", " << y << ", " << r << endl; 
            }
        }

        struct hammer n;
        n.x = x; 
        n.y = y;
        n.r = r;
        hammers.push_back(n);

        // for(int k : dset){
        //     cout << k << " ";
        //     cout << endl;
        // }

        if(find(0, dset) == find(1, dset)) {
            cout << i << endl;
            return 0;
        }
    }
    cout << N << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

struct hammer{
    int x;
    int y;
    int r;
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int width = 200;
    int height = 300;
    
    int N;
    cin >> N;
    vector<vector<int>> adj_list(N*2+2);
    vector<hammer> hammers;
    for(int i = 0; i < N; i++){
        int in_idx = 2*i;
        int out_idx = 2*i+1;
        int x, y, r;
        cin >> x >> y >> r;
        if (x-r <= 0){
            adj_list[N].push_back(i);
            adj_list[i].push_back(N);
        }
        if (x+r >= width){
            adj_list[N+1].push_back(i);
            adj_list[i].push_back(N+1);
        }
        for (int j = 0; j < i; j++){
            hammer h = hammers[j];
            int j_index = j + 2;
            int dx = h.x - x;
            int dy = h.y - y;
            int sq_dist = dx*dx+dy*dy;
            int r_sum = r + h.r;
            if (sq_dist <= r_sum*r_sum){
                adj_list[i].push_back(j);
                adj_list[j].push_back(i);
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

    }
    cout << N << endl;
    return 0;
}
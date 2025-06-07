#include <bits/stdc++.h>
using namespace std;


typedef pair<int, bool> edge;
typedef vector<int> vi;
// typedef vector<edge> ve;
// typedef vector<vector<edge>> vve;
typedef vector<vi> vvi;

int INF = 1e7; // big enough to be larger than any possible value in the dp

void topo_dfs(int v, vector<bool> &visited, vector<vector<int>>& adj, vector<int> &ans) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u]) {
            topo_dfs(u, visited, adj, ans);
        }
    }
    // cout << "pushing "<< v << " into ans\n";
    ans.push_back(v);
}
 
void topological_sort(vector<bool> & visited, vector<vector<int>>& adj, vector<int> &ans, int N) {
    for (int i = 0; i < N; ++i) {
        if (!visited[i]) {
            // cout << "starting topo dfs\n";
            topo_dfs(i, visited, adj, ans);
        }
    }
}

void solve(){
    int N, M, K;
    cin >> N >> M >> K;
    vvi adj(N);

    vector<bool> marked (N, false);
    map<pair<int,int>,bool> candidate;
    
    for(int i = 0; i < N; i++){
        int idx = 0;
        int ki;
        cin >> ki;
        while(ki--){
            int a;
            cin >> a;
            a--;
            adj[i].push_back(a);
            candidate[{i,a}] = false;
            idx++;
        }
    }

    for(int i = 0; i < M; i++){
        int a,b;
        cin >> a >> b;
        a--;b--;
        candidate[{a,b}] = true;
    }

    for(int i = 0; i < K; i++){
        int a;
        cin >> a;
        marked[a-1] = true;
    }

    vector<int> dp (N,-2);
    
    // vector<vector<int>> adj; // adjacency list of graph
    vector<bool> visited(N, false);
    vector<int> ans;
    topological_sort(visited, adj, ans, N);
    // cout << ans.size() << endl;
    // for(int i = 0; i < N; i++){
    //     cout << ans[i] << " ";
    // }
    // cout << endl;

    for(int j = 0; j < N; j++){
        int i = ans[j];
        if(adj[i].empty()){
            if(!marked[i]) dp[i] = -1; // -1 means you cannot reach marked leaf
            else dp[i] = 0;
            //don't need to change marked nodes because it takes 0 to get to them
            continue;
        }
        bool good = true; // this is true as long as every possible child can reach a leaf
        int min_det = INF;
        int max_rand = 0;
        // cout << "processing i = " << i << endl;
        for(int k : adj[i]){ // we can guarantee this has already been processed
            
            if(dp[k] == -1 || dp[k] == -2) {
                max_rand += INF;
                continue;
            } // mark it as bad
            else max_rand += dp[k]; // so we add up the total number of deterministic edges needed?
            if(candidate[{i,k}])
                min_det = min(min_det, 1+dp[k]); // if we can deterministically move this way 
            // cout << k.first << ", " << max_rand << ", " << min_det << endl;
        }
        
        int res = min(min_det, max_rand); // get optimal strategy
        // cout << i << ": " << res << endl;
        if(res >= INF){
            dp[i] = -1; // not reachable
        } else {
            dp[i] = res; // choose best strategy
        }
    }
    // for(int k : dp){
    //     cout << k << " ";
    // }
    // cout << endl;
    cout << dp[0] << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        solve();
    }

    return 0;
}
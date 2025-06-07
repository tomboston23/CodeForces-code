#include <bits/stdc++.h>
using namespace std;

void dfs1(int v, vector<bool>& visited, vector<vector<int>>& adj, vector<int>& order) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u]) {
            dfs1(u, visited, adj, order);
        }
    }
    order.push_back(v);
}

int dfs2(int idx, int v, vector<bool>& visited, vector<vector<int>>& adj_rev, vector<int>& component, int d, vector<int> &vals, map<int,int> &comp) {
    visited[v] = true;
    d+=vals[v];
    component.push_back(v);
    comp[v] = idx;
    for (int u : adj_rev[v]) {
        if (!visited[u]) {
            d = dfs2(idx, u, visited, adj_rev, component, d, vals, comp);
        }
    }
    return d;
}


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
    reverse(ans.begin(), ans.end());
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        int n,m;
        cin >> n >> m;
        vector<vector<int>> adj(n);
        vector<vector<int>> adj_rev(n);
        vector<int> vals(n);
        
        for(int i = 0; i < n; i++) cin >> vals[i];
        
        for(int j = 0; j < m; j++){
            int a,b; cin >> a >> b;
            adj[a].push_back(b);
            adj_rev[b].push_back(a);
        }
        
        vector<bool> visited(n, false);
        vector<int> order;
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                dfs1(i, visited, adj, order);
            }
        }
        reverse(order.begin(), order.end());
    
        fill(visited.begin(), visited.end(), false);
        vector<vector<int>> sccs;
        vector<int> new_vals;
        map<int, int> comp; //maps each vertex to its component in constant time
        //meaning we can collect all the diamonds in one sweep
        int idx = 0;
        for (int v : order) {
            if (!visited[v]) {
                vector<int> component;
                int val = dfs2(idx, v, visited, adj_rev, component, 0, vals, comp);
                sccs.push_back(component);
                
                if(component.size()>1) {
                    new_vals.push_back(val);
                } else {
                    new_vals.push_back(min(val, 3));
                }
                idx++;
            }
        }
        
        int N = sccs.size();
        set<pair<int, int>> seen;
        vector<vector<int>> gcc_adj(N);
        for(int i = 0; i < n; i++){
            for (int j : adj[i]){
                if (comp[i] != comp[j] && seen.insert({comp[i], comp[j]}).second) {
                    gcc_adj[comp[i]].push_back(comp[j]);
                }
            }
        }
    
        // cout << "Strongly Connected Components:" << endl;
        // for (int i = 0; i < sccs.size(); i++) {
        //     auto& component = sccs[i];
        //     cout << "{ ";
        //     for (int v : component) {
        //         cout << v << " ";
        //     }
        //     cout << "} ";
        //     cout << new_vals[i] << endl;
        // }
        
        vector<bool> topo_visited(N, false);
        vector<int> ans;
        topological_sort(topo_visited, gcc_adj, ans, N);
        vector<int> dp(N, 0);
        int largest = 0;

        for(int k : ans){
            dp[k] = max(dp[k], new_vals[k]);
            for(int j : gcc_adj[k]){
                dp[j] = max(dp[j], dp[k] + new_vals[j]);
            }
        }
        for(int k : dp){
            largest = max(k, largest);
            // cout << k << " ";
        }
        // cout << endl;

        cout << largest << endl;
    }

    return 0;
}

/*
you can collect every diamond from every node in a cycle
you can exit a cycle from any node you want
SCC gives us a DAG
*/



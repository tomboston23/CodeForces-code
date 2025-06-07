#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int n;
vector<vector<int>> graph;
vector<vector<int>> dp;

int tsp(int mask, int pos) {
    if (mask == (1 << n) - 1) return 0;

    if (dp[mask][pos] != -1) return dp[mask][pos];

    int ans = INF;
    for (int next = 0; next < n; next++) {
        if (!(mask & (1 << next))) {
            ans = min(ans, graph[pos][next] + tsp(mask | (1 << next), next));
        }
    }
    return dp[mask][pos] = ans;
}

int main() {
    cin >> n;
    graph.assign(n, vector<int>(n,0));
    dp.assign(1 << n, vector<int>(n, -1));
    vector<string> words;

    for(int i = 0; i<n;i++){
        string s;
        cin >> s;
        int sz = s.size();
        words.push_back(s);
        //get paths between nodes
        for(int j = 0; j < i; j++){
            int l = words[j].size();
            if(s[0] == words[j][l-1]){
                graph[j][i] = sz;
            } else graph[j][i] = INF;
            if(words[j][0] == s[sz-1]){
                graph[i][j] = l;
            } else graph[i][j] = INF;
        }
    }
    
    //get actual shortest paths using floyd-warshall
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                graph[i][j] = min(graph[i][j], graph[i][k]+graph[k][j]);
            }
        }
    }

    int result = INF;
    //find lowest cost visit to all vertices
    for (int i = 0; i < n; i++){
        int size = words[i].size();
        result = min(result, tsp(1 << i, i) + size);
    }
    cout << result << endl;
    return 0;
}

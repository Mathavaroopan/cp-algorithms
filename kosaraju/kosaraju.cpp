#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int>& vis, vector<vector<int>>& adj, stack<int>& st) {
    vis[node] = 1;
    for (int v : adj[node]) {
        if (!vis[v]) dfs(v, vis, adj, st);
    }
    st.push(node);
}

void dfss(int node, vector<int>& vis, vector<vector<int>>& adjt, vector<int>& cur) {
    cur.push_back(node);
    vis[node] = 1;
    for (int v : adjt[node]) {
        if (!vis[v]) dfss(v, vis, adjt, cur);
    }
}

vector<vector<int>> kosaraju(int V, vector<vector<int>>& adj) {
    vector<int> vis(V, 0);
    stack<int> st;

    // Step 1: Perform DFS and store nodes in stack according to their finishing times
    for (int node = 0; node < V; node++) {
        if (!vis[node]) dfs(node, vis, adj, st);
    }

    // Step 2: Transpose the graph
    vector<vector<int>> adjt(V);
    for (int node = 0; node < V; node++) {
        for (int v : adj[node]) {
            adjt[v].push_back(node);
        }
    }

    // Step 3: Perform DFS on transposed graph in the order of finishing times
    fill(vis.begin(), vis.end(), 0); 
    vector<vector<int>> ans;
    while (!st.empty()) {
        vector<int> cur;
        int node = st.top(); st.pop();
        if (!vis[node]) {
            dfss(node, vis, adjt, cur);
            ans.push_back(cur);
        }
    }

    return ans;
}
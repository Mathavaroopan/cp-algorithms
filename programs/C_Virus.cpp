#include<bits/stdc++.h>
using namespace std;
void dfs(long long node, vector<vector<long long>>& adj, vector<bool>& vis){
    vis[node] = true;
    for(long long i : adj[node]){
        if(!vis[i]) dfs(i, adj, vis);
    }
}
int main(){
    #define int long long
    #define double long double
    int n;
    double d;
    cin >> n >> d;
    vector<vector<int>> adj(n);
    pair<int, int> arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i].first >> arr[i].second;
    }
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            int a = arr[i].first, b = arr[i].second;
            int x = arr[j].first, y = arr[j].second;
            double tempd = sqrt((a - x)*(a - x) + (b - y)*(b - y));
            if(tempd <= d){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    vector<bool> vis(n, false);
    dfs(0, adj, vis);
    for(int i = 0; i < n; i++){
        if(!vis[i]) cout << "No" << endl;
        else cout << "Yes" << endl;
    }
}
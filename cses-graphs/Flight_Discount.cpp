/* Author: Mathavaroopan */
#include "bits/stdc++.h"
#define int long long
#define double long double
#define srt(arr) sort(arr.begin(), arr.end())
#define srtrev(arr) sort(arr.begin(), arr.end(), greater<int>())
#define reverse(arr) reverse(arr.begin(), arr.end())
#define all(arr) arr.begin(), arr.end()
#define input(arr) for(int& a : arr) cin >> a
#define print(arr) for(int i : arr) cout << i << " "
#define var(a) cout << #a << " = " << a << endl
#define min(arr) *min_element(arr.begin(), arr.end())
#define sum(arr) accumulate(arr.begin(), arr.end(), 0)
#define endl '\n'
using namespace std;

const int mod = 1e9 + 7;
int inf = 1e18;

void solve(){
    int n, m; cin >> n >> m;
    vector<vector<pair<int, int>>> g(n);
    for(int i = 0; i < m; i++){
        int u, v, w; cin >> u >> v >> w; u--, v--;
        g[u].push_back({v, w});
    }
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push({0, {0, 0}});
    vector<int> dist(n, inf), tdist(n, inf), vis(n, -1);
    dist[0] = tdist[0] = 0;
    while(!pq.empty()){
        auto [cost, p] = pq.top();
        auto [node, took] = p;
        pq.pop();
        if((!took && dist[node] < cost) || (took && tdist[node] < cost)) continue;
        for(auto [v, c] : g[node]){
            if(took){
                if(tdist[v] > tdist[node] + c){
                    tdist[v] = tdist[node] + c;
                    pq.push({tdist[v], {v, 1}});
                }
            }else{
                if(tdist[v] > dist[node] + (c / 2)){
                    tdist[v] = dist[node] + (c / 2);
                    pq.push({tdist[v], {v, 1}});
                }
                if(dist[v] > dist[node] + c){
                    dist[v] = dist[node] + c;
                    pq.push({dist[v], {v, 0}});
                }
            }
        }
    }   
    cout << tdist[n - 1] << endl;
}
 
int32_t main()
{
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int T = 1;
    // cin >> T;
    while (T--) solve();
    return 0;
}
 
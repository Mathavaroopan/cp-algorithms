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
#define max(arr) *max_element(arr.begin(), arr.end())
#define sum(arr) accumulate(arr.begin(), arr.end(), 0)
#define endl '\n'
using namespace std;

const int mod = 1e9 + 7;
int inf = 1e18;

void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> arr(n);
    for(int i = 0; i < m; i++){
        int u, v, w; cin >> u >> v >> w; u--, v--;
        arr[u].push_back({v, w});
    }
    vector<int> vis(n, -1), dist(n, 1e18);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});
    dist[0] = 0;
    while(!pq.empty()){
        auto [cost, node] = pq.top();
        pq.pop();
        if(dist[node] < cost) continue;
        for(auto [x, c] : arr[node]){
            if(dist[x] > dist[node] + c){
                dist[x] = dist[node] + c;
                pq.push({dist[x], x});
            }
        }
    }
    print(dist);
}
 
int32_t main()
{
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int T = 1;
    while (T--) solve();
    return 0;
}
 
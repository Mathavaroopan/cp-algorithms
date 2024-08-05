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
    vector<string> arr(n);
    queue<pair<pair<int, int>, int>> q;
    vector<vector<int>> pos(n, vector<int>(m, -1));
    vector<vector<int>> vis(n, vector<int>(m, inf));
    int sr = -1, sc = -1;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        for(int j = 0; j < m; j++){
            if(arr[i][j] == 'M'){
                q.push({{i, j}, 0});
                vis[i][j] = 0;
            }else if(arr[i][j] == '#') vis[i][j] = -2;
            if(arr[i][j] == 'A') sr = i, sc = j;
        }
    }
    int dr[] = {0, 0, 1, -1};
    int dc[] = {1, -1, 0, 0};
    char ds[] = {'R', 'L', 'D', 'U'};
    while(!q.empty()){
        auto [p, steps] = q.front(); q.pop();
        auto [r, c] = p;
        for(int i = 0; i < 4; i++){
            int nrow = r + dr[i], ncol = c + dc[i];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == inf){
                vis[nrow][ncol] = steps + 1;
                q.push({{nrow, ncol}, steps + 1});
            }
        }
    }

    int cr = -1, cc = -1;
    q.push({{sr, sc}, 0});
    while(!q.empty()){
        auto [p, steps] = q.front(); q.pop();
        auto [r, c] = p;
        if(r == 0 || c == 0 || r == n - 1 || c == m - 1){
            cr = r, cc = c;
            break;
        }
        for(int i = 0; i < 4; i++){
            int nrow = r + dr[i], ncol = c + dc[i];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] > steps + 1 && pos[nrow][ncol] == -1){
                pos[nrow][ncol] = i;
                q.push({{nrow, ncol}, steps + 1});
            }
        }
    }
    if(cr == -1) cout << "NO" << endl;
    else{
        cout << "YES" << endl;
        string ans = "";
        while(cr != sr || cc != sc){
            int ind = pos[cr][cc];
            ans += ds[ind];
            cr -= dr[ind], cc -= dc[ind];
        }
        cout << ans.size() << endl;
        reverse(ans);
        if(ans.size() > 0) cout << ans << endl;
    }
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
 
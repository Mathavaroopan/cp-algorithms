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
int n, m;

void solve(){
    cin >> n >> m;
    vector<string> arr(n);
    vector<vector<int>> vis(n, vector<int>(m, -1));
    queue<pair<int, int>> q;
    for(auto& s : arr) cin >> s;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) if(arr[i][j] == 'A') q.push({i, j}), vis[i][j] = -2;
    }
    int dr[] = {0, 0, 1, -1};
    int dc[] = {1, -1, 0, 0};
    char dir[] = {'R', 'L', 'D', 'U'};
    int dx = -1, dy = -1;
    while(!q.empty()){
        int row = q.front().first, col = q.front().second;
        q.pop();
        if(arr[row][col] == 'B'){
            dx = row, dy = col;
            break;
        }
        for(int i = 0; i < 4; i++){
            int nrow = row + dr[i], ncol = col + dc[i];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && arr[nrow][ncol] != '#' && vis[nrow][ncol] == -1){
                vis[nrow][ncol] = i;
                q.push({nrow, ncol});
            }
        }
    }

    if(dx == -1) cout << "NO";
    else{
        cout << "YES" << endl;
        string ans = "";
        int cr = dx, cc = dy;
        while(vis[cr][cc] != -2){
            int temp = vis[cr][cc];
            ans += dir[temp];
            cr -= dr[temp], cc -= dc[temp];
        }
        cout << ans.size() << endl;
        reverse(ans);
        cout << ans << endl;
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
 
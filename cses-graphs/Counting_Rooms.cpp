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
vector<vector<char>> arr(1000, vector<char>(1000));
vector<vector<int>> vis(1000, vector<int>(1000, 0));    
int n, m;

void dfs(int row, int col){
    vis[row][col] = 1;
    if(row + 1 < n && !vis[row + 1][col] && arr[row + 1][col] == '.') dfs(row + 1, col);
    if(row - 1 >= 0 && !vis[row - 1][col] && arr[row - 1][col] == '.') dfs(row - 1, col);
    if(col + 1 < m && !vis[row][col + 1] && arr[row][col + 1] == '.') dfs(row, col + 1);
    if(col - 1 >= 0 && !vis[row][col - 1] && arr[row][col - 1] == '.') dfs(row, col - 1);
}

void solve(){
    cin >> n >> m;
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) cin >> arr[i][j];
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!vis[i][j] && arr[i][j] == '.'){
                ans++;
                dfs(i, j);
            }
        }
    }
    cout << ans << endl;
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
 
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
    int n, m; cin >> n >> m;
    vector<pair<int, int>> arr(n + m + 1);
    for(int i = 0; i < n + m + 1; i++) cin >> arr[i].first;
    for(int i = 0; i < n + m + 1; i++) cin >> arr[i].second;
    int ans = 0, prob = n + m, type = -1, cn = n, cm = m;
    vector<int> pos(n + m + 1);
    for(int i = 0; i < n + m; i++){
        if(arr[i].first > arr[i].second){
            if(cn > 0){
                ans += arr[i].first, cn--, pos[i] = 1;
                continue;
            }
            else if(type == -1) type = 1, prob = i;
            ans += arr[i].second, pos[i] = 2;
        }else{
            if(cm > 0){
                ans += arr[i].second, cm--, pos[i] = 2;
                continue;
            }
            else if(type == -1) type = 2, prob = i;
            ans += arr[i].first, pos[i] = 1;
        }
    }
    for(int i = 0; i < n + m; i++){
        int newans = ans - (pos[i] == 1 ? arr[i].first : arr[i].second);
        if(pos[i] == type){
            newans += (type == 1 ? arr[prob].first + arr.back().second - arr[prob].second : arr[prob].second + arr.back().first - arr[prob].first);
        }else newans += (pos[i] == 1 ? arr.back().first : arr.back().second);
        cout << newans << " ";
    }
    cout << ans << endl;
}
 
int32_t main()
{
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}
 
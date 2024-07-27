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
#define sum(arr) accumulate(arr.begin(), arr.end(), 0)
#define endl '\n'
using namespace std;

const int mod = 1e9 + 7;
int inf = 1e18;

bool compare(pair<int, int> p, pair<int, int> q){
    return p.first < q.first || (p.first == q.first && p.second < q.second);
}

void solve(){
    int n;
    cin >> n;
    vector<pair<int, int>> arr(2 * n);
    for(int i = 0; i < 2 * n; i++){
        cin >> arr[i].first;
        arr[i].second = (i >= n) ? 2 : 1;
    }
    sort(arr.begin(), arr.end(), compare);
    vector<int> a1, a2, b1, b2;
    for(int i = 0; i < 2 * n; i++){
        if(i < n){
            if(arr[i].second == 1) a1.push_back(arr[i].first);
            else a2.push_back(arr[i].first);
        }else{
            if(arr[i].second == 1) b2.push_back(arr[i].first);
            else b1.push_back(arr[i].first);
        }
    }
    int ans = 1e9;
    for(int i = 0; i < (int) a1.size(); i++) ans = min(ans, b1[i] - a1[i]);
    for(int i = 0; i < (int) a2.size(); i++) ans = min(ans, b2[i] - a2[i]);
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
 
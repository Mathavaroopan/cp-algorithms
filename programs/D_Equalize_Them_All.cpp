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
    int n;
    cin >> n;
    vector<int> arr(n);
    map<int, int> mp;
    int mx = -inf, x = 0;
    for(int& a : arr){
        cin >> a;
        mp[a]++;
        if(mx < mp[a]){
            mx = mp[a];
            x = a;
        }
    }
    set<int> s;
    for(int i = 0; i < n; i++) if(arr[i] == x) s.insert(i);
    vector<vector<int>> ans;
    while(!s.empty()){
        int ind = *s.begin();
        s.erase(s.begin());
        vector<int> temp;
        if(ind < n - 1 && arr[ind + 1] != x){
            s.insert(ind + 1);
            temp = {((arr[ind] > arr[ind + 1]) ? 1 : 2), ind + 2, ind + 1};
            arr[ind + 1] = x;
            ans.push_back(temp);
        }
        if(ind > 0 && arr[ind - 1] != x){
            s.insert(ind - 1);
            temp = {((arr[ind] > arr[ind - 1]) ? 1 : 2), ind, ind + 1};
            arr[ind - 1] = x;
            ans.push_back(temp);
        }
    }
    cout << ans.size() << endl;
    for(auto v : ans){
        for(int i : v) cout << i << " ";
        cout << endl;
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
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

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    map<int, int> mp1, mp2, mp3;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        arr[i] = a;
        if(i % 3 == 0) mp1[a]++;
        else if(i % 3 == 1) mp2[a]++;
        else mp3[a]++;
    }
    if(n <= 2){
        cout << 0 << endl;
        return;
    }
    if(n == 3){
        if(arr[0] == arr[2]) cout << 1 << endl;
        else cout << 0 << endl;
        return;
    }
    int x = (n + 2) / 3;
    int temp = (x * 3) - n;
    int y = x - ((temp == 2) ? 1 : 0);
    int z = x - ((temp >= 1) ? 1 : 0);
    int ans = 1e18;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            for(int k = 1; k <= n; k++){
                if(i == j || (j == k && n != 4) || i == k) continue;
                int total = x - mp1[i] + y - mp2[j] + z - mp3[k];
                total -= min(mp1[j], mp2[i]) + min(mp1[k], mp3[i]) + ((j != k) ? min(mp2[k], mp3[j]) : 0);
                ans = min(ans, total);
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
    cin >> T;
    while (T--) solve();
    return 0;
}
 
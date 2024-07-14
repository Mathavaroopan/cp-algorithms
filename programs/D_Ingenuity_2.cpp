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
    int n; cin >> n;
    string s; cin >> s;
    int a = 0, b = 0, c = 0, d = 0;
    for(char p : s){
        if(p == 'N') a++;
        else if(p == 'S') b++;
        else if(p == 'E') c++;
        else d++;
    }
    if(n == 2 && s[0] == s[1]){
        cout << "HR" << endl;
        return;
    }
    if(n <= 3 || (abs(a - b) & 1 || abs(c - d) & 1)){
        cout << "NO" << endl;
        return;
    }
    int h1 = 0, h2 = 0, h3 = 0, h4 = 0;
    if(a && b){
        a--, b--;
    }else{
        c--, d--;
    }
    if(a > b){
        h1 += ((a - b) / 2) + b;
        h2 += b;
    }else{
        h2 += ((b - a) / 2) + a;
        h1 += a;
    }
    if(c > d){
        h3 += ((c - d) / 2) + d;
        h4 += d;
    }else{
        h4 += ((d - c) / 2) + c;
        h3 += c;
    }
    string ans = "";
    for(char i : s){
        if(i == 'N'){
            if(h1) ans += 'H', h1--;
            else ans += 'R';
        }else if(i == 'S'){
            if(h2) ans += 'H', h2--;
            else ans += 'R';
        }else if(i == 'E'){
            if(h3) ans += 'H', h3--;
            else ans += 'R';
        }else if(i == 'W'){
            if(h4) ans += 'H', h4--;
            else ans += 'R';
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
 
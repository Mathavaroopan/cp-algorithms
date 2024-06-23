#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
/* Author: Mathavaroopan */

void solve(){
    string s;
    cin >> s;
    s = "0" + s;
    int n = s.size();
    int i;
    int pos = n + 1;
    string num = "";
    for(i = n - 1; i >= 1;){
        if(s[i] - '0' >= 5){
            i--;
            while(s[i] - '0' == 9) i--;
            pos = i;
            num = to_string((s[i] - '0') + 1);
            s[i] = num[0];
        }else i--;
    }
    string ans = "";
    for(int j = 1; j < pos; j++){
        if(isdigit(s[j])) ans += s[j];
    }
    if(pos != n + 1){
        ans += num;
        for(int i = 0; i < n - pos - 1; i++) ans += "0";
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

    
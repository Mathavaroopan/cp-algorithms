#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
    cin >> n;

    int count = 0;
    for(int i = 0; i < n; i++){
        long long a;
        cin >> a;
        while(a > 1 && a % 2 == 0){
            a >>= 1;
            count++;
        }
    }

    int a = n;
    if(a & 1) a--;
    int ans = 0;
    vector<int> arr;
    while(a > 1){
        int p = a;
        int temp = 0;
        while(p > 1 && p % 2 == 0){
            p >>= 1;
            temp++;
        }
        arr.push_back(temp);
        a -= 2;
    }
    if(count >= n){
        cout << 0 << endl;
        continue;
    }
    sort(arr.begin(), arr.end(), greater<int>());

    for(int i : arr){
        if(count + i >= n){
            count = n;
            ans++;
            break;
        }
        count += i;
        ans++;
    }
    if(count < n) cout << -1 << endl;
    else cout << ans << endl;
    }
}
#include <bits/stdc++.h>
#define all(x) begin(x),end(x)

using namespace std;
using ll = long long;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    double win;
    cin >> win;
    int w = win * 1000;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> win;
        arr[i] = win * 1000;
    }
    vector<int> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    
    vector<ll> dp(w + 1);
    for (int i = 0; i < n; i++) {
        for (int cur = w - arr[i]; cur >= 0; cur--) {
            if (dp[cur + arr[i]] < dp[cur] + s[i]) {
                dp[cur + arr[i]] = dp[cur] + s[i];
            }
        }
    }
    cout << *max_element(all(dp)) << endl;
}

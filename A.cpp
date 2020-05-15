#include <bits/stdc++.h>
#define all(x) begin(x),end(x)

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n, m;
    cin >> n >> m;
    ll ans = -1;

    for (ll delta = 0; delta <= n; delta++) {
        if (n * 2 * 100 == m * 5 * (n + delta * 2)) {
            ans = delta;
            break;
        }
    }
    if (ans == -1) {
        cout << "NO\n";
    } else {
        cout << ans << endl;
    }
}

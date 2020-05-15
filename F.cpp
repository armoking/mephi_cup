#include <bits/stdc++.h>
#define all(x) begin(x),end(x)

using namespace std;
using ll = long long;

int Solve(int n, int sx, int sy, int r) {
    /*
     * |x - sx| + |y - sy| == r
     * x in [0, n - 1]
     * y in [0, n - 1]
     * if x <= sx and y <= sy:
     *     sx + sy - x - y = r
     *     - x - y = r - sx - sy
     *     x + y = sx + sy - r
     *
     *     delta := sx + sy - r
     *
     *     y = delta - x
     *     0 <= y <= min(sy, delta, r)
     *     0 <= x <= min(sx, delta, r)
     *     min(delta + 1, sx + 1, sy + 1)
     */
    auto get = [] (int sx, int sy, int n, int r, bool good) {
        int res = 0;
        if (!good) {
            int a1 = sx;
            int b1 = sy - r;
            if (a1 >= 0 && a1 < n && b1 >= 0 && b1 < n) {
                res--;
            }
            int a2 = sx - r;
            int b2 = sy;
            if (a2 >= 0 && b2 >= 0) {
                res--;
            }
        }
        int delta = sx + sy - r;
        res += max(0, min({r, sx, sy, delta}) + 1);
        return res;
    };
    int ans = get(sx, sy, n, r, true);
    sx = n - 1 - sx;
    ans += get(sx, sy, n, r, false);
    sy = n - 1 - sy;
    ans += get(sx, sy, n, r, true);
    sx = n - 1 - sx;
    ans += get(sx, sy, n, r, false);
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    int x, y;
    cin >> x >> y;
    ll ans = 0;

    for (int r = 1; r <= n + n - 2; r++) {
        int res = Solve(n, x, y, r);
        ans += res * 1ll * (res - 1) / 2;
    }
    cout << ans << '\n';
}

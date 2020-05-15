#include <bits/stdc++.h>
#define all(x) begin(x),end(x)

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    const int N = 1e6 + 1;
    vector<int> del(N);
    for (int i = 1; i < N; i++) {
        for (int j = i; j < N; j += i) {
            del[j]++;
        }
    }
    vector<int> cnt(N);
    for (int i = 0; i < N; i++) {
        cnt[i] = del[i] & 1;
    }
    for (int i = 1; i < N; i++) {
        cnt[i] += cnt[i - 1];
    }
    int a, b;
    cin >> a >> b;
    int ans = cnt[b] - (a >= 0 ? cnt[a - 1] : 0);
    cout << ans << '\n';
}

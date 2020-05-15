#include <bits/stdc++.h>
#define all(x) begin(x),end(x)

using namespace std;
using ll = long long;

struct Fenwick {
    int n;
    vector<ll> t;
    Fenwick(int n) : n(n), t(n) {}

    void Add(int i, int val) {
        while (i < n) {
            t[i] += val;
            i = ((i + 1) | i);
        }
    }
    ll Get(int i) {
        ll ans = 0;
        while (i >= 0) {
            ans += t[i];
            i = ((i + 1) & i) - 1;
        }
        return ans;
    }
    ll Get(int l, int r) {
        return Get(r) - Get(l - 1);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    Fenwick tree(n);
    for (int i = 0; i < n; i++) {
        tree.Add(i, arr[i]);
    }

    ll sum = 0;
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int index, v;
            cin >> index >> v;
            index--;
            int delta = v - arr[index];
            tree.Add(index, delta);
            arr[index] = v;
        } else {
            int index, v;
            cin >> index >> v;
            index--;
            
            int left = 0;
            int right = n - index;
            int mid;
            int ans = -1;
            while (left <= right) {
                mid = (left + right) / 2;
                if (tree.Get(index, index + mid - 1) <= v) {
                    ans = mid;
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            sum += ans;
        }
    }
    cout << sum << endl;
}

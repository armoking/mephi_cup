#include <bits/stdc++.h>
#define all(x) begin(x),end(x)

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string a;
    cin >> a;
    vector<int> arr(26);
    for (int i = 0; i < a.size(); i++) {
        arr[a[i] - 'a']++;
    }
    string s;
    vector<int> cur(26);
    while (cin >> s) {
        if (s[0] < 'a' || s[0] > 'z') break;
        fill(all(cur), 0);
        for (char ch : s) cur[ch - 'a']++;
        bool good = true;
        for (int i = 0; i < 26; i++) {
            good &= cur[i] >= arr[i];
        }
        if (good) {
            cout << s << '\n';
        }
    }
}

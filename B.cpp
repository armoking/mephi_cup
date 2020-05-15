#include <bits/stdc++.h>
#define all(x) begin(x),end(x)

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, x1, y1, x2, y2;
    cin >> n;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    /* (x, y) |1..n|  
        |x - x1| + |y - y1| = |x - x2| + |y - y2|
    */

    set<pair<int,int>> ans;
    
    if (y1 > y2) {
        swap(y1, y2);
        swap(x1, x2);
    }

    for (int x = 0; x < n; x++) {
        int dlt = abs(x - x1) - abs(x - x2);
        if (y2 - y1 == dlt) {
            for (int y = 0; y < y1; y++) {
                ans.insert({x, y});
            }
        }
        int cur = dlt - y1 - y2;
        if (cur % 2 == 0 && cur < 0) {
            ans.insert({x, -cur / 2});
        }
    }
    
    if (x1 > x2) {
        swap(x1, x2);
        swap(y1, y2);
    }
    
    for (int y = 0; y < n; y++) {
        int dlt = abs(y - y1) - abs(y - y2);
        if (x2 - x1 == dlt) {
            for (int x = 0; x < x1; x++) {
                ans.insert({x, y});
            }
        }
        int cur = dlt - x1 - x2;
        if (cur % 2 == 0 && cur < 0) {
            ans.insert({-cur / 2, y});
        }
    }
    for (auto& [x, y] : ans) {
        if (abs(x - x1) + abs(y - y1) == abs(x - x2) + abs(y - y2)) {
            cout << x << ' ' << y << '\n';
        }
    }

}

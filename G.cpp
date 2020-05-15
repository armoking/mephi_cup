#include <bits/stdc++.h>
#define all(x) begin(x),end(x)

using namespace std;
using ll = long long;

const int N = 500;
int dp[N][N];
int used[N][N];

void setmin(int x, int y, int time, int value) {
    if (used[x][y] < time || dp[x][y] > value) {
        used[x][y] = time;
        dp[x][y] = value;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    int a, b, c;
    cin >> a >> b >> c;
    vector<int> xs(n);
    vector<int> ys(n);
    vector<int> zs(n);
    for (int i = 0; i < n; i++) {
        cin >> xs[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> ys[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> zs[i];
    }
    for (int i = 0; i < n; i++) {
        int x, y, z;
        x = xs[i];
        y = ys[i];
        z = zs[i];
        for (int usedx = a; usedx >= 0; usedx--) {
            for (int usedy = b; usedy >= 0; usedy--) {
                int usedz = i - usedx - usedy;
                
                if (usedz < 0 || usedz > c) {
                    continue;
                }
                
                if (usedx != a) {
                    setmin(usedx + 1, usedy + 0, i + 1, dp[usedx][usedy] + x);  
                }

                if (usedy != b) {
                    setmin(usedx + 0, usedy + 1, i + 1, dp[usedx][usedy] + y);  
                }

                if (usedz != c) {
                    setmin(usedx + 0, usedy + 0, i + 1, dp[usedx][usedy] + z);  
                }

            }
        }
    }
    cout << dp[a][b] << endl;
}

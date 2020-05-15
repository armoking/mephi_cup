#include <bits/stdc++.h>
#define all(x) begin(x),end(x)

using namespace std;
using ll = long long;

const int N = 100100;

int arr[N];

struct Edge {
    int to, w;
};

vector<Edge> g[N];
ll depth[N];

void Dijkstra(int from) {
    fill(depth, depth + N, 4e18);
    depth[0] = 0;
    priority_queue<pair<ll, int>> pq;
    pq.push({-depth[0], from});
    while (pq.size()) {
        auto [w, v] = pq.top();
        pq.pop();
        w = -w;
        if (depth[v] < w) continue;
        for (auto& [to, dw] : g[v]) {
            if (depth[to] > depth[v] + dw + arr[to]) {
                depth[to] = depth[v] + dw + arr[to];
                pq.push({-depth[to], to});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    arr[0] = arr[n - 1] = 0;
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int f, t, w;
        cin >> f >> t >> w;
        f--, t--;
        g[f].push_back({t, w});
    }
    Dijkstra(0);
    if (depth[n - 1] == 4e18) {
        depth[n - 1] = -1;
    }
    cout << depth[n - 1] << endl;
}

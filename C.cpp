#include <bits/stdc++.h>
#define all(x) begin(x),end(x)

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll x, y;
    ll a, b;

    cin >> a >> b;
    cin >> x >> y;

    a = a * 100 + b;
    x = x * 100 + y;
    
    ll dlt = x - a;
    ll c1, c2, c3, c4, c5, c6;
    
    ll d6 = 1000;
    ll d5 = 500;
    ll d4 = 100;
    ll d3 = 50;
    ll d2 = 10;
    ll d1 = 1;
   
    x = dlt;

    c6 = x / d6;
    x -= c6 * d6;

    c5 = x / d5;
    x -= c5 * d5;
    
    c4 = x / d4;
    x -= c4 * d4;

    c3 = x / d3;
    x -= c3 * d3;

    c2 = x / d2;
    x -= c2 * d2;

    c1 = x / d1;
    x -= c1 * d1;

    cout << c1 << ' ' << c2 << ' ' << c3 << ' ' << c4 << ' ' << c5 << ' ' << c6 << endl;
}

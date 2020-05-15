
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;
 
constexpr long long INF = 1e+18;
 
struct TPoint {
    long long X;
    long long Y;
 
    long long Len() const {
        return X * X + Y * Y;
    }
 
    bool operator <(const TPoint& it) const {
        return X < it.X || (X == it.X && Y < it.Y);
    }
 
    TPoint operator -(const TPoint& it) const {
        return {X - it.X, Y - it.Y};
    }
 
    long long operator *(const TPoint& it) const {
        return X * it.Y - Y * it.X;
    }
};
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n;
    cin >> n;
    vector<TPoint> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].X >> points[i].Y;
        points[i].X += 10000;
        points[i].Y += 10000;
    }
 
    sort(points.begin(), points.end());
    const TPoint min_point = points[0];
 
    sort(points.begin(), points.end(), [&min_point](const TPoint& lhs, const TPoint& rhs) {
        long long sq = (lhs - min_point) * (rhs - min_point);
        return sq > 0 || (sq == 0 && lhs.Len() < rhs.Len());
    });
 
    vector<TPoint> ch;
    ch.emplace_back(points[0]);
    ch.emplace_back(points[1]);
 
    for (int i = 2; i < n; ++i) {
        ch.emplace_back(points[i]);
 
        while (ch.size() > 2) {
            TPoint v1 = ch.at(ch.size() - 2) - ch.at(ch.size() - 3);
            TPoint v2 = ch.at(ch.size() - 1) - ch.at(ch.size() - 2);
 
            long long sq = v1 * v2;
 
            if (sq <= 0) {
                ch.at(ch.size() - 2) = ch.back();
                ch.pop_back();
            } else {
                break;
            }
        }
    }
 
    long double p = sqrt(1.0 * (ch[0] - ch.back()).Len());
    long long s = ch.back() * ch[0];
    for (size_t i = 1; i < ch.size(); ++i) {
        p += sqrt(1.0 * (ch[i] - ch[i - 1]).Len());
        s += ch[i - 1] * ch[i];
    }

    
    
    cout << fixed << setprecision(10);
    cout << p << endl;
    cout << s / 2 << (s % 2 ? ".5" : "") << endl;
 
    return 0;
}

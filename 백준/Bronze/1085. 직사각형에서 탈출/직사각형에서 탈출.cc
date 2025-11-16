#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int x, y, w, h;
    if (!(cin >> x >> y >> w >> h)) return 0;
    int ans = min( min(x, y), min(w - x, h - y) );
    cout << ans << '\n';
    return 0;
}

// BOJ 4573 - Pizza Pricing
// 컴파일: g++ -std=c++17 -O2 -pipe -o a.out solution.cpp

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    int menu = 0;
    const double PI = acos(-1.0);
    while ( (cin >> n) ) {
        if (n == 0) break;
        ++menu;
        int bestD = 0;
        double bestPricePerArea = 1e300; // 아주 큰 값
        for (int i = 0; i < n; ++i) {
            int D, P;
            cin >> D >> P;
            double r = D / 2.0;
            double area = PI * r * r;
            double pricePerArea = P / area;
            if (pricePerArea < bestPricePerArea) {
                bestPricePerArea = pricePerArea;
                bestD = D;
            }
            // 동률이면 먼저 나온 것을 유지 (문제의 일반적인 요구와 블로그 풀이와 동일)
        }
        cout << "Menu " << menu << ": " << bestD << '\n';
    }
    return 0;
}

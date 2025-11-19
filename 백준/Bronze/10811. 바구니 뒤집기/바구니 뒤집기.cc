#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<int> basket(N);
    
    // 1부터 N까지 초기화
    for (int i = 0; i < N; i++) {
        basket[i] = i + 1;
    }
    
    // M번 뒤집기
    for (int k = 0; k < M; k++) {
        int i, j;
        cin >> i >> j;
        
        // i부터 j까지 뒤집기 (1-indexed를 0-indexed로 변환)
        reverse(basket.begin() + i - 1, basket.begin() + j);
    }
    
    // 결과 출력
    for (int i = 0; i < N; i++) {
        cout << basket[i];
        if (i < N - 1) cout << " ";
    }
    cout << "\n";
    
    return 0;
}
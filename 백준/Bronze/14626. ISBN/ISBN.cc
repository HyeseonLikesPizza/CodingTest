#include <iostream>
#include <string>
using namespace std;

int main() {
    string isbn;
    cin >> isbn;
    
    int star_pos = -1;
    int sum = 0;
    
    // 체크섬 계산 및 * 위치 찾기
    for (int i = 0; i < 13; i++) {
        if (isbn[i] == '*') {
            star_pos = i;
        } else {
            int digit = isbn[i] - '0';
            if (i % 2 == 0) {
                sum += digit;
            } else {
                sum += digit * 3;
            }
        }
    }
    
    // * 위치의 숫자 찾기
    int multiplier = (star_pos % 2 == 0) ? 1 : 3;
    
    for (int x = 0; x <= 9; x++) {
        if ((sum + x * multiplier) % 10 == 0) {
            cout << x << '\n';
            break;
        }
    }
    
    return 0;
}
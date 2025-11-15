#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    while(cin >> s) {
        if(s == "0") break;
        
        bool isPalindrome = true;
        int len = s.length();
        
        for(int i = 0; i < len / 2; i++) {
            if(s[i] != s[len - 1 - i]) {
                isPalindrome = false;
                break;
            }
        }
        
        if(isPalindrome) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
    }
    
    return 0;
}
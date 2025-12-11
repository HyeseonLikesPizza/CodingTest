#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <string>
#include <sstream>

using namespace std;

int main(){

    int H,I,A,R,C;

    cin >> H >> I >> A >> R >> C;
    cout << H*I - A*R*C;

    return 0;
}
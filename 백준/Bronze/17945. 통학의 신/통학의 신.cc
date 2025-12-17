#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stack>
#include <climits>

using namespace std;

int main()
{
    int A, B, result1, result2;

    cin >> A >> B;

    result1 = -1*A - sqrt(A*A-B);
    result2 = -1*A + sqrt(A*A-B);

    if (result1 == result2) cout << result1;
    else cout << result1 << " " << result2;
    
    return 0;
}
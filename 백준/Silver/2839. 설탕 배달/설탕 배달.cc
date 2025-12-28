#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stack>
#include <climits>
#include <set>
#include <queue>
#include <string>

using namespace std;


int main()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    
    int N;

    cin >> N;

    int result = 0;
    while(N>0)
    {
        if (N%5==0)
        {
            result++;
            N-=5;
            continue;
        }
        result++;
        N-=3;
    }

    if (N==0)
    {
        cout << result;
    }
    else cout << -1;

    return 0;
}
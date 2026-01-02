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
    long long result=1;

    cin >> N;

    if (N>=2)
    {
        for(int i=2; i<=N; i++)
        {
            result *= i;
        }
    }
    
    cout << result;

    return 0;
}
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
int main()
{
    int N, k, cnt=0, result;

    cin >> N >> k;

    vector<int> vec(N);

    for(int i=0; i<N; i++)
    {
        cin >> vec[i];
    }

    result = k;

    for(int i=N-1; i>=0; i--)
    {
        if (vec[i]<=result)
        {
            int m = result / vec[i];
            result -= m*vec[i];
            cnt += m;
        }

        if (result <= 0) break;
    }

    cout << cnt;

    return 0;
}
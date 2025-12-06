#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
int main()
{
    int N, k;

    cin >> N;
    cin >> k;

    int left = 1;
    int right = k;
    int answer = 0;
    
    while(left<=right)
    {
        int mid = (left+right)/2;
        
        int cnt=0;
        for (int i=1; i<=N; i++)
        {
            cnt += min(N, mid/i);
        }

        if (cnt>=k)
        {
            answer = mid;
            right = mid-1;
        }
        else
        {
            left = mid+1;
        }
    }

    cout << answer;


    return 0;
}
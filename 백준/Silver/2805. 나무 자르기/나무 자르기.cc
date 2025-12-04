#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <stdio.h>
#include <climits>
#include <queue>
#include <tuple>
#include <cmath>

using namespace std;

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

    long long N, M;
    int answer = 0;

    cin >> N >> M;
    vector<int> vec(N);
    int minNum=INT_MAX, maxNum=INT_MIN;

    for (int i=0; i<N; i++)
    {
        cin >> vec[i];
        minNum = min(minNum,vec[i]);
        maxNum = max(maxNum,vec[i]);
    }
    
    sort(vec.begin(), vec.end());

    int left = 1;
    int right = maxNum;

    while (left <= right)
    {
        int mid = (left+right)/2;

        long long cnt = 0;
        for (int a : vec)
            cnt += a > mid ? a - mid : 0;

        if (cnt >= M)
        {
            answer = mid;
            left = mid+1;
        }
        else
        {
            right = mid-1;
        }
        
    }

    cout << answer;

    
    return 0;
}

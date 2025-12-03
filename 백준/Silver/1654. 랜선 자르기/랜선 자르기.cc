#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <stdio.h>
#include <climits>
#include <queue>

using namespace std;


int main() {
    
    FILE* fp;
    
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    //freopen_s(&fp, "input.txt", "rt", stdin);

    int N, K, maxLen=INT_MIN;
    cin >> K >> N;
    vector<int> vec(K);

    for (int i=0; i<K; i++)
    {
        cin >> vec[i];
        maxLen = max(vec[i],maxLen);
    }

    long long left = 1;
    long long right = maxLen;
    long long answer = 0;
    
    while (left<=right)
    {
        long long mid = (left+right)/2;

        long long cnt = 0;
        for (int a : vec)
            cnt += a/mid;

        if (cnt >= N)
        {
            left = mid+1;
            answer = mid;
        }
        else
        {
            right = mid-1;
        }
    }

    cout << answer;
    
    return 0;
}
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
#include <map>

using namespace std;

int N;
long long sz[51];
long long pt[51];

long long solution(int level, long long x)
{
    if (level <= 0)
    {
        return 1;
    }
    if (x==0) return 0;

    long long length = 2 * sz[level-1] + 3; 
    long long middleIdx = length/2;
    long long cnt = 0;
    long long leftX = sz[level-1];
    
    if (x < middleIdx)
    {
        cnt += solution(level-1, x-1);
    }
    else if (x > middleIdx)
    {
        cnt += pt[level-1];
        cnt += 1;
        cnt += solution(level-1,x-(length/2+1));
    }
    else if (x == middleIdx)
    {
        cnt += pt[level-1];
        cnt += 1;
    }

    return cnt;
}



int main()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

    long long X;
    
    cin >> N >> X;

    sz[0] = 1;
    pt[0] = 1;
    for (int i=1; i<N; i++)
    {
        sz[i] = 2*sz[i-1]+3;
        pt[i] = 2*pt[i-1]+1;
    }

    long long answer = solution(N, X-1);

    cout << answer;
    
    return 0;
}

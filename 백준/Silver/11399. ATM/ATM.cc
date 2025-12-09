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

    int N, result=0;

    cin >> N;
    
    vector<int> vec(N);
    vector<int> cnt(N, 0);

    for (int i=0; i<N; i++)
    {
        cin >> vec[i];
    }

    sort(vec.begin(), vec.end());

    cnt[0] = vec[0];
    result += cnt[0];
    
    for (int i=1; i<N; i++)
    {
        cnt[i] = cnt[i-1] + vec[i];
        result += cnt[i];
    }

    cout << result;
    
    
    return 0;
}

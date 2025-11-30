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
    int N, Avg, total;
    float result, sum=0;

    cin >> N;
    Avg = round(N*0.15f);
    total = N-Avg*2;
    vector<int> v(N);

    if (N==0)
    {
        cout << 0;
        return 0;
    }
    
    
    for (int i=0; i<N; i++)
    {
        cin>> v[i];
    }

    sort(v.begin(), v.end());

    for (int i=Avg; i<N-Avg;i++)
    {
        sum += v[i];
    }
    
    

    result = round(sum/total);

    cout << (int)result;
    
    
    return 0;
}

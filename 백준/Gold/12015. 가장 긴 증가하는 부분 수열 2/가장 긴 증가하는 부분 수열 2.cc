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

    int N, len=0;

    cin >> N;
    
    vector<int> vec(N);
    vector<int> LIS(N);

    for (int i=0; i<N; i++)
    {
        cin >> vec[i];
    }

    for (int i=0; i<N; i++)
    {
        if (len==0 || LIS[len-1] < vec[i])
        {
            LIS[len] = vec[i];
            len++;
        }
        else
        {
            int idx = lower_bound(LIS.begin(), LIS.begin()+len, vec[i]) - LIS.begin();
            LIS[idx] = vec[i];
        }
    }

    cout << len;
    
    return 0;
}
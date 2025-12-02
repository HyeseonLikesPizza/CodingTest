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

    int N, M;
    cin >> N;
    vector<int> vec(N);

    for (int i=0; i<N; i++)
    {
        cin >> vec[i];
    }

    sort(vec.begin(), vec.end());

    cin >> M;

    for (int i=0; i<M; i++)
    {
        int target;
        cin >> target;

        auto it = lower_bound(vec.begin(), vec.end(), target);
        
        if (it!=vec.end() && *it == target)
        {
            int firstIdx = lower_bound(vec.begin(), vec.end(), target) - vec.begin();
            int lastIdx = upper_bound(vec.begin(), vec.end(), target) - vec.begin();
            cout << lastIdx - firstIdx << " ";
        }
        else
        {
            cout << 0 << " ";
        }
        
    }
    
    return 0;
}
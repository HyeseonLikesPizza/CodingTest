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
    int cnt=0;
    for (int i=0; i<5; i++)
    {
        int num;
        cin >> num;
        cnt += num;
    }

    cout << cnt;
    
    return 0;
}

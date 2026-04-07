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
#include <string>
#include <iomanip>

using namespace std;


int main()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

    int N, K, cnt=0;

    cin >> N >> K;

    for (int i=1; i<=N; i++)
    {
        if (N%i==0) cnt++;
        if (cnt==K)
        {
            cout << i;
            return 0;
        }
    }

    cout << 0;
    
    return 0;
}

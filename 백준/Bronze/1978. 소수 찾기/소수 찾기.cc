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

    int n, cnt=0;
    cin >> n;

    for (int i=1; i<=n; i++)
    {
        int temp;
        cin >> temp;
        for (int j=2; j<=temp; j++)
        {
            if (temp%j==0 && j!=temp) break;
            if (j==temp) cnt++;
        }
    }

    cout << cnt;
}

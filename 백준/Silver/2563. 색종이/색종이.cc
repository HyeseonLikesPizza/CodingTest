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
    
    int N;
    int arr[101][101] = {0};
    cin >> N;

    for (int i=0; i<N; i++)
    {
        int x, y;
        cin >> x >> y;

        for (int i=y; i<y+10; i++)
        {
            for (int j=x; j<x+10; j++)
            {
                arr[i][j]=1;
            }
        }
    }

    int answer = 0;
    for (int i=1; i<=100; i++)
    {
        for (int j=1; j<=100; j++)
        {
            if (arr[i][j] == 1) answer++;
        }
    }

    cout << answer;
    
    return 0;
}

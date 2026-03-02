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
char arr[400][400];

void draw(int n, int row, int col)
{
    // 1. n이 0보다 같거나 작으면 나온다.
    if (n<=0) return;
    // 2. 그린다.
    int size = 4*n-3;

    for (int i=row; i<row+size; i++)
    {
        arr[i][col] = '*';
        arr[i][col+size-1] = '*';
    }

    for (int j=col; j<col+size; j++)
    {
        arr[row][j] = '*';
        arr[row+size-1][j] = '*';
    }

    draw(n-1, row+2, col+2);
}

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

    int num, max;

    cin >> num;

    int size = 4*num-3;
    for (int i=1;i<=size;i++)
    {
        for (int j=1; j<=size; j++)
        {
            arr[i][j] = ' ';
        }
    }

    draw(num, 1,1);

    for (int i=1; i<=size; i++)
    {
        for (int j=1; j<=size; j++)
        {
            cout << arr[i][j];
        }
        cout << '\n';
    }
    
    return 0;
}

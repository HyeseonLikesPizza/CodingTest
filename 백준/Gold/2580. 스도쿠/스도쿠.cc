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

int arr[10][10];
vector<pair<int, int>> blank;

// 그룹의 첫행 첫열 리턴
pair<int, int> WhichGroup(int row, int col)
{
    if (1<=row && row<=3 && 1<=col && col<=3)
        return pair<int, int>(1,1);
    if (1<=row && row<=3 && 4<=col && col<=6)
        return pair<int, int>(1,4);
    if (1<=row && row<=3 && 7<=col && col <=9)
        return pair<int, int>(1,7);
    if (4<=row && row<=6 && 1<=col && col<=3)
        return pair<int, int>(4,1);
    if (4<=row && row<=6 && 4<=col && col<=6)
        return pair<int, int>(4,4);
    if (4<=row && row<=6 && 7<=col && col <=9)
        return pair<int, int>(4,7);
    if (7<=row && row<=9 && 1<=col && col<=3)
        return pair<int, int>(7,1);
    if (7<=row && row<=9 && 4<=col && col<=6)
        return pair<int, int>(7,4);
    if (7<=row && row<=9 && 7<=col && col <=9)
        return pair<int, int>(7,7);
}

bool IsValid(int row, int col, int num)
{
    // 같은 행 체크
    for (int i=1;i<=9; i++)
    {
        if (arr[row][i] == num) return false;
    }
    // 같은 열 체크
    for (int i=1;i<=9; i++)
    {
        if (arr[i][col] == num) return false;
    }
    // 3x3 박스 체크
    pair<int, int> p = WhichGroup(row, col);
    for (int i=p.first; i<=p.first+2; i++)
    {
        for (int j=p.second; j<=p.second+2; j++)
        {
            if (arr[i][j] == num) return false;
        }
    }

    return true;
}

bool Solve(int idx)
{
    if (idx == blank.size())
    {
        // 스도쿠 전체 출력
        for (int i=1; i<=9; i++)
        {
            for (int j=1; j<=9; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << '\n';
        }
        return true;
    }

    int row = blank[idx].first;
    int col = blank[idx].second;

    for (int i=1; i<=9; i++)
    {
        if (IsValid(row, col, i))
        {
            arr[row][col] = i;
            if (Solve(idx+1))
                return true;
            arr[row][col] = 0;
        }
    }
    return false;
}

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

    for (int i=1; i<=9; i++)
    {
        for (int j=1; j<=9; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 0)
            {
                blank.push_back(make_pair(i, j));
            }
        }
    }

    Solve(0);
    
    return 0;
}

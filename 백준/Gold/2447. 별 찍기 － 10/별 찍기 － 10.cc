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


vector<string> Solution(int N)
{
    vector<string> vs;
    if (N == 1)
    {
        vs.push_back("*");
        return vs;
    }

    int nextN = N/3;

    // 좌상단
    vs = Solution(nextN);

    // 상단 중앙
    vector<string> temp = Solution(nextN);

    for (int i=0; i<vs.size(); i++)
    {
        string left = vs[i];
        string right = temp[i];
        vs[i] = left+right;
    }

    // 우상단
    temp = Solution(nextN);

    for (int i=0; i<vs.size(); i++)
    {
        string left = vs[i];
        string right = temp[i];
        vs[i] = left+right;
    }

    // 좌측
    temp = Solution(nextN);

    for (int i=0; i<temp.size(); i++)
    {
        vs.push_back(temp[i]);
    }

    // 우측 (패딩 넣어서 배열에 추가하기)
    temp = Solution(nextN);
    int paddingSize = N/3;
    int idx = N/3;
    
    for (string str : temp)
    {
        string left = vs[idx];
        string padding;
        padding.resize(paddingSize, ' ');
        vs[idx] = left + padding + str;
        idx++;
    }

    // 좌하단
    temp = Solution(nextN);

    for (int i=0; i<temp.size(); i++)
    {
        vs.push_back(temp[i]);
    }

    // 하단 중앙
    temp = Solution(nextN);
    idx = N/3 * 2;
    
    for (string str : temp)
    {
        string left = vs[idx];
        vs[idx] = left + str;
        idx++;
    }

    // 우하단
    temp = Solution(nextN);
    idx = N/3 * 2;
    
    for (string str : temp)
    {
        string left = vs[idx];
        vs[idx] = left + str;
        idx++;
    }


    return vs;
}

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<string> answer = Solution(N);

    for (string str : answer)
    {
        cout << str << '\n';
    }
    
    
    return 0;
}

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

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int R, C, T;
int answer = 0;
vector<string> vec;


void solution(int x, int y, int moveCnt, int eatCnt)
{
    if (moveCnt==T)
    {
        answer = max(answer, eatCnt);
        return;
    }

    for (int i=0; i<4; i++)
    {
        int nx = x+dx[i];
        int ny = y+dy[i];

        if (nx < 0 || nx >= C || ny < 0 || ny >= R) continue;
        if (vec[ny][nx] == '#' || vec[ny][nx] == '1') continue;

        char original = vec[ny][nx];
        if (original == 'S')
        {
            eatCnt++;
            vec[ny][nx] = '.';
        }
        
        solution(nx, ny, moveCnt+1, eatCnt);
        
        vec[ny][nx] = original;
        if (vec[ny][nx]=='S') eatCnt--;
    }
}

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

    cin >> R >> C >> T;

    int startX, startY;
    
    for (int i=0; i<R; i++)
    {
        string str;
        cin >> str;

        size_t pos = str.find('G');
        if (pos != string::npos)
        {
            startX = pos;
            startY = i;
        }
        
        vec.push_back(str);
    }

    solution(startX, startY, 0, 0);

    cout << answer;
    
    
    return 0;
}

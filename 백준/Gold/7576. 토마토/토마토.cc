#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <stdio.h>
#include <climits>
#include <queue>

using namespace std;

int vec[1001][1001];
int visited[1001][1001];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    int N, M, minusCnt=0, maxDate=-200, AdultTomato=0, AlreadyAdultTomato=0;
    queue<pair<int,int>> q;
    int order_cnt = 1;

    cin >> M >> N;
    

    for (int i=0; i<N; i++)
    {
        for (int j=0; j<M; j++)
        {
            cin >> vec[i][j];
            if (vec[i][j]==1)
            {
                q.push({i,j});
                AlreadyAdultTomato++;
            }
            if (vec[i][j]==-1)
                minusCnt++;
        }
    }

    while (!q.empty())
    {
        int ny = q.front().first;
        int nx = q.front().second;
        q.pop();
        AdultTomato++;

        for (int i=0; i<4; i++)
        {
            int y = ny+dy[i];
            int x = nx+dx[i];

            if (x >= M || y >= N || x < 0 || y < 0) continue;
            
            if (visited[y][x] == 0 && vec[y][x]==0)
            {
                visited[y][x]=visited[ny][nx]+1;
                q.push({y,x});
            }
        }
    }

    for (int i=0; i<N; i++)
    {
        for (int j=0; j<M; j++)
        {
            if (visited[i][j] > maxDate)
                maxDate = visited[i][j];
        }
    }

    if ((N*M-minusCnt) == AdultTomato)
    {
        cout << maxDate;
    }
    else if ((N*M-minusCnt) == AlreadyAdultTomato)
    {
        cout << 0;
    }
    else if ((N*M-minusCnt)>AdultTomato)
    {
        cout << -1;
    }

    
    return 0;
}

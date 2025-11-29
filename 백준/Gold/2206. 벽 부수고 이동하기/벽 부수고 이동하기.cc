#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <stdio.h>
#include <climits>
#include <queue>
#include <tuple>

using namespace std;

int vec[1001][1001];
bool visited[1001][1001][2];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int cnt[1001][1001][2];

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    int N, M;
    queue<tuple<int,int,int>> q;

    cin >> N >> M;

    for (int i=1; i<=N; i++)
    {
        string s;
        cin >> s;
        for (int j=1; j<=M; j++)
        {
            vec[i][j] = s[j-1] - '0';
        }
    }

    q.push({1,1,0});
    visited[1][1][0] = true;
    cnt[1][1][0] = 1;
    cnt[1][1][1] = 1;

    while (!q.empty())
    {
        int y = get<0>(q.front());
        int x = get<1>(q.front());
        int isBrokenWall = get<2>(q.front()); 
        q.pop();

        if (y == N && x == M)
        {
            cout << cnt[y][x][isBrokenWall];
            return 0;
        }

        for (int i=0; i<4; i++)
        {
            int nx = x+dx[i];
            int ny = y+dy[i];

            if (nx < 1 || nx > M || ny < 1 || ny > N) continue;

            if (vec[ny][nx] == 1 && isBrokenWall==0 && !visited[ny][nx][1])
            {
                cnt[ny][nx][1] = cnt[y][x][isBrokenWall]+1;
                visited[ny][nx][1] = true;
                q.push({ny,nx,1});
            }
            else if (vec[ny][nx]==0 && !visited[ny][nx][isBrokenWall])
            {
                cnt[ny][nx][isBrokenWall] = cnt[y][x][isBrokenWall]+1;
                visited[ny][nx][isBrokenWall] = true;
                q.push({ny,nx,isBrokenWall});
            }
        }
    }
    
    cout << -1;
    
    return 0;
}

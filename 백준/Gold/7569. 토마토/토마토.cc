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

int vec[101][101][101];
int visited[101][101][101];
int dx[6] = {1,0,-1,0,0,0};
int dy[6] = {0,1,0,-1,0,0};
int dz[6] = {0,0,0,0,1,-1};

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    int N, M, H, minusCnt=0, maxDate=-200, AdultTomato=0, AlreadyAdultTomato=0;
    queue<tuple<int,int,int>> q;
    int order_cnt = 1;

    cin >> M >> N >> H;
    

    for (int i=0; i<H; i++)
    {
        for (int j=0; j<N; j++)
        {
            for (int k=0; k<M; k++)
            {
                cin >> vec[i][j][k];
                if (vec[i][j][k]==1)
                {
                    q.push({i,j,k});
                    AlreadyAdultTomato++;
                }
                if (vec[i][j][k]==-1)
                    minusCnt++;
            }
        }
    }

    while (!q.empty())
    {
        int nz = get<0>(q.front());
        int ny = get<1>(q.front());
        int nx = get<2>(q.front());
        q.pop();
        AdultTomato++;

        for (int i=0; i<6; i++)
        {
            int z = nz+dz[i];
            int y = ny+dy[i];
            int x = nx+dx[i];

            if (x >= M || y >= N || x < 0 || y < 0 || z >= H || z < 0) continue;
            
            if (visited[z][y][x] == 0 && vec[z][y][x]==0)
            {
                visited[z][y][x] = visited[nz][ny][nx]+1;
                q.push({z,y,x});
            }
        }
    }

    
    for (int i=0; i<H; i++)
    {
        for (int j=0; j<N; j++)
        {
            for (int k=0; k<M; k++)
            {
                if (visited[i][j][k] > maxDate)
                    maxDate = visited[i][j][k];                
            }
        }
    }

    if ((H*N*M-minusCnt) == AdultTomato)
    {
        cout << maxDate;
    }
    else if ((H*N*M-minusCnt) == AlreadyAdultTomato)
    {
        cout << 0;
    }
    else if ((H*N*M-minusCnt)>AdultTomato)
    {
        cout << -1;
    }

    
    return 0;
}

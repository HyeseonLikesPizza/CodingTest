#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <stdio.h>

using namespace std;

int arr[102][102];
bool visited[102][102];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int cnt;


void DFS(int y, int x)
{
    for (int i=0; i<4; i++)
    {
        int nx = x+dx[i];
        int ny = y+dy[i];

        if (arr[ny][nx] == 1 && visited[ny][nx] == false)
        {
            visited[ny][nx] = true;
            DFS(ny, nx);
            cnt++;
        }
    }
}


int main() {
    
    FILE* fp;
    
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    //freopen_s(&fp, "input.txt", "rt", stdin);

    int N, M, K;
    int r, c, max = -1;

    cin >> N >> M >> K;

    //vector<vector<int>> arr(K+1);

    for (int i=0; i<K; i++)
    {
        cin >> r >> c;
        arr[r][c] = 1;
    }

    for (int i=1; i<=N; i++)
    {
        for (int j=1; j<=M; j++)
        {
            if (arr[i][j] == 1 && visited[i][j] == false)
            {
                cnt = 1;
                visited[i][j] = true;
                DFS(i, j);
                if (cnt > max) max = cnt;
            }
        }
    }

    cout << max;

    return 0;
}
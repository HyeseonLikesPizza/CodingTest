#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <stdio.h>
#include <cmath>
#include <limits>

using namespace std;

int paintingCnt;
int sizeMax;
int paintingSize;
int dx[4] = {1,0,-1,0};
int dy[4] = { 0,1,0,-1 };
int vec[501][501];
bool visited[501][501];

void DFS(int y, int x)
{
    for (int dir = 0; dir < 4; dir++)
    {
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        if (vec[ny][nx] == 1 && visited[ny][nx] == false)
        {
            visited[ny][nx] = true;
            DFS(ny, nx);
            paintingSize++;
        }
    }
}


int main() {

    FILE* fp;

    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    //freopen_s(&fp, "input.txt", "rt", stdin);

    int n, m, temp;

    cin >> n >> m;

    //vector<vector<int>> vec(n, vector<int>(m));
    //vector<vector<bool>> visited(n, vector<bool>(m));



    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> vec[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (vec[i][j] == 1 && visited[i][j] == false)
            {
                visited[i][j] = true;
                paintingSize = 1;
                DFS(i, j);
                if (paintingSize > sizeMax) sizeMax = paintingSize;
                paintingCnt++;
            }
        }
    }

    cout << paintingCnt << '\n' << sizeMax;



    return 0;
}
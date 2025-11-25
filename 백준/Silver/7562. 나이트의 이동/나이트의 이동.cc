#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <stdio.h>
#include <climits>
#include <queue>

using namespace std;

vector<vector<int>> vec;
int visited[301][301];

int dx[8] = {2,1,-1,-2,-2,-1,1,2};
int dy[8] = {1,2,2,1,-1,-2,-2,-1};


int main() {
    
    FILE* fp;
    
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    //freopen_s(&fp, "input.txt", "rt", stdin);

    int S, l;
    int cnt = 1;
    cin >> S;
    
    for (int i=0; i<S; i++)
    {
        int curX, curY, toX, toY;
        cin >> l;
        cin >> curX >> curY;
        cin >> toX >> toY;

        // visited 배열 초기화
        memset(visited, 0, sizeof(visited));

        queue<pair<int, int>> q;
        q.push(pair<int, int>(curX, curY));
        visited[curY][curX] = 0;

        while (!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            if (x == toX && y == toY)
            {
                cout << visited[y][x] << '\n';
                break;
            }

            for (int j=0; j<8; j++)
            {
                int nx = x+dx[j];
                int ny = y+dy[j];

                if (nx < 0 || nx >= l || ny < 0 || ny >= l) continue;
                
                if (visited[ny][nx] == 0 && !(nx == curX && ny == curY)) 
                {
                    visited[ny][nx] = visited[y][x]+1;
                    q.push(pair<int,int>(nx,ny));
                }
            }
        }
    }
     
    return 0;
}
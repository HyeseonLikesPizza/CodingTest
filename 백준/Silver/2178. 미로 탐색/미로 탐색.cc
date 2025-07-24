#include <iostream>
#include <queue>
using namespace std;

int map[101][101];
int dist[101][101];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void BFS(int N, int M)
{
    queue<pair<int, int>> q;
    q.push({1, 1});
    dist[1][1] = 1;

    while (!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny >= 1 && ny <= N && nx >= 1 && nx <= M)
            {
                if (map[ny][nx] == 1 && dist[ny][nx] == 0)
                {
                    dist[ny][nx] = dist[y][x] + 1;
                    q.push({ny, nx});
                }
            }
        }
    }
}

int main()
{
    int N, M;
    cin >> N >> M;

    // 입력을 문자로 받아서 숫자로 변환
    for (int i = 1; i <= N; i++)
    {
        string line;
        cin >> line;
        for (int j = 1; j <= M; j++)
        {
            map[i][j] = line[j - 1] - '0';
        }
    }

    BFS(N, M);

    cout << dist[N][M] << endl;

    return 0;
}

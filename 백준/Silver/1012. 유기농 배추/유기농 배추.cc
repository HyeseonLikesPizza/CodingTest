#include <iostream>
#include <cstring>

using namespace std;

int arr[50][50];
bool visited[50][50];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int M, N;

void DFS(int y, int x)
{
	for (int i = 0; i < 4; i++)
	{
		int m = x + dx[i];
		int n = y + dy[i];

		if (m < 0 || n < 0 || m>=M || n>=N) continue;

		if (arr[n][m] == 1 && visited[n][m] == false)
		{
			visited[n][m] = true;
			DFS(n, m);
		}
	}
}

int main() {

	int T, K, X, Y, cnt=0;

	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	//freopen("input.txt", "rt", stdin);

	cin >> T;
	
	for (int i = 0; i < T; i++)
	{
		cin >> M >> N >> K;

		for (int j = 0; j < K; j++)
		{
			cin >> X >> Y;
			arr[Y][X] = 1;
		}

		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < M; x++)
			{
				if (arr[y][x] == 1 && visited[y][x] == false)
				{
					visited[y][x] = true;
					DFS(y, x);
					cnt++;
				}
			}
		}
		cout << cnt << endl;
		cnt = 0;
		memset(arr, 0, sizeof(arr));
		memset(visited, false, sizeof(visited));
	}

	

	return 0;
}
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

int vec[101];
int cnt[101];
bool visited[101];

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    int N, M;
    queue<int> q;

    cin >> N >> M;

    for (int i = 0; i < N+M; i++)
    {
        int a, b;
        cin >> a >> b;
        vec[a] = b;
    }

    q.push(1);
    visited[1] = true;

    while (!q.empty())
    {
        int x = q.front();
        q.pop();

        for (int i = 1; i <= 6; i++)
        {
            int n = x + i;
            
            if (n > 100) continue;

            if (vec[n] != 0)
            {
                n = vec[n];
            }

            if (n == 100)
            {
                cout << cnt[x]+1;
                return 0;
            }

            if (!visited[n])
            {
                visited[n] = true;
                cnt[n] = cnt[x] + 1;
                q.push(n);
            }
        }
    }
    
    
    return 0;
}

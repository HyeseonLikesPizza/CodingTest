#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, K, X, M, A, B;

    cin >> N >> M >> K >> X;
    vector<vector<int>> vec(N+1);
    vector<int> dist(N+1, -1);

    for (int i=1; i<=M; i++)
    {
        cin >> A >> B;
        vec[A].push_back(B);
    }

    queue<int> q;
    q.push(X);
    dist[X] = 0;
    
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        
        for (int next : vec[cur])
        {
            if (dist[next] == -1)
            {
                dist[next] = dist[cur] + 1;
                q.push(next);
            }
        }
    }

    vector<int> result;
    for (int i=1; i<=N; i++)
    {
        if (dist[i] == K)
        {
            result.push_back(i);
        }
    }

    if (result.empty())
    {
        cout << -1;
    }
    else
    {
        sort(result.begin(), result.end());
        for (int city : result)
        {
            cout << city << '\n';
        }
    }

    return 0;
}
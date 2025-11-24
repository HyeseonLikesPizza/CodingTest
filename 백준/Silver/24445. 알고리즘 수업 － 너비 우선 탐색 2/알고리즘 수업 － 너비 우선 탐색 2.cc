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
int visited[100001];

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    int N, M, R;
    queue<int> q;
    int order_cnt = 1;

    cin >> N >> M >> R;

    vec.resize(N+1);

    for (int i=0; i<M; i++)
    {
        int A, B;
        cin >> A >> B;
        vec[A].push_back(B);
        vec[B].push_back(A);
    }

    q.push(R);

    for (int i=1; i<=N; i++)
    {
        sort(vec[i].begin(), vec[i].end(), greater<int>());
    }

    while (!q.empty())
    {
        int num = q.front();
        q.pop();
        visited[num] = order_cnt++;

        for (int i=0; i<vec[num].size(); i++)
        {
            int x = vec[num][i];
            if (visited[x] == 0)
            {
                visited[x]++;
                q.push(x);
            }
        }
    }

    for (int i=1; i<=N; i++)
    {
        cout << visited[i] << '\n';
    }

    
    return 0;
}

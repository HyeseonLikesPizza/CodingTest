#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <stdio.h>
#include <climits>

using namespace std;

vector<vector<int>> vec;
int visited[100001];
int order_cnt = 1;

void DFS(int num)
{
    visited[num] = order_cnt++;

    for (int i=0; i<vec[num].size(); i++)
    {
        int x = vec[num][i];
        if (visited[x] == 0)
        {
            DFS(x);
        }
    }
}

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    int N, M, R;

    cin >> N >> M >> R;

    vec.resize(N+1);

    for (int i=0; i<M; i++)
    {
        int A, B;
        cin >> A >> B;
        vec[A].push_back(B);
        vec[B].push_back(A);
    }

    for (int i=1; i<=N; i++)
    {
        sort(vec[i].begin(), vec[i].end(), greater<>());
    }

    DFS(R);

    for (int i=1; i<=N; i++)
    {
        cout << visited[i] << '\n';
    }
    
    
    return 0;
}

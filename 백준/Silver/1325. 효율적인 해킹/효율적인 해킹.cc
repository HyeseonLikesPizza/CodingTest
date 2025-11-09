#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int N, M;
vector<int> graph[10001];
bool visited[10001];

// BFS로 i번 컴퓨터를 해킹했을 때 해킹 가능한 컴퓨터 수 계산
int bfs(int start)
{
    memset(visited, false, sizeof(visited));
    queue<int> q;
    q.push(start);
    visited[start] = true;
    int count = 0;
    
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        count++;
        
        for (int next : graph[cur])
        {
            if (!visited[next])
            {
                visited[next] = true;
                q.push(next);
            }
        }
    }
    
    return count;
}

int main()
{
    cin >> N >> M;
    
    for (int i = 0; i < M; i++)
    {
        int A, B;
        cin >> A >> B;
        graph[B].push_back(A); // B를 해킹하면 A를 해킹할 수 있음
    }
    
    int maxCount = 0;
    vector<int> result;
    
    // 각 컴퓨터에 대해 해킹 가능한 컴퓨터 수 계산
    for (int i = 1; i <= N; i++)
    {
        int count = bfs(i);
        
        if (count > maxCount)
        {
            maxCount = count;
            result.clear();
            result.push_back(i);
        }
        else if (count == maxCount)
        {
            result.push_back(i);
        }
    }
    
    // 결과는 이미 오름차순으로 저장됨 (i가 1부터 N까지 순회)
    for (int res : result)
    {
        cout << res << " ";
    }
    
    return 0;
}
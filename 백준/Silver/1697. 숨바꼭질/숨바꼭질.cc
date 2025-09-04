#include <iostream>
#include <vector>
#include <cstdio>
#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;

int maxIdx = 100002;
bool visited[100002];


int main() {
    
    FILE* fp;
    
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    //freopen_s(&fp, "input.txt", "rt", stdin);

    int N, K;
    queue<pair<int, int>> q;

    cin >> N >> K;
    q.push({N, 0});
    visited[N] = true;

    while (!q.empty())
    {
        int x = q.front().first;
        int time = q.front().second;
        q.pop();

        if (x == K)
        {
            cout << time;
            return 0;
        }
        
        int arr[3] = {x-1, x+1, x*2};

        for (int nx : arr)
        {
            
            
            if ( nx >=0 && nx < maxIdx && visited[nx] == false)
            {
                visited[nx] = true;
                q.push({nx, time+1});
            }
        }
        
        
    }
    

    return 0;
}

#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <stdio.h>
#include <climits>
#include <queue>

using namespace std;

int colored[20001];


int main() {
    
    FILE* fp;
    
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    //freopen_s(&fp, "input.txt", "rt", stdin);

    int K;
    cin >> K;

    for (int i=0; i<K; i++)
    {
        int V, E;

        cin >> V >> E;

        vector<vector<int>> vec(V+1);
        memset(colored, 0, sizeof(colored));

        for (int j=0; j<E; j++)
        {
            int a, b;
            cin >> a >> b;
            vec[a].push_back(b);
            vec[b].push_back(a);
        }

        
        bool bYes = true;

        for (int k=1; k<V; k++)
        {
            if (colored[k] != 0) continue;

            queue<int> q;
            q.push(k);
            colored[k] = 1;

            while (!q.empty())
            {
                int x = q.front();
                q.pop();

                for (int j=0; j<vec[x].size(); j++)
                {
                    int nx = vec[x][j];
                    if (colored[nx] == 0)
                    {
                        if (colored[x]==1) colored[nx] = 2;
                        else if (colored[x]==2) colored[nx] = 1;
                        q.push(nx);
                        continue;
                    }
                
                    if (colored[nx] == colored[x])
                    {
                        bYes = false;
                        q = queue<int>();
                        break;
                    }
                }

                if (!bYes) break;
            }
            if (!bYes) break;
        }

        if (bYes)
        {
            cout << "YES" << '\n';
        }
        else
        {
            cout << "NO" << '\n';
        }
        
    }
    
    return 0;
}
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <fstream>
#include <queue>
#include <string>

using namespace std;

int arr[100][100];
bool visited[100];
int n;

void DFS(int a)
{
    for (int i=1; i<=n; i++)
    {
        if (visited[i]==false && arr[a][i]==1)
        {
            visited[i] = true;
            DFS(i);
        }
    }
}


int main()
{
    int m, tmp1, tmp2;
    int cnt=0;

    fstream f;
    f.open("input.txt", ios::in);
    
    cin >> n >> m;

    for (int i=0;i<m;i++)
    {
        cin >> tmp1 >> tmp2;
        arr[tmp1][tmp2] = 1;
        arr[tmp2][tmp1] = 1;
    }

    visited[1]=true;
    DFS(1);

    for (int i=1; i<=n; i++)
    {
        if (visited[i] == true) cnt++;
    }

    cout << cnt-1;
    
    return 0;
}
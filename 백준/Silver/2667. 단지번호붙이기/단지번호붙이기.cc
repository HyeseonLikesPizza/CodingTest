#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <stdio.h>

using namespace std;

int arr[50][50];
bool visited[50][50];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int N;
int num=1;

void DFS(int y, int x)
{
    for (int i = 0; i < 4; i++)
    {
        int m = x + dx[i];
        int n = y + dy[i];

        if (m < 0 || n < 0 || m>=N || n>=N) continue;

        if (arr[n][m] == 1 && visited[n][m] == false)
        {
            visited[n][m] = true;
            num++;
            DFS(n, m);
        }
    }
}

int main() {

    int cnt=0;
    string str;

    vector<int> vec;
    //FILE* fp;
    
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    //freopen("input.txt", "rt", stdin);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> str;
        for (int j=0; j<N; j++)
        {
            arr[i][j] = str[j] - '0';
        }
    }

    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < N; x++)
        {
            if (arr[y][x] == 1 && visited[y][x] == false)
            {
                visited[y][x] = true;
                DFS(y, x);
                cnt++;
                vec.push_back(num);
                num = 1;
            }
        }
    }
    
    cout << cnt << endl;
    sort(vec.begin(), vec.end());
    
    for (int i=0; i<vec.size(); i++)
    {
        cout << vec[i] << endl;
    }

	

    return 0;
}
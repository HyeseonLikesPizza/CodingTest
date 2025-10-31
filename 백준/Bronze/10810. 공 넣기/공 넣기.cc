#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <stdio.h>
#include <climits>

using namespace std;

int arr[101];

int main() {
    
    FILE* fp;
    
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    //freopen_s(&fp, "input.txt", "rt", stdin);

    int N, M, i, j, k;
    

    cin >> N >> M;

    for (int a=0; a<M; a++)
    {
        cin >> i >> j >> k;
        for (int b=i; b<=j; b++)
        {
            arr[b] = k;
        }
    }

    for (int i=1; i<=N; i++)
    {
        cout << arr[i] << " ";
    }
    
     
    return 0;
}
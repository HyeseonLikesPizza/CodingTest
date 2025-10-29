#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <stdio.h>
#include <climits>

using namespace std;

long long D[91][2];

int main() {
    
    FILE* fp;
    
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    //freopen_s(&fp, "input.txt", "rt", stdin);

    int N;

    cin >> N;

    D[1][1] = 1;
    D[1][0] = 0;

    for (int i=2; i<=N; i++)
    {
        D[i][0] = D[i-1][0] + D[i-1][1];
        D[i][1] = D[i-1][0];
    }
    
    
    cout << D[N][1] + D[N][0] << '\n';
     
    return 0;
}
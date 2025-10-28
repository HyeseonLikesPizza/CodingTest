#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <stdio.h>
#include <climits>

using namespace std;



int main() {
    
    FILE* fp;
    
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    //freopen_s(&fp, "input.txt", "rt", stdin);

    int N;

    cin >> N;
    
    vector<int> D(N+2, 0), T(N+2), P(N+2);
    
    for (int i=1; i<=N; i++)
    {
        cin >> T[i] >> P[i];  
    }

    for (int i=N; i>=1; i--)
    {
        if (i+T[i] > N+1)
        {
            D[i] = D[i+1];
        }
        else
        {
            D[i] = max(D[i+1], D[i+T[i]]+P[i]);
        }
    }

    cout << D[1];
    
    return 0;
}
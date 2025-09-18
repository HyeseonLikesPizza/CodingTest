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
    //10freopen_s(&fp, "input.txt", "rt", stdin);

    int n;

    cin >> n;

    int* D = new int[n+1];

    D[1]=0;
    D[2]=1;

    if (n==1)
    {
        cout << D[1];
        return 0;
    }
    else if (n==2)
    {
        cout << D[2];
        return 0;
    }

    for (int i=3; i<=n; i++)
    {
        int best = D[i-1];
        int n2=INT_MAX, n3=INT_MAX;
        if (i%2==0) best = min(best, D[i/2]);
        if (i%3==0) best = min(best, D[i/3]);

        D[i] = best + 1;
    }

    cout << D[n];
    
    delete[] D;

    return 0;
}
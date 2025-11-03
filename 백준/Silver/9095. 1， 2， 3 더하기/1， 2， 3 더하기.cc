#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <stdio.h>
#include <climits>

using namespace std;

int D[12];

int Calc(int num)
{
    D[1] = 1;
    D[2] = 2;
    D[3] = 4;

    for (int i=4; i<=num; i++)
    {
        D[i] = D[i-1] + D[i-2] + D[i-3];
    }

    return D[num];
}


int main() {
    
    FILE* fp;
    
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    //freopen_s(&fp, "input.txt", "rt", stdin);

    int T, n;

    cin >> T;

    for (int i=0; i<T; i++)
    {
        cin >> n;
        cout << Calc(n) << endl;
    }
    
    
     
    return 0;
}
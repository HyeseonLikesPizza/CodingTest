#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <stdio.h>
#include <climits>

using namespace std;

long long int arr[91];

int main() {
    
    FILE* fp;
    
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    //freopen_s(&fp, "input.txt", "rt", stdin);

    int n;

    cin >> n;

    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 1;

    for (int i=3; i<=n; i++)
    {
        arr[i] = arr[i-1] + arr[i-2];
    }

    cout << arr[n];
    
     
    return 0;
}
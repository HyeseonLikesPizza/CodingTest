#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <stdio.h>
#include <climits>
#include <queue>
#include <tuple>
#include <cmath>

using namespace std;


int main()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

    vector<int> arr(3);

    cin >> arr[0] >> arr[1] >> arr[2];
    sort(arr.begin(), arr.end());
    cout << arr[0] << ' ' << arr[1] << ' ' << arr[2];
    
    return 0;
}

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
#include <map>

using namespace std;

int x,y,n;
int answer = 0;
vector<int> vec;
int dist;

void solution(int num)
{
    if (num > n)
    {
        answer++;
        return;
    }

    if (num == dist)
    {
        solution(num+1);
    }

    for (int i=1; i<=2*n; i++)
    {
        int i2 = i+num+1;
        
        if (i2 > 2*n) continue;
        if (vec[i] != 0 || vec[i2] !=0 ) continue;

        vec[i] = num;
        vec[i2] = num;

        solution(num+1);

        vec[i] = 0;
        vec[i2] = 0;
        
    }
}

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

    cin >> n >> x >> y;

    vec.resize(2*n+1, 0);

    dist = y-x-1;
    
    vec[x] = vec[y] = dist;

    solution(1);
    
    cout << answer;
    
    return 0;
}

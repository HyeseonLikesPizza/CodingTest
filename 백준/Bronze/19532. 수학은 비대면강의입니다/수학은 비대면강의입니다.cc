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

    int a,b,c,d,e,f,x=0,y=0;

    cin >> a >> b >> c >> d >> e >> f;

    // x 계산
    x = (f*b-e*c)/(d*b-a*e);

    // y 계산
    y = (f*a-c*d)/(e*a-b*d);

    cout << x << ' ' << y;
    
    return 0;
}

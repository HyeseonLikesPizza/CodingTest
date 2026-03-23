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
#include <string>
#include <iomanip>

using namespace std;


int main()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

    int X,D,num,den;

    cin >> X;

    for (int i=1; i<=X; i++)
    {
        if (i*(i+1)>=2*X)
        {
            D = i; 
            break;
        }
    }

    int pos = X - (D-1)*D/2;

    // D가 짝수일 때
    if (D%2==0)
    {
        num = pos;
        den = D+1-pos;
    }
    else
    {
        num = D+1-pos;
        den = pos;
    }

    cout << num << "/" << den;
    
    
    return 0;
}

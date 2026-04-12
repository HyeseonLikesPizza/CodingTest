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
#include <set>

using namespace std;

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

    map<int, int> x,y;

    for (int i=1; i<=3; i++)
    {
        int x1, y1;
        cin >> x1 >> y1;

        if (x[x1]==1)
        {
            x.erase(x1);
        }
        else
        {
            x[x1]++;
        }
        if (y[y1]==1)
        {
            y.erase(y1);
        }
        else
        {
            y[y1]++;
        }
    }

    cout << x.begin()->first << " " << y.begin()->first;
    
    
    return 0;
}

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


int main()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

    string str;

    cin >> str;

    int length = str.length();

    for (int i=0; i<length/2; i++)
    {
        if (str[i] != str[length-1-i])
        {
            cout << '0';
            return 0;
        }
    }

    cout << '1';
    
    return 0;
}

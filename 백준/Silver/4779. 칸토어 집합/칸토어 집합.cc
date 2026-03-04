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

void Recursive(string& str)
{
    if (str.size() <= 1)
    {
        cout << str;
        return;
    }

    int rightLast = str.size()-1;

    int leftFirst = 0;
    int middleFirst = str.size() / 3;
    int leftLast = middleFirst - 1;
    int rightFirst = str.size() / 3 * 2;
    int middleLast = rightFirst - 1;

    // 3등분
    string tempStr = "";
    for (int i=leftFirst; i<=leftLast; i++)
    {
        tempStr += '-';
    }
    Recursive(tempStr);

    tempStr = "";
    for (int i=middleFirst; i<=middleLast; i++)
    {
        tempStr += ' ';
    }
    cout << tempStr;

    tempStr = "";
    for (int i=rightFirst; i<=rightLast; i++)
    {
        tempStr += '-';
    }
    Recursive(tempStr);
}


int main()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

    int N;

    while (1)
    {
        cin >> N;
        if (cin.eof()) break;

        int len = pow(3, N);
        string str(len, '-');

        Recursive(str);
        cout << '\n';
    }
    
    return 0;
}

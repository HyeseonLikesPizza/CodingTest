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

    string str;
    int B;

    cin >> str >> B;

    int answer = 0;
    for (int i=str.length()-1; i>=0; i--)
    {
        int coefficient = isdigit(str[i]) ? str[i]-'0' : str[i] - 'A' + 10;
        answer += coefficient * pow(B, str.length()-1-i);
    }

    cout << answer;
    
    return 0;
}

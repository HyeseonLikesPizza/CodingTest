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

string input;

bool solution(int left, int right)
{
    if (right-left == 0)
    {
        return true;
    }
    
    int len = right - left + 1;
    int half = len/2;
    
    // 펠린드롬인지 체크
    for (int i=0; i<half; i++)
    {
        if (input[left+i]!=input[right-i]) return false;
    }

    // 접두사 체크
    bool isLeftOK = solution(left, left+half-1);

    // 접미사 체크
    bool isRightOK = solution(right-half+1,right);

    return isLeftOK && isRightOK;
}



int main()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    
    cin >> input;
    bool answer = solution(0, input.size()-1);

    if (answer)
        cout << "AKARAKA";
    else
    {
        cout << "IPSELENTI";
    }
    
    return 0;
}

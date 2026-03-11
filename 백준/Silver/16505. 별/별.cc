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

int N;

vector<string> solution(int depth)
{
    vector<string> vs;
    
    if (depth == 0)
    {
        vs.push_back("*");
        return vs;
    }

    int leftWidth = pow(2, depth)/2;

    // 왼쪽
    
    vs = solution(depth-1);
    
    // 오른쪽
    vector<string> rightVec = solution(depth-1);
    
    for (int i=0; i<vs.size(); i++)
    {
        string left = vs[i];
        string right = rightVec[i];

        int leftSize = left.size();
        int paddingSize = leftWidth-leftSize;

        string padding;
        padding.resize(paddingSize, ' ');

        string row = left+padding+right;
        vs[i] = row;
    }

    // 아래
    vector<string> bottomVec = solution(depth-1);
    for (string str : bottomVec)
    {
        vs.push_back(str);
    }

    return vs;
}


int main()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

    cin >> N;

    vector<string> answer;
    answer = solution(N);

    for (string str : answer)
    {
        cout << str <<'\n';
    }
    
    return 0;
}

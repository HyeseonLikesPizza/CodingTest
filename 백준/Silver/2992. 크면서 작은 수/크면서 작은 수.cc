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

string answer; // 만든 숫자
string bestAnswer = "999999"; // 최솟값이어야 하는 숫자
string X; // 입력값
vector<char> nums; // 뽑은 숫자들.
vector<bool> visited; // 방문 저장 배열
bool hasAnswer = false;

void Choose(int depth)
{
    if (depth == nums.size())
    {
        if (answer > X)
        {
            bestAnswer = min(answer, bestAnswer);
            hasAnswer = true;
        }
        return;
    }

    for (int i=0; i<nums.size(); i++)
    {
        if (!visited[i])
        {
            answer += nums[i];
            visited[i] = true;

            Choose(depth+1);

            if (hasAnswer) return;

            answer.pop_back();
            visited[i] = false;
        }
    }
}


int main()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

    cin >> X;

    for (int i = 0; i < X.size(); i++)
    {
        nums.push_back(X[i]);
    }

    sort(nums.begin(), nums.end());
    visited.resize(X.size(), false);

    Choose(0);

    if (hasAnswer)
    {
        cout << bestAnswer;
    }
    else
    {
        cout << 0;
    }
    

    
    return 0;
}

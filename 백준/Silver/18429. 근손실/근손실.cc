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

vector<int> kits; // 키트들이 들어있는 배열
vector<bool> isVisited; // 각 키트들이 사용됐는지 체크하는 배열
vector<int> selected; // 선택한 수들을 담아두는 배열
int N, K;
int answer = 0;

void Solution(int weight)
{
    if (selected.size() >= N)
    {
        answer++;
    }

    // 재귀 넘길때 -K 하기!
    for (int i=0; i<kits.size(); i++)
    {
        if (isVisited[i]) continue;
        int newWeight = weight - K + kits[i];
        if (newWeight < 500) continue; 

        selected.push_back(kits[i]);
        isVisited[i] = true;

        Solution(newWeight);

        selected.pop_back();
        isVisited[i] = false;
    }
}


int main()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    
    cin >> N >> K;
    
    kits.resize(N);
    isVisited.resize(N);

    for (int i=0; i<N; i++)
    {
        cin >> kits[i];
    }

    sort(kits.begin(), kits.end());

    Solution(500);

    cout << answer;
    
    return 0;
}

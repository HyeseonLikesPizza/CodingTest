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

vector<int> vec;
int N;
int answer = -999;
vector<bool> isVisited;
vector<int> selected;

void solution()
{
    if (selected.size() == N)
    {
        int sum = 0;
        for (int i=0; i<N-1; i++)
        {
            sum += abs(selected[i] - selected[i+1]);
        }

        if (sum > answer) answer = sum;
        return;
    }

    for (int i=0; i<vec.size(); i++)
    {
        if (isVisited[i]) continue;

        isVisited[i] = true;
        selected.push_back(vec[i]);

        solution();

        isVisited[i] = false;
        selected.pop_back();
    }
}

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

    cin >> N;
    isVisited.resize(N, false);

    for (int i=0; i<N; i++)
    {
        int num;
        cin >> num;
        vec.push_back(num);
    }

    solution();
    cout << answer;
    
    return 0;
}

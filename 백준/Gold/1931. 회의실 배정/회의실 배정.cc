#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stack>
#include <climits>

using namespace std;

int main()
{
    int N, cnt=0;

    cin >> N;

    vector<pair<int, int>> vec(N);
    pair<int, int> current;

    for(int i=0; i<N; i++)
    {
        pair<int, int> p;
        cin >> p.first >> p.second;
        vec[i] = p;
    }

    
    sort(vec.begin(), vec.end(), [](const pair<int, int>& a, const pair<int, int>& b)
    {
        if (a.second == b.second) return a.first < b.first;
        return a.second < b.second;
    });
    
    current.first = vec[0].first;
    current.second = vec[0].second;
    cnt++;
    
    for(int i=1; i<N; i++)
    {
        if (current.second <= vec[i].first)
        {
            current = vec[i];
            cnt++;
        }
    }

    cout << cnt;
    
    return 0;
}
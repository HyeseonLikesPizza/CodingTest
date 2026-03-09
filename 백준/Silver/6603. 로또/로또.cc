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

vector<int> v;
vector<int> selected;

void solution(int startIdx)
{
    if (selected.size() == 6)
    {
        for (int i=0; i<6; i++)
        {
            cout << selected[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i=startIdx; i<v.size(); i++)
    {
        selected.push_back(v[i]);
        solution(i+1);
        selected.pop_back();
    }
}


int main()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

    int k;
    
    while (1)
    {
        cin >> k;

        if (k==0) break;
        v.assign(k, 0);
        
        for (int i=0; i<k; i++)
        {
            int num;
            cin >> num;
            v[i] = num;
        }

        sort(v.begin(), v.end());

        solution(0);
        cout << '\n';

        selected.clear();
        
    }
    
    return 0;
}

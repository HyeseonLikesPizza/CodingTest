#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <string>
#include <sstream>
#include <queue>

using namespace std;

int N, M;
vector<int> picked;

void backtracking(int start)
{
    if (picked.size() == M)
    {
        for(int i=0; i<M; i++)
            cout << picked[i] << " ";
        cout << '\n';
        return;
    }

    for(int i=start; i<=N; i++)
    {
        picked.push_back(i);

        backtracking(i);

        picked.pop_back();
    }
}

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> N >> M;

    backtracking(1);


    return 0;
}
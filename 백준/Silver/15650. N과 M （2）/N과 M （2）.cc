#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stack>
#include <climits>

using namespace std;

int N, M;
vector<bool> used;
vector<int> picked;


void backtracking(int start)
{
    if (picked.size()==M)
    {
        for(int i=0; i<M; i++)
        {
            cout << picked[i] << " ";
        }
        cout << "\n";
        return;
    }

    for(int i=start; i<=N; i++)
    {
        if (used[i]==true) continue;

        used[i] = true;
        picked.push_back(i);

        backtracking(i);

        used[i] = false;
        picked.pop_back();
    }

}

int main()
{
    cin >> N>> M;

    used.assign(N+1,false);
    picked.clear();

    backtracking(1);
    
    return 0;
}
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


void backtracking()
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

    for(int i=1; i<=N; i++)
    {
        picked.push_back(i);

        backtracking();

        picked.pop_back();
    }

}

int main()
{
    cin >> N>> M;

    //used.assign(N+1,false);
    picked.clear();

    backtracking();
    
    return 0;
}
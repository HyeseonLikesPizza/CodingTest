#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stack>
#include <climits>

using namespace std;

int N, minNum=INT_MAX, maxNum=INT_MIN;
vector<int> vec;
vector<int> op;

void backtracking(int idx, int currentSum)
{
    if (idx == N)
    {
        minNum = min(minNum, currentSum);
        maxNum = max(maxNum, currentSum);
        return;
    }

    for(int i=0; i<op.size(); i++)
    {
        if (op[i]<=0) continue;

        op[i]--;

        int sum = currentSum;
        switch(i)
        {
            case 0:
                sum += vec[idx];
                break;
            case 1:
                sum -= vec[idx];
                break;
            case 2:
                sum *= vec[idx];
                break;
            case 3:
                sum /= vec[idx];
                break;
        }

        backtracking(idx+1, sum);

        op[i]++;
    }
}

int main()
{
    cin >> N;

    vec.resize(N);
    op.resize(4);

    for(int i=0; i<N; i++)
    {
        cin >> vec[i];
    }

    cin >> op[0] >> op[1] >> op[2] >> op[3];

    backtracking(1, vec[0]);

    cout << maxNum << '\n';
    cout << minNum;


    return 0;
}
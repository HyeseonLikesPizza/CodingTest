#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stack>
#include <climits>

using namespace std;

int main()
{
    int N;

    cin >> N;

    vector<int> ArrX(N);
    vector<int> ArrY(N);

    vector<int> SortedX(N);
    vector<int> SortedY(N);

    for(int i=0; i<N; i++)
    {
        cin >> ArrX[i] >> ArrY[i];
    }

    SortedX = ArrX;
    SortedY = ArrY;

    sort(SortedX.begin(), SortedX.end());
    sort(SortedY.begin(), SortedY.end());

    int a = SortedX[N/2];
    int b = SortedY[N/2];
    long long answer = 0;

    for(int i=0; i<N; i++)
    {
        answer += abs(ArrX[i]-a) + abs(ArrY[i]-b);
    }

    cout << answer;

    
    return 0;
}
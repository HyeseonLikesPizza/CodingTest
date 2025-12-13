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
    
    vector<long long> roads(N-1);  // 도로 길이
    vector<long long> prices(N);   // 주유 가격
    
    // 도로 길이 입력
    for(int i = 0; i < N-1; i++)
        cin >> roads[i];
    
    // 주유 가격 입력
    for(int i = 0; i < N; i++)
        cin >> prices[i];
    
    long long minPrices = INT_MAX;
    long long totalCost = 0;

    for(int i=0; i<N-1; i++)
    {
        if (prices[i] < minPrices)
        {
            minPrices = prices[i];
        }

        totalCost += minPrices * roads[i];
    }

    cout << totalCost;
    
    return 0;
}